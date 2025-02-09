#pragma once

#include <memory>

#include "IInstructionSetRepository.h"
#include "JSONInstructionSetRepository.h"

namespace ls6502
{
class IInstructionSetRepoFactory
{
  public:
    IInstructionSetRepoFactory() = delete;

    static std::shared_ptr<IInstructionSetRepository> create()
    {
        return std::make_shared<JSONInstructionSetRepository>();
    }
};
} // namespace ls6502
