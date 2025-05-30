#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <string>
#include <unordered_map>

#include "../ISnippetRepository.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// Typedefs
///
//////////////////////////////////////////////////////////////
typedef std::unordered_multimap<std::string, std::string> SnippetsMultimapT;

//////////////////////////////////////////////////////////////
///
/// @class SnippetRepository
///
/// @brief repository for 6502 snippets
///
//////////////////////////////////////////////////////////////
class SnippetRepository : public ISnippetRepository
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Loads predefined snippets for 6502 ASM
    ///
    //////////////////////////////////////////////////////////////
    SnippetsMultimapT load() override;

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Loads predefined snippets for 6502 ASM
    ///        from provided input stream
    ///
    /// @param [in] snippetsFile
    ///
    //////////////////////////////////////////////////////////////
    void load(std::ifstream& snippetsFile);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Path to the predefined 6502 ASM snippets
    ///
    //////////////////////////////////////////////////////////////
    const char* PREDEFINED_SNIPPETS_PATH = "../../snippets/snippets.json";

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Predefined snippets for 6052 ASM
    ///
    //////////////////////////////////////////////////////////////
    SnippetsMultimapT m_snippets;
};
} // namespace ls6502
