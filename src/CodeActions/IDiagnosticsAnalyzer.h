#pragma once

#include "../Types/CodeAction.h"
#include "../Types/Diagnostic.h"

#include <string>
#include <vector>

namespace ls6502
{

class IDiagnosticsAnalyzer
{
  public:
    virtual std::vector<CodeAction> provideCodeActions(const Diagnostic &diagnostic,
                                                       const std::string &document,
                                                       const std::string &URI) = 0;
};
} // namespace ls6502
