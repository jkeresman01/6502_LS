#include "ConfigurationManager.h"

#include "../Utils/Logger.h"
#include "../Utils/XMLUtil.h"

#include <fstream>
#include <mutex>
#include <string>

namespace ls6502
{

ConfigurationManager *ConfigurationManager::s_instance = nullptr;
std::mutex ConfigurationManager::s_mutex;

void ConfigurationManager::load()
{
    m_properties.clear();

    std::ifstream configFile(XML_CONFIGURATION_PATH);

    if (!configFile.is_open())
    {
        LS_6502_ERROR(STR("No can do for config file: %s", XML_CONFIGURATION_PATH));
        return;
    }

    load(configFile);

    configFile.close();
}

void ConfigurationManager::load(std::ifstream &in)
{
    std::string line;

    while (getline(in, line))
    {
        if (XMLUtil::isValidXMLLine(line))
        {
            readPropertyFromFileLine(line);
        }
    }
}

void ConfigurationManager::readPropertyFromFileLine(const std::string &line)
{
    std::pair<std::string, std::string> property = XMLUtil::parseFromFileLine(line);

    bool isValidProperty = property.first != "" and property.second != "";

    if (!isValidProperty)
    {
        LS_6502_WARN(STR("Found empty property: [\"%s\"] : [\"%s\"]", property.first.c_str(),
                         property.second.c_str()));
        return;
    }

    m_properties.insert(property);
}

std::string ConfigurationManager::getProperty(const std::string &propertyName)
{
    auto it = m_properties.find(propertyName);

    if (it == m_properties.end())
    {
        LS_6502_ERROR(STR("No can do for property: %s", propertyName.c_str()));
        return std::string();
    }

    return it->second;
}

ConfigurationManager::~ConfigurationManager()
{
    if (s_instance)
    {
        delete s_instance;
    }
}

ConfigurationManager *ConfigurationManager::getInstance()
{
    std::lock_guard<std::mutex> lock(s_mutex);

    if (!s_instance)
    {
        s_instance = new ConfigurationManager;
    }

    return s_instance;
}
} // namespace ls6502
