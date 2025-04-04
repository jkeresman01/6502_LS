////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "DefinitionProvider.h"

#include "../../Utils/DefinitionUtil.h"
#include "../../Utils/DocumentUtil.h"
#include "../../Utils/Logger.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
Location DefinitionProvider::provideDefinitionLocation(const std::string& document,
                                                       const Position&    position,
                                                       const std::string& URI)
{
    // TODO extract word under the cursor not prefix
    const std::string& label = DocumentUtil::extractPrefix(document, position);

    LS_6502_DEBUG(STR("Label: %s", label.c_str()));

    if (label.empty())
    {
        LS_6502_DEBUG("Empty label, returning current position");
        return Location{URI, Range{position, position}};
    }

    const Position& definitionPosition = DefinitionUtil::findLabelPosition(label, document);

    uint32_t lineNumber        = definitionPosition.line;
    uint32_t characterPosition = definitionPosition.character + label.length();

    Range range{definitionPosition, {lineNumber, characterPosition}};

    return Location{URI, range};
}

} // namespace ls6502
