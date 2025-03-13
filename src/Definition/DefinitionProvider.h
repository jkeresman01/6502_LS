#pragma once

#include "../Types/Location.h"
#include "IDefinitionProvider.h"

namespace ls6502
{
class DefinitionProvider : public IDefinitionProvider
{
  public:
    virtual Location provideDefinitionLocation(const std::string &document, const Position &position,
                                               const std::string &URI) override;
};
} // namespace ls6502
