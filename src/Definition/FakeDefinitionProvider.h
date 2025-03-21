#pragma once

#include "IDefinitionProvider.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class FakeDefinitionProvider
///
/// @brief A mock implementation of IDefinitionProvider
///         for testing or demonstration purposes.
///
//////////////////////////////////////////////////////////////
class FakeDefinitionProvider : public IDefinitionProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Provides a fake location of a definition
    ///
    /// @param [in] document
    /// @param [in] position
    /// @param [in] URI
    ///
    /// @return A fake location of the definition
    ///
    //////////////////////////////////////////////////////////////
    virtual Location provideDefinitionLocation(const std::string &document, const Position &position,
                                               const std::string &URI) override;
};
} // namespace ls6502
