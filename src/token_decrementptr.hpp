#pragma once

#include "token_base.hpp"

#include <iostream>

namespace token {

class DecrementPtr final : public Base {
public:
  void Execute(DataMemory& dataPtr) override {
    dataPtr.DecrementPtr();
    #ifdef _DEBUG
    std::cout << '<';
    #endif
  }
};

} // namespace token