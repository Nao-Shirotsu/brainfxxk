#pragma once

#include "iteratableinstructionbuffer.hpp"
#include "token_base.hpp"

namespace token {

class LoopEnd final : public Base {
public:
  inline LoopEnd() = default;
  inline LoopEnd(IteratableInstructionBuffer* instBuf_, InstructionPtr_t begItr_)
    : instBuf(instBuf_) 
    , begItr(begItr_){}

  void Execute(DataMemory& dataPtr) override {
    instBuf->instructionPtr = begItr;
#ifdef _DEBUG
    std::cout << ']';
#endif
  }

private:
  IteratableInstructionBuffer* instBuf;
  InstructionPtr_t begItr;
};

} // namespace token