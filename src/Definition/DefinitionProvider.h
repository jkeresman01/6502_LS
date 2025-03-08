#pragma once

#include "IDefinitionProvider.h"
#include "../Types/Location.h"

namespace ls6502
{
    class DefinitionProvider : public IDefinitionProvider
    {
        public:
            virtual Location providerDefinitionLocation(const std::string &document, const Position &position,
                                                const std::string &URI) override; 
    };
}

   
