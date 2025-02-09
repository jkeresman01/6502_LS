#pragma once

#include <cstdint>
#include <iomanip>
#include <sstream>

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @struct ClientInfo
///
/// @brief Stores the information about the client (editor)
///
//////////////////////////////////////////////////////////////
struct TextDocumentSyncClientCapabilities
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Whether text document synchronization supports
    ///         dynamic registration.
    ///
    //////////////////////////////////////////////////////////////
    bool isDynamicRegistrationSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Whether the client supports sending will
    ///         save notifications.
    ///
    //////////////////////////////////////////////////////////////
    bool isWillSaveSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  The client supports sending a will save request and
    ///         waits for a response providing text edits which will
    ///         be applied to the document before it is saved.
    ///         save notifications.
    ///
    //////////////////////////////////////////////////////////////
    bool isWillSaveUntilSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Whether The client supports did save notifications.
    ///
    //////////////////////////////////////////////////////////////
    bool isDidSaveSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief String representation of Clients sync capabilities
    ///
    /// @return String representation of Clients sync capabilites
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const
    {
        int8_t optionWidth = 30;
        int8_t resultWidth = 20;

        std::stringstream ss;

        ss << std::setw(optionWidth) << std::left << "Sync option";
        ss << std::setw(resultWidth) << std::left << "Yes/No" << std::endl;
        ss << std::string(optionWidth + resultWidth, '-') << std::endl;

        ss << std::setw(optionWidth) << std::left << "Dynamic Registration";
        ss << std::setw(resultWidth) << std::left << (isDynamicRegistrationSupported ? "Yes" : "No")
           << std::endl;

        ss << std::setw(optionWidth) << std::left << "Will Save Supported";
        ss << std::setw(resultWidth) << std::left << (isWillSaveSupported ? "Yes" : "No") << std::endl;

        ss << std::setw(optionWidth) << std::left << "Will Save Until Supported";
        ss << std::setw(resultWidth) << std::left << (isWillSaveUntilSupported ? "Yes" : "No") << std::endl;

        ss << std::setw(optionWidth) << std::left << "Did Save Supported";
        ss << std::setw(resultWidth) << std::left << (isDidSaveSupported ? "Yes" : "No") << std::endl;

        return ss.str();
    }
};
} // namespace justanlsp
