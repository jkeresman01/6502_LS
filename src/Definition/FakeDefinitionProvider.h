#pragma once

#include "IDefinitionProvider.h"

namespace ls6502
{
class FakeDefinitionProvider : public IDefinitionProvider
{
  public:
    virtual Location providerDefinitionLocation(const std::string &document, const Position &position,
                                     const std::string &URI) override;
};
} // namespace ls6502
