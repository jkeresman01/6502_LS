#pragma once

#include <nlohmann/json.hpp>
#include <string>

namespace ls6052
{
//////////////////////////////////////////////////////////////
///
/// @class HoverResult
///
/// @brief Represents the result of a hover request in a
///        Ls6502 language server.
///
//////////////////////////////////////////////////////////////
class HoverResult
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a HoverResult with the given value.
    ///
    /// @param value The string value to be displayed in the hover result.
    ///
    //////////////////////////////////////////////////////////////
    HoverResult(const std::string &value) : m_value(value){};

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the HoverResult object into a JSON representation.
    ///
    /// @return A nlohmann::json object containing the hover result
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const { return {{"result", m_value}}; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The string value that will be displayed in the hover result.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_value;
};

} // namespace ls6052
