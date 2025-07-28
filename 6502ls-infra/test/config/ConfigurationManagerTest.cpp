#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

#include "../../src/Config/ConfigurationManager.h"

using namespace ls6502;

class ConfigurationManagerTest : public ::testing::Test
{
  protected:
    void SetUp() override { configManager = ConfigurationManager::getInstance(); }

    ConfigurationManager *configManager;
};

TEST_F(ConfigurationManagerTest, WillReturnEmptyPropertyForNonExistentKey)
{
    // GIVEN
    std::string propertyName = "nonexistent_property";

    // WHEN
    std::string propertyValue = configManager->getProperty(propertyName);

    // THEN
    EXPECT_EQ(propertyValue, "");
}

TEST_F(ConfigurationManagerTest, WillLoadValidConfigurationFile)
{
    // GIVEN
    std::ifstream mockFile("<property name=\"validKey\">validValue</property>\n"
                           "<property name=\"anotherKey\">anotherValue</property>\n");

    // WHEN
    configManager->load(mockFile);

    // THEN
    EXPECT_EQ(configManager->getProperty("validKey"), "validValue");
    EXPECT_EQ(configManager->getProperty("anotherKey"), "anotherValue");
}

TEST_F(ConfigurationManagerTest, WillIgnoreInvalidXMLLines)
{
    // GIVEN
    std::ifstream mockFile("<invalid>some invalid data</invalid>\n"
                           "<property name=\"validKey\">validValue</property>\n");

    // WHEN
    configManager->load(mockFile);

    // THEN
    EXPECT_EQ(configManager->getProperty("validKey"), "validValue");
    EXPECT_EQ(configManager->getProperty("invalid"), "");
}

TEST_F(ConfigurationManagerTest, WillWarnOnEmptyProperties)
{
    // GIVEN
    std::ifstream mockFile("<property name=\"emptyKey\"></property>\n");

    // WHEN
    configManager->load(mockFile);

    // THEN
    EXPECT_EQ(configManager->getProperty("emptyKey"), "");
}

TEST_F(ConfigurationManagerTest, WillReturnSameInstance)
{
    // WHEN
    ConfigurationManager *instance1 = ConfigurationManager::getInstance();
    ConfigurationManager *instance2 = ConfigurationManager::getInstance();

    // THEN
    EXPECT_EQ(instance1, instance2);
}
