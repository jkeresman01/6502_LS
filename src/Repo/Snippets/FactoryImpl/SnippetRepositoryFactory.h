#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>

#include "../ISnippetRepository.h"
#include "../JsonRepositoryImpl/JsonSnippetRepository.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class SnippetRepositoryFactory
///
/// @brief Factory class for creating instances
///        of ISnippetRepository.
///
/// @note This factory ensures that SnippetRepository
///       instances are created in a standardized way,
///       allowing for easy dependency injection and
///       future extension.
///
//////////////////////////////////////////////////////////////
class SnippetRepositoryFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    SnippetRepositoryFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of ISnippetRepository.
    ///
    /// @return A shared pointer to a newly created
    ///         SnippetRepository instance.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ISnippetRepository> create() { return std::make_shared<SnippetRepository>(); }
};
} // namespace ls6502
