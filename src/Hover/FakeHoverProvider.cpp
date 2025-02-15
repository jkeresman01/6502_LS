#include "FakeHoverProvider.h"

namespace ls6502
{
HoverItem FakeHoverProvider::getHoverItem(const std::string &document, const Position &position)
{
    HoverItem fakeHoverItem;
    fakeHoverItem.text = "6502 ASM langauge server";
    return fakeHoverItem;
}
} // namespace ls6502
