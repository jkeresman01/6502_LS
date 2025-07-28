////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "FakeHoverProvider.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
HoverItem FakeHoverProvider::getHoverItem(const std::string& document, const Position& position)
{
    (void)document;
    (void)position;

    return HoverItem{"6502 ASM langauge server"};
}


} // namespace ls6502
