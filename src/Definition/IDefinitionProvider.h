#pragma once

#include "../Types/Location.h"
#include "../Types/Position.h"

namespace ls6502
{
class IDefinitionProvider
{
  public:
    virtual Location provideDefinitionLocation(const std::string &document, const Position &position,
                                                const std::string &URI) = 0;
};
} // namespace ls6502
