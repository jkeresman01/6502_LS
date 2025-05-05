#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <any>
#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <typeindex>
#include <unordered_map>

#include "RegisterClass.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// Typedefs
///
//////////////////////////////////////////////////////////////
typedef std::unordered_map<std::type_index, std::unordered_map<std::string, std::function<std::any()>>> RegistriesT;

//////////////////////////////////////////////////////////////
///
/// @class ClassRegistry
///
//////////////////////////////////////////////////////////////
class ClassRegistry
{
public:
    static ClassRegistry& getInstance()
    {
        static ClassRegistry instance;
        return instance;
    }

    template <typename T>
    void registerClass(const std::string& name, std::function<std::shared_ptr<T>()> factory)
    {
        std::type_index typeId     = std::type_index(typeid(T));
        m_registries[typeId][name] = [factory]() -> std::any { return std::any(factory()); };
    }

    template <typename T>
    class TypeFactory
    {
    public:
        explicit TypeFactory(const std::string& name) : m_factoryName(name)
        {
        }

        std::shared_ptr<T> newInstance() const
        {
            auto&           registry = ClassRegistry::getInstance().m_registries;
            std::type_index typeId   = std::type_index(typeid(T));

            auto typeIt = registry.find(typeId);

            if (typeIt == registry.end())
            {
                LS_6502_ERROR("No registry for type");
            }

            auto factoryIt = typeIt->second.find(m_factoryName);

            if (factoryIt == typeIt->second.end())
            {
                LS_6502_ERROR(STR("Class not registered: %s", m_factoryName.c_str());
            }

            std::any instance = factoryIt->second();
            return std::any_cast<std::shared_ptr<T>>(instance);
        }

    private:
        std::string m_factoryName;
    };

    template <typename T>
    TypeFactory<T> forName(const std::string& name)
    {
        return TypeFactory<T>(name);
    }

private:
    RegistriesT m_registries;

    ClassRegistry()                                = default;
    ClassRegistry(const ClassRegistry&)            = delete;
    ClassRegistry& operator=(const ClassRegistry&) = delete;
};

} // namespace ls6502
