#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../../Results/HoverResult.h"
#include "ResponseMessage.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class HoverResponse
///
/// @brief Represents a response message for a hover request.
///
//////////////////////////////////////////////////////////////
class HoverResponse : public ResponseMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a HoverResponse with given parameters.
    ///
    /// @param jsonRPC
    /// @param id
    /// @param hoverResult
    ///
    //////////////////////////////////////////////////////////////
    HoverResponse(const std::string &jsonRPC, const int64_t id, const HoverResult &hoverResult);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the HoverResponse to a JSON representation.
    ///
    /// @return A JSON object representing the HoverResponse.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Overloads the output stream operator for HoverResponse.
    ///
    /// @param os
    /// @param codeActionResponse
    ///
    /// @return The modified output stream.
    ///
    //////////////////////////////////////////////////////////////
    friend std::ostream &operator<<(std::ostream &os, const HoverResponse &hoverResponse);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The hover result associated with this response.
    ///
    //////////////////////////////////////////////////////////////
    HoverResult m_hoverResult;
};

} // namespace justanlsp
