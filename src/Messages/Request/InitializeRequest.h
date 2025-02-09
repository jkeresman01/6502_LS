#pragma once

#include <memory>

#include "../Params/InitializeParams.h"
#include "RequestMessage.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class InitializeRequest
///
/// @brief The initialize request is sent as the first request
///        from the client to the server.
///
//////////////////////////////////////////////////////////////
class InitializeRequest : public RequestMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Initialize request from JSON RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit InitializeRequest(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for InitalizeParams
    ///
    /// @return InitializeParams
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<InitializeParams> getInitializeParams() const { return m_initializeParams; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for initialize params
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setInitializeParams(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Paramters used in Initalize Request
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<InitializeParams> m_initializeParams;
};
} // namespace justanlsp
