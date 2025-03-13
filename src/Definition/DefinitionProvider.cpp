#include "DefinitionProvider.h"
#include "../Utils/DocumentUtil.h"
#include "../Utils/Logger.h"

namespace ls6502
{
Location DefinitionProvider::provideDefinitionLocation(const std::string &document, const Position &position,
                                                        const std::string &URI)
{
    const std::string &label = DocumentUtil::extractPrefix(document, position);

    LS_6502_DEBUG(STR("Label: %s", label.c_str()));

    // TODO extract range from label implementaion or reutrn current local
    Range range;

    LS_6502_DEBUG(STR("Document: %s", document.c_str()));

    return Location{URI, range};
}
} // namespace ls6502
