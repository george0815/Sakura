#include "core.h"
#include <cstdint>
#include <sys/types.h>

// OFFICIAL INSTRUCTIONS

// Add withn carry, adds the carry flag and a memory value to the accumulator
// carry flag is the set to the carry value coming out of bit 7
void CPU_6502::ADC(uint16_t addr) {}

// Bitwise AND, ANDs a memory value with the accumulator, bit by bit
void CPU_6502::AND(uint16_t addr) {}

// Arithmetic shift left, shifts all bits of a value one position to the left
// bit 7 is shifted into the carry flag, and 0 is shifted into bit 0
// equivalent to multiplying the unsigned value by 2
void CPU_6502::ASL(uint16_t addr) {}

// Branch if carry clear, if the carry is clear then branches by adding the
// offset to the PC offset is signed and has a range of -128 -> 127
void CPU_6502::BCC(uint16_t addr) {}

// Branch if carry set, if the carry is set then branches by adding the offset
// to the PC offset is signed and has a range of -128 -> 127
void CPU_6502::BCS(uint16_t addr) {}

// Branch if equal, if the zero flag is set then branches by adding the offset
// to the PC offset is signed and has a range of -128 -> 127
void CPU_6502::BEQ(uint16_t addr) {}

// Bit test, modifies flags but does not change memory or registers.
// the zero flag is set depending on the reselt of the accumulator AND memory
// value bits 7 and 6 of the memory value are loaded directly into the negative
// and overflow flags
void CPU_6502::BIT(uint16_t addr) {}

// Branch if minus, if the negative flag is set then branches by adding the
// offset to the PC offset is signed and has a range of -128 -> 127
void CPU_6502::BMI(uint16_t addr) {}

// Branch if not equal, if the zero flag is clear then branches by adding the
// relative offset to the PC offset is signed and has a range of -128 -> 127
void CPU_6502::BNE(uint16_t addr) {}

// Branch if plus, if the negative flag is clear then branches by adding the
// relative offset to the PC offset is signed and has a range of -128 -> 127
void CPU_6502::BPL(uint16_t addr) {}

// Break, software IRQ (interrupt request), triggers an IRQ
// this instruction is the only way to trigger an IRQ via software
// pushes the current PC and flags to the stack, sets the IRQ flag, and jumps to
// the IRQ handler unlike a normal IRQ, sets the break flag in the flags byte
// and triggers an interrupt even if the interrupt disable flag is set the
// return address that is pushed to the stack skips the byte after the BRK
// opcode
void CPU_6502::BRK(uint16_t addr) {}

// Branch if overflow clear, if the overflow flag is clear then branches by
// adding the relative offset to the PC offset is signed and has a range of -128
// -> 127
void CPU_6502::BVC(uint16_t addr) {}

// Branch if overflow set, if the overflow flag is set then branches by adding
// the relative offset to the PC offset is signed and has a range of -128 -> 127
void CPU_6502::BVS(uint16_t addr) {}

// Clear carry, clears the carry flag
void CPU_6502::CLC(uint16_t addr) {}

// Clear carry, clears the decimal flag
void CPU_6502::CLD(uint16_t addr) {}

// Clear carry, clears the interrupt disable flag
void CPU_6502::CLI(uint16_t addr) {}

// Clear carry, clears the overflow flag
void CPU_6502::CLV(uint16_t addr) {}

// Compare A, compares the accumulator to a memory value
// sets flags as appropriate but does not modify any of the registers
// comparison is implemented as a subtraction, setting carry if there is no
// borrow zero if the result is 0, negative if the result is negative
void CPU_6502::CMP(uint16_t addr) {}

// Compare X, compares Y to a memory value
// sets flags as appropriate but does not modify any of the registers
// comparison is implemented as a subtraction, setting carry if there is no
// borrow zero if the result is 0, negative if the result is negative
void CPU_6502::CPX(uint16_t addr) {}

// Compare Y, compares Y to a memory value
// sets flags as appropriate but does not modify any of the registers
// comparison is implemented as a subtraction, setting carry if there is no
// borrow zero if the result is 0, negative if the result is negative
void CPU_6502::CPY(uint16_t addr) {}

// Decrement memory, subtracts 1 from a memory location
void CPU_6502::DEC(uint16_t addr) {}

// Decrement X, subtracts 1 from the X register
void CPU_6502::DEX(uint16_t addr) {}

// Decrement Y, subtracts 1 from the Y register
void CPU_6502::DEY(uint16_t addr) {}

// Bitwise exclusive OR, XORs a memory value with the accumulator, bit by bit
void CPU_6502::EOR(uint16_t addr) {}

// Increment memory, 1 is added to a memory value
void CPU_6502::INC(uint16_t addr) {}

// Increment Y, 1 is added to the Y register
void CPU_6502::INY(uint16_t addr) {}

// Increment X, 1 is added to the X register
void CPU_6502::INX(uint16_t addr) {}

// Jump, sets the PC to a new value, allowing code to execute from a new
// location JMP BUG: if the new 2 byte PC crosses a page (ends in FF), then the
// CPU fails to increment the page wheen reading the second byte
void CPU_6502::JMP(uint16_t addr) {}

// Pushes the current program counter to the stack, then sets the PC to a new
// value then the code can call a function and return using RTS the return
// address on the stack points 1 byte before the start of the next instruction
void CPU_6502::JSR(uint16_t addr) {}

// Loads a memory value into the accumulator
void CPU_6502::LDA(uint16_t addr) {}

// Loads a memory value into the X register
void CPU_6502::LDX(uint16_t addr) {}

// Loads a memory value into the Y register
void CPU_6502::LDY(uint16_t addr) {}

// Logical shift right, shifts all bits of a memory value or the accumulator one
// position to the right 0 is shifted into bit 7, and 0 is shifted to the carry
// flag equivalent of dividing an unsigned integer by 2 and rounding down, with
// the remainder in the carry flag
void CPU_6502::LSR(uint16_t addr) {}

// No operation, literally just does fucking nothing and wastes space and CPU
// cycles
void CPU_6502::NOP(uint16_t addr) {}

// Bitwise OR, ORs a memory value and the accumulator, bit by bit
void CPU_6502::ORA(uint16_t addr) {}

// Push A, stores the value of the accumulator to the current stack position
// then decrements the stack pointer
void CPU_6502::PHA(uint16_t addr) {}

// Push processor status, pushes a byte representing the status register to the
// stack, then decrements the stack pointer the B flag and the extra bit are
// both pushed as one
void CPU_6502::PHP(uint16_t addr) {}

// Pull A, increments the stack pointer then loads that value at that stack
// position into A
void CPU_6502::PLA(uint16_t addr) {}

// Pull processor status, increments the stack pointer then loads that byte into
// the 6 flags
void CPU_6502::PLP(uint16_t addr) {}

// Rotate left, shifts a memory value or the accumulator to the left
// the carry flag is treated as though it is both above bit 7 and below bit 0
// so bit 7 is shifted to carry, and carry is shifted to bit 0
void CPU_6502::ROL(uint16_t addr) {}

// Rotate right, shifts a memory value or the accumulator to the right
// the carry flag is treated as though it is both above bit 7 and below bit 0
// so bit 7 is shifted to carry, and carry is shifted to bit 0
void CPU_6502::ROR(uint16_t addr) {}

// Return from interrupt, returns from an interrupt handler by pulling the
// status flags from the stack, then pulling the new program counter similar to
// PLP but changes to the interrupt disable flag apply immediately instead of
// being delayed one instruction
void CPU_6502::RTI(uint16_t addr) {}

// Return from subroutine, pulls an address from the stack into the program
// counter, then increments the program counter
void CPU_6502::RTS(uint16_t addr) {}

// Subtract with carry, subtracts a memory value and the NOT of the carry flag
// from the accumulator it does this by adding the bitwise NOT of the memory
// value using ADC carry is cleared when it underflows and set otherwise
// overflow works the same as ADC, except with an intverted memory value
void CPU_6502::SBC(uint16_t addr) {}

// Set carry, sets the carry flag
void CPU_6502::SEC(uint16_t addr) {}

// Set decimal, sets the decimal flag
void CPU_6502::SED(uint16_t addr) {}

// Set interrupt disable, sets the interrupt disable flag
void CPU_6502::SEI(uint16_t addr) {}

// Store accumulator, stores the accumulator value into memory
void CPU_6502::STA(uint16_t addr) {}

// Store X, stores the X register value into memory
void CPU_6502::STX(uint16_t addr) {}

// Store Y, stores the Y register value into memory
void CPU_6502::STY(uint16_t addr) {}

// Transfer A to X, copies the accumulator value to the X register
void CPU_6502::TAX(uint16_t addr) {}

// Transfer A to Y, copies the accumulator value to the Y register
void CPU_6502::TAY(uint16_t addr) {}

// Transfer stack pointer to X, copies the stack pointer value to the X register
void CPU_6502::TSX(uint16_t addr) {}

// Transfer X to the accumulator, copies the X register value to the accumulator
void CPU_6502::TXA(uint16_t addr) {}

// Transfer X to the stack pointer, copies the X register value to the stack
// pointer
void CPU_6502::TXS(uint16_t addr) {}

// Transfer Y to the accumulator, copies the Y register value to the accumulator
void CPU_6502::TYA(uint16_t addr) {}

// UNIMPLEMENTED/INVALID

void CPU_6502::XXX(uint16_t addr) {}

/// BUILD LOOKUP TABLE
void CPU_6502::BUILD_LOOKUP() {

  // Lambda for adding instructions to the lookup table
  auto INSERT_INSTRUCTION = [this](uint8_t opcode_byte, const char *mnemonic,
                                   int cycles,
                                   void (CPU_6502::*opcode)(uint16_t),
                                   uint16_t (CPU_6502::*addr_mode)()) {
    auto instruciton_length =
        [&](uint16_t (CPU_6502::*addr_mode)()) -> uint8_t {
      if (addr_mode == &CPU_6502::IMPLICIT ||
          addr_mode == &CPU_6502::ACCUMULATOR) {
        return 1;
      }
      if (addr_mode == &CPU_6502::RELATIVE ||
          addr_mode == &CPU_6502::IMMEDIATE ||
          addr_mode == &CPU_6502::ZERO_PAGE ||
          addr_mode == &CPU_6502::ZERO_PAGE_INDEXED_X ||
          addr_mode == &CPU_6502::ZERO_PAGE_INDEXED_Y ||
          addr_mode == &CPU_6502::INDEXED_INDIRECT ||
          addr_mode == &CPU_6502::INDIRECT_INDEXED) {
        return 2;
      }
      return 3;
    };

    LOOKUP[opcode_byte] = {mnemonic, cycles, instruciton_length(addr_mode),
                           opcode, addr_mode};
  };

  // Fill lookup table with NOP
  for (auto &inst : LOOKUP) {
    inst = {"NOP", 2, 1, &CPU_6502::NOP, &CPU_6502::IMPLICIT};
  };
}
