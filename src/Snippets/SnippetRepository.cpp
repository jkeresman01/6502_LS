////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "SnippetRepository.h"

#include <nlohmann/json.hpp>

#include "../Utils/Logger.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
SnippetsMultimapT SnippetRepository::load()
{
    std::ifstream snippetsFile(PREDEFINED_SNIPPETS_PATH);

    if (!snippetsFile.is_open())
    {
        LS_6502_ERROR(STR("No can do for %s", PREDEFINED_SNIPPETS_PATH));
        return {};
    }

    load(snippetsFile);
    snippetsFile.close();

    return m_snippets;
}


////////////////////////////////////////////////////////////
void SnippetRepository::load(std::ifstream &snippetsFile)
{
    nlohmann::json snippetsJson;
    snippetsFile >> snippetsJson;

    for (auto &[mnemonic, snippets] : snippetsJson.items())
    {
        for (const auto &snippet : snippets)
        {
            m_snippets.emplace(mnemonic, snippet);
        }
    }
}
} // namespace ls6502
