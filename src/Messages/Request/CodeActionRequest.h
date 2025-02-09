#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../../Params/CodeActionParams.h"
#include "RequestMessage.h"

namespace justanlsp
{
class CodeActionRequest : public RequestMessage
{
  public:
    explicit CodeActionRequest(const nlohmann::json &jsonRPC);

    std::shared_ptr<CodeActionParams> getParams() const { return m_codeActionParams; };

  private:
    void setParams(const nlohmann::json &jsonRPC);

  private:
    std::shared_ptr<CodeActionParams> m_codeActionParams;
};
} // namespace justanlsp
