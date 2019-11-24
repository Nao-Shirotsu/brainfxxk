#include "instructionbuffer.hpp"
#include "datamemory.hpp"

int main() {
  auto program = InstructionBuffer("hello.bf");
  auto memory = DataMemory();
  program.Execute(memory);
}