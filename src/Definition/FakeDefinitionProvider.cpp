////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "FakeDefinitionProvider.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
Location FakeDefinitionProvider::provideDefinitionLocation(const std::string &document,
                                                           const Position &position, const std::string &URI)
{
    Range range{{10, 10}, {10, 12}};
    return Location{URI, range};
}
} // namespace ls6502
