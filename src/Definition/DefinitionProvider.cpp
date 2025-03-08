#pragma once

#include "DefinitionProvider.h"
#include "../Utils/DocumentUtil.h"

namespace ls6502
{
    Location DefinitionProvider::providerDefinitionLocation(const std::string &document, const Position &position,
                                                const std::string &URI)
    {
        std::string label = DocumentUtil::extractPrefix(document, position);

        // TODO extract range from label implementaion or reutrn current local 
        Range range; 

        return Location{URI, range};
    }
}

   
