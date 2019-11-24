#pragma once

#include "token_base.hpp"

namespace token {

class IncrementPtr final : public Base {
public:
  void Execute(DataMemory& dataPtr) override {
    dataPtr.IncrementPtr();
#ifdef _DEBUG
    std::cout << '>';
#endif
  }
};

} // namespace token