#pragma once

#include <memory>
#include <string>

#include "../Config/ConfigurationManager.h"
#include "FakeHoverProvider.h"
#include "IHoverProvider.h"
#include "InstructionSet6502HoverProvider.h"

namespace ls6502
{
class HoverProviderFactory
{
  public:
    HoverProviderFactory() = delete;

    static std::shared_ptr<IHoverProvider> create()
    {
        std::string hoverProvider = ConfigurationManager::getInstance()->getProperty("hoverProvider");

        if (hoverProvider == "fake")
        {
            return std::make_shared<FakeHoverProvider>();
        }

        return std::make_shared<InstructionSet6502HoverProvider>();
    }
};
} // namespace ls6502
