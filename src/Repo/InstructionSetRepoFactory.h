#pragma once

#include <memory>

#include "IInstructionSetRepository.h"
#include "JSONInstructionSetRepository.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class InstructionSetRepoFactory
///
/// @brief Factory class for creating instances of IInstructionSetRepository
///
/////////////////////////////////////////////////////////////////////
class InstructionSetRepoFactory
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    InstructionSetRepoFactory() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of IInstructionSetRepository
    ///
    /// @return A shared pointer to a JSONInstructionSetRepository instance
    ///
    /////////////////////////////////////////////////////////////////////
    static std::shared_ptr<IInstructionSetRepository> create()
    {
        return std::make_shared<JSONInstructionSetRepository>();
    }
};

} // namespace ls6502
