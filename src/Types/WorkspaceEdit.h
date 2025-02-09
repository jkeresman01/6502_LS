#pragma once

#include "TextEdit.h"

#include <nlohmann/json.hpp>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace justanlsp
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

    void addChage(const std::pair<std::string, std::vector<TextEdit>> &textEdit);

    nlohmann::json toJson() const;

    std::string toString() const;

  private:
    ChangesT m_changes;
};
} // namespace justanlsp
