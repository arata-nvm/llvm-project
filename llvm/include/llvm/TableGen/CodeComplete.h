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

  virtual void completeClass(StringRef name) = 0;

  void completeClasses(ArrayRef<StringRef> names) {
    for (auto &name : names) {
      completeClass(name);
    }
  }

  virtual void completeValue(StringRef name) = 0;

  void completeValues(ArrayRef<StringRef> names) {
    for (auto &name : names) {
      completeValue(name);
    }
  }

  virtual void completeVariable(StringRef name, StringRef detail = "") = 0;

  void completeVariables(ArrayRef<StringRef> names) {
    for (auto &name : names) {
      completeVariable(name);
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
