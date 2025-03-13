#pragma once

#include "IDefinitionProvider.h"

namespace ls6502
{
class FakeDefinitionProvider : public IDefinitionProvider
{
  public:
    virtual Location provideDefinitionLocation(const std::string &document, const Position &position,
                                                const std::string &URI) override;
};
} // namespace ls6502
