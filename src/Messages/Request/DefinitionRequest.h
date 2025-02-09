#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../../Params/DefintionParams.h"
#include "RequestMessage.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class DefintionRequest
///
/// @brief The definition request is sent from the client to the
///        server to request hover information at a given
///        text document position.
///
//////////////////////////////////////////////////////////////
class DefintionRequest : public RequestMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Defintion request from JSON RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit DefintionRequest(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for DefintionParams
    ///
    /// @return DefintionParams
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<DefinitionParams> getParams() const { return m_hoverParams; };

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
    /// @brief Paramters used in Defintion Request
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<DefinitionParams> m_hoverParams;
};
} // namespace justanlsp
