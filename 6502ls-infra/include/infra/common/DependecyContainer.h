#pragma once

#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "../Logger/Logger.h"
#include "Lifetime.h"
#include "Registration/IRegistration.h"

namespace ls6502
{

typedef std::unordered_map<std::type_index, std::shared_ptr<IRegistration>> RegistrationsMapT;

class DependencyContainer
{
public:
    template <typename T>
    void registerFactory(std::function<std::shared_ptr<T>()> creator, Lifetime lifetime = Lifetime::TRANSIENT)
    {
        std::shared_ptr<IRegistration> registration = std::make_shared<Registration<T>>(creator, lifetime);

        m_registrations[std::type_index(typeid(T))] = registration;
    }

    template <typename T>
    std::shared_ptr<T> get()
    {
        RegistrationsMapT::iterator it = m_registrations.find(std::type_index(typeid(T)));

        if (it == m_registrations.end())
        {
            LS_6502_ERROR("No registration for given type");
        }

        auto registration = std::static_pointer_cast<Registration<T>>(it->second);

        return registration->get();
    }

private:
    RegistrationsMapT m_registrations;
};
} // namespace ls6502
