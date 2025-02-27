#pragma once

#include "TextEdit.h"

#include <nlohmann/json.hpp>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// Typedefs
///
//////////////////////////////////////////////////////////////
typedef std::unordered_map<std::string, std::vector<TextEdit>> ChangesT;

class WorkspaceEdit
{
  public:
    WorkspaceEdit() = default;

    void addChange(const std::pair<std::string, std::vector<TextEdit>> &textEdit);

    nlohmann::json toJson() const;

    std::string toString() const;

  private:
    ChangesT m_changes;
};
} // namespace ls6502
