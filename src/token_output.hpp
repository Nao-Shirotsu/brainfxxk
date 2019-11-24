#pragma once

#include "token_base.hpp"

#include <iostream>

namespace token {

class Output final : public Base {
public:
  void Execute(DataMemory& dataPtr) override {
    dataPtr.Output(std::cout);
#ifdef _DEBUG
    std::cout << '.' << std::endl;
#endif
  }
};

} // namespace token