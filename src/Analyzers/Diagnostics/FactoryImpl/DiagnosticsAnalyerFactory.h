#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>

#include "../DiagnosticsAnalyerImpl/IncorrectLabelDiagnosticsAnalyzer.h"
#include "../DiagnosticsAnalyerImpl/UnsupportedInstructionDiagnosticsAnalyzer.h"
#include "../DiagnosticsAnalyerImpl/WrongInstructionUsageDiagnosticsAnalyzer.h"
#include "../IDiagnosticsAnalyzer.h"
#include "../Types/Diagnostic.h"
#include "../Utils/DiagnosticsUtil.h"
#include "../Utils/Logger.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class DiagnosticsAnalyzerFactory
///
/// @brief Factory class for creating instances of
///        diagnostic analyzers based on the type of
///        diagnostic provided.
///
//////////////////////////////////////////////////////////////
class DiagnosticsAnalyzerFactory
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of the appropriate
    ///        diagnostics analyzer based on the given diagnostic.
    ///
    /// @param [in] diagnostic
    ///
    /// @return A shared pointer to an IDiagnosticsAnalyzer instance
    ///         corresponding to the diagnostic type.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<IDiagnosticsAnalyzer> getInstance(const Diagnostic& diagnostic)
    {
        if (DiagnosticsUtil::isLabelMissingSemicolon(diagnostic))
        {
            return std::make_shared<IncorrectLabelDiagnosticsAnalyzer>();
        }

        if (DiagnosticsUtil::isInstructionUnsupproted(diagnostic))
        {
            return std::make_shared<UnsupportedInstructionDiagnosticsAnalyzer>();
        }

        return std::make_shared<WrongInstructionUsageDiagnosticsAnalyzer>();
    }
};

} // namespace ls6502
