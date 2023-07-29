#ifndef LLVM_TABLEGEN_CODECOMPLETE_H
#define LLVM_TABLEGEN_CODECOMPLETE_H

#include "llvm/Support/SourceMgr.h"

namespace llvm {
class CodeCompleteContext {
public:
  virtual ~CodeCompleteContext() = default;

  SMLoc getCodeCompleteLoc() const { return codeCompleteLoc; }

  virtual void completeKeyword(StringRef keyword) = 0;

  void completeKeywords(ArrayRef<StringRef> keywords) {
    for (auto &keyword : keywords) {
      completeKeyword(keyword);
    }
  }

  virtual void completeClass(StringRef class_) = 0;

  void completeClasses(ArrayRef<StringRef> classes) {
    for (auto &class_ : classes) {
      completeClass(class_);
    }
  }

protected:
  explicit CodeCompleteContext(SMLoc codeCompleteLoc)
      : codeCompleteLoc(codeCompleteLoc) {}

private:
  SMLoc codeCompleteLoc;
};
} // namespace llvm

#endif // LLVM_TABLEGEN_CODECOMPLETE_H
