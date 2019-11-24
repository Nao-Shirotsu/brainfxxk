#pragma once

#include "datamemory.hpp"

#ifdef _DEBUG
#include <iostream>
#endif

namespace token {

class Base {
public:
  inline virtual ~Base() {}
  virtual void Execute(DataMemory& dataPtr) = 0;
};

} // namespace token