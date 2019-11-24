#pragma once

#include "iteratableinstructionbuffer.hpp"
#include "token_base.hpp"

namespace token {

class LoopBeg final : public Base {
public:
  inline LoopBeg() = default;

  inline LoopBeg(IteratableInstructionBuffer* instBuf_, InstructionPtr_t endItr_)
      : Base()
      , instBuf(instBuf_)
      , endItr(endItr_) {}

  void Execute(DataMemory& dataPtr) override {
    if (!(*dataPtr)) {
      instBuf->instructionPtr = (endItr + 1);
      return;
    }
#ifdef _DEBUG
    std::cout << '[';
#endif
  }

private:
  IteratableInstructionBuffer* instBuf;
  InstructionPtr_t endItr;
};

} // namespace token