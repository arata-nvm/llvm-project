#ifndef LLVM_TABLEGEN_CODECOMPLETE_H
#define LLVM_TABLEGEN_CODECOMPLETE_H

#include "llvm/Support/SourceMgr.h"

namespace llvm {
class CodeCompleteContext {
public:
  virtual ~CodeCompleteContext() = default;

  SMLoc getCodeCompleteLoc() const { return codeCompleteLoc; }

protected:
  explicit CodeCompleteContext(SMLoc codeCompleteLoc)
      : codeCompleteLoc(codeCompleteLoc) {}

private:
  SMLoc codeCompleteLoc;
};
} // namespace llvm

#endif // LLVM_TABLEGEN_CODECOMPLETE_H
