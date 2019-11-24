#pragma once

#include "token_base.hpp"

namespace token {

class IncrementVal final : public Base {
public:
  void Execute(DataMemory& dataPtr) override {
    dataPtr.IncrementVal();
#ifdef _DEBUG
    std::cout << '+';
#endif
  }
};

} // namespace token