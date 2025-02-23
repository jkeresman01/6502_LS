#pragma once

#include "IDiagnosticsAnalyzer.h"
#include "IncorrectLabelDiagnosticsAnalyzer.h"
#include "UnsupportedInstructionDiagnosticsAnalyzer.h"
#include "WrongInstructionUsageDiagnosticsAnalyzer.h"

#include "../Types/Diagnostic.h"
#include "../Utils/DiagnosticsUtil.h"
#include "../Utils/Logger.h"

#include <memory>

namespace ls6502
{
class DiagnosticsAnalyzerFactory
{
  public:
    static std::shared_ptr<IDiagnosticsAnalyzer> getInstance(const Diagnostic &diagnostic)
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
