#pragma once

#include <array>
#include <cstdint>
#include <iosfwd>

class DataMemory {
public:
  inline DataMemory() 
    : dataMem{}
    , ptr(dataMem.begin()) {
    for (auto& byte : dataMem) {
      byte = 0;
    }
  }

  inline void IncrementVal() {
    ++(*ptr);
  }

  inline void DecrementVal() {
    --(*ptr);
  }

  inline void IncrementPtr() {
    ++ptr;
  }

  inline void DecrementPtr() {
    --ptr;
  }

  inline void Output(std::ostream& ost) {
    ost << (*ptr);
  }

  inline void Input(std::istream& ist) {
    ist >> (*ptr);
  }

  inline uint8_t operator*() {
    return *ptr;
  }

private:
  std::array<uint8_t, 30000> dataMem;
  std::array<uint8_t, 30000>::iterator ptr;
};