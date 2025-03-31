#pragma once

#include <memory>

#include "../../Algo/Trie.h"
#include "../../Types/Instruction.h"

namespace ls6502
{
    typedef std::vector<Instruction> InstructionsT;

   class InstructionSetManager
   {
       public:

       private:
           std::unique_ptr<Trie> m_instructionSetTrie;
    
   };
}
