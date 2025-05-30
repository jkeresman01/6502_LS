#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <nlohmann/json.hpp>

#include "HoverClientCapabilities.h"
#include "TextDocumentSyncClientCapabilites.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class TextDocumentCapabilities
///
/// @brief TextDocumentClientCapabilities define capabilities
///        the editor / tool provides on text documents.
///
//////////////////////////////////////////////////////////////
class TextDocumentCapabilities
{
    // TODO add rest of the capabilities only sync and hover are
    // currently included

public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the TextDocumentCapabilities from jsonRPC request
    ///
    /// @param [in] jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit TextDocumentCapabilities(const nlohmann::json& jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for text docuemnt sync capabilities
    ///
    /// @param [in] synchronization capabilites
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentSyncClientCapabilities getTextDocumentSyncCapabilites() const
    {
        return m_synchronization;
    };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for text docuemnt hover capabilities
    ///
    /// @param [in] hover capabilites
    ///
    //////////////////////////////////////////////////////////////
    HoverClientCapabilities getHoverCapabilities() const
    {
        return m_hover;
    };

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Capabilities specific to the textDocument syncrhonization
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentSyncClientCapabilities m_synchronization;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Capabilities specific to the `textDocument/hover` request.
    ///
    //////////////////////////////////////////////////////////////
    HoverClientCapabilities m_hover;
};
} // namespace ls6502
