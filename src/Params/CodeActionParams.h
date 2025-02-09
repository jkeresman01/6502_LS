#pragma once

#include <string>

#include "../Types/Range.h"

namespace justanlsp
{
class CodeActionParams
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the CodeActionParams object from JSON RPC
    ///
    /// @param jsonRPC JSON object containing code action parameters
    ///
    //////////////////////////////////////////////////////////////
    explicit CodeActionParams(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for the range in which the code
    ///        action is requested
    ///
    /// @return Range of the requested code action
    ///
    //////////////////////////////////////////////////////////////
    Range getRange() const { return m_range; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for the URI of the text document
    ///        on which the code action is requested
    ///
    /// @return URI of the text document
    ///
    //////////////////////////////////////////////////////////////
    std::string getURI() const { return m_URI; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for setting the range from JSON RPC
    ///
    /// @param jsonRPC JSON object containing range details
    ///
    //////////////////////////////////////////////////////////////
    void setRange(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for setting the start position
    ///        of the range from JSON RPC
    ///
    /// @param jsonRPC JSON object containing start position details
    ///
    //////////////////////////////////////////////////////////////
    void setStartPosition(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for setting the end position
    ///        of the range from JSON RPC
    ///
    /// @param jsonRPC JSON object containing end position details
    ///
    //////////////////////////////////////////////////////////////
    void setEndPosition(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for setting the text document URI
    ///        from JSON RPC
    ///
    /// @param jsonRPC JSON object containing the document URI
    ///
    //////////////////////////////////////////////////////////////
    void setURI(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Range within which the code action is requested
    ///
    //////////////////////////////////////////////////////////////
    Range m_range;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief URI of the text document on which the code action
    ///        is requested
    ///
    //////////////////////////////////////////////////////////////
    std::string m_URI;
};

} // namespace justanlsp
