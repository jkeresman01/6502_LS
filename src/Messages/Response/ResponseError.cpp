#include "ResponseError.h"

#include <sstream>

namespace justanlsp
{

ResponseError::ResponseError(const ErrorCodes &errorCode, const std::string &message)
    : m_errorCode(errorCode), m_message(message)
{
}

nlohmann::json ResponseError::toJson() const
{
    return {{"code", static_cast<int>(m_errorCode)}, {"message", m_message}};
}

std::string ResponseError::toString() const
{
    std::stringstream ss;

    ss << "Error code { " << std::to_string(static_cast<uint32_t>(m_errorCode)) << " }, ";
    ss << "Error msg { " << m_message << " }, ";

    return ss.str();
}

ResponseError::Builder &ResponseError::Builder::withErrorCode(const ErrorCodes &errorCode)
{
    m_errorCode = errorCode;
    return *this;
}

ResponseError::Builder &ResponseError::Builder::withErrorMessage(const std::string &message)
{
    m_message = message;
    return *this;
}

ResponseError ResponseError::Builder::build() const
{
    return ResponseError(m_errorCode, m_message);
}

} // namespace justanlsp
