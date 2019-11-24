#pragma once

#include "datamemory.hpp"
#include "iteratableinstructionbuffer.hpp"
#include "token_base.hpp"
#include "token_decrementptr.hpp"
#include "token_decrementval.hpp"
#include "token_incrementptr.hpp"
#include "token_incrementval.hpp"
#include "token_input.hpp"
#include "token_loopbeg.hpp"
#include "token_loopend.hpp"
#include "token_output.hpp"

#include <fstream>
#include <memory>
#include <stack>
#include <iostream>

// ソースコードをトークン列に変換したものを保持し、1行ずつ実行するクラス
class InstructionBuffer : public IteratableInstructionBuffer {
public:
  inline InstructionBuffer(const char* const filePath) {
    auto ifs = std::ifstream(filePath);
    if (!ifs) {
      std::exit(1);
    }

    std::stack<size_t> loopBegIdx;
    while (!ifs.eof()) {
      ReadInstruction(ifs.get(), loopBegIdx);
    }
    instructionPtr = program.begin();
    int n = 6;
  }

  inline void Execute(DataMemory& dataMem) {
    while (instructionPtr != program.end()) {
      (*instructionPtr)->Execute(dataMem);
      ++instructionPtr;
    }
  }

private:
  using IteratableInstructionBuffer::program;
  using IteratableInstructionBuffer::instructionPtr;

  inline void ReadInstruction(const uint8_t byte, std::stack<size_t>& loopBegIdx) {
#ifdef _DEBUG
    std::cout << byte;
#endif
    switch (byte) {
      case '+': {
        program.emplace_back(std::make_unique<token::IncrementVal>());
      } break;

      case '-': {
        program.emplace_back(std::make_unique<token::DecrementVal>());
      } break;

      case '>': {
        program.emplace_back(std::make_unique<token::IncrementPtr>());
      } break;

      case '<': {
        program.emplace_back(std::make_unique<token::DecrementPtr>());
      } break;

      case '.': {
        program.emplace_back(std::make_unique<token::Output>());
        std::cout << std::endl;
      } break;

      case ',': {
        program.emplace_back(std::make_unique<token::Input>());
      } break;

      case '[': {
        program.emplace_back(nullptr);
        loopBegIdx.push(program.size() - 1); // ループ開始位置を保持
      } break;

      case ']': {
        program.emplace_back(std::make_unique<token::LoopEnd>(this, program.begin() + loopBegIdx.top()));
        program[loopBegIdx.top()] = std::make_unique<token::LoopBeg>(this, program.end() - 1);
        loopBegIdx.pop();
      } break;

      default: {
      } break;
    }
  }
};
