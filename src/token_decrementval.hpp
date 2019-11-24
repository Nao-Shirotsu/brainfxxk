#pragma once

#include "token_base.hpp"

namespace token {

class DecrementVal final : public Base {
public:
  void Execute(DataMemory& dataPtr) override {
    dataPtr.DecrementVal();
#ifdef _DEBUG
    std::cout << '-';
#endif
  }
};

} // namespace token