#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <string>

#include "../Enums/TraceValue.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class TraceUtil
///
/// @brief Utility class for trace related stuff
///
/////////////////////////////////////////////////////////////////////
class TraceUtil
{
public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    TraceUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Converts string trace value to enum representation
    ///
    /// @param [in] traceValueStr
    ///
    /////////////////////////////////////////////////////////////////////
    static TraceValue getTraceValue(const std::string& traceValueStr);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
inline TraceValue getTraceValue(const std::string& traceValueStr)
{
    if (traceValueStr == "messages")
    {
        return TraceValue::MESSAGES;
    }

    if (traceValueStr == "verbose")
    {
        return TraceValue::VERBOSE;
    }

    return TraceValue::OFF;
}


} // namespace ls6502
