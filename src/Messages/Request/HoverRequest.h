#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../../Params/HoverParams.h"
#include "RequestMessage.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class HoverRequest
///
/// @brief The hover request is sent from the client to the
///        server to request hover information at a given
///        text document position.
///
//////////////////////////////////////////////////////////////
class HoverRequest : public RequestMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Hover request from JSON RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit HoverRequest(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for HoverParams
    ///
    /// @return HoverParams
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<HoverParams> getParams() const { return m_hoverParams; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for hover params
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setParams(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Paramters used in Hover Request
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<HoverParams> m_hoverParams;
};
} // namespace justanlsp
