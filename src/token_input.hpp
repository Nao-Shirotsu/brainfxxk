#pragma once

#include "token_base.hpp"

#include <iostream>

namespace token {

class Input final : public Base {
public:
  void Execute(DataMemory& dataPtr) override {
    dataPtr.Input(std::cin);
#ifdef _DEBUG
    std::cout << ',';
#endif
  }
};

} // namespace token