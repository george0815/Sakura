#include "../Bus/bus.h"
#include "core.h"
#include <cstdint>
// Anonymous namespace for variables that are only accessed in this file
namespace {}

// In implicit addressing, the operand is already implied in the opcode, so just
// returning 0 is fine
uint8_t CPU_6502::IMPLICIT() { return 0; }

// In accumulator addressing, the operand is the accumulator (yea, no shit
// right? lol), so again, just returning 0 is fine
uint8_t CPU_6502::ACCUMULATOR() { return 0; }
