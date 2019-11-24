#pragma once

#include "token_base.hpp"

#include <vector>
#include <memory>

using InstructionPtr_t = std::vector<std::unique_ptr<token::Base>>::iterator;

struct IteratableInstructionBuffer {
  std::vector<std::unique_ptr<token::Base>> program;
  std::vector<std::unique_ptr<token::Base>>::iterator instructionPtr;
};