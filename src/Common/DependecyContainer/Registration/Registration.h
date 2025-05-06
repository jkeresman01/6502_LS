#pragma once

namespace ls6502
{

template <typename T>
class Registration : public IRegistration
{
public:
    using FactoryFunction = std::function<std::shared_ptr<T>()>;

    Registration(FactoryFunction factoryFunction, Lifetime lifetime) :
    m_factory(factoryFunction),
    m_lifetime(lifetime)
    {
    }

    std::shared_ptr<T> get()
    {
        if (m_lifetime == Lifetime::SINGLETON)
        {
            if (!m_instance)
            {
                m_instance = m_factory();
            }

            return m_instance;
        }

        return m_factory();
    }

private:
    FactoryFunction m_factory;
    Lifetime        m_lifetime;

    std::shared_ptr<T> m_instance;
};
} // namespace ls6502
