#pragma onceInstrCom

#include <memory>
#include <unordered_map>
#include <vector>

#include "../Algo/Trie.h"
#include "../Repo/IInstructionSetRepository.h"
#include "../Types/Instruction.h"
#include "ICompletionProvider.h"

namespace ls6502
{
typedef std::unordered_map<std::string, Instruction> InstructionSetMapT;

class InstructionSetCompletionProvider : public ICompletionProvider
{
  public:
    InstructionSetCompletionProvider();

    virtual std::vector<CompletionItem> getCompletions(const std::string &document,
                                                       const Position &position) override;

  private:
    void loadInstructionSetTrie();
    std::vector<CompletionItem> mapInstructionsToCompletions(const std::vector<std::string> &instructions);

  private:
    std::unique_ptr<Trie> m_instructionSetTrie = std::make_unique<Trie>();

    std::shared_ptr<IInstructionSetRepository> m_instructionSetRepository;

    InstructionSetMapT m_instructionSet;
};
} // namespace ls6502
