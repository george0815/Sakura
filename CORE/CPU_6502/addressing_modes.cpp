#pragma once
#include "core.h"
#include <cstdint>
#include <filesystem>
// Anonymous namespace for variables that are only accessed in this file
namespace {

// CONSTANTS

constexpr uint16_t ZERO_PAGE_MASK = 0x00FF; // addre
} // namespace

// OTHER ADDRESSING MODES

// In implicit addressing, the operand is already implied in the opcode, so just
// returning 0 is fine
uint16_t CPU_6502::IMPLICIT() { return 0; }

// In accumulator addressing, the operand is the accumulator (yea, no shit
// right? lol), so again, just returning 0 is fine
uint16_t CPU_6502::ACCUMULATOR() { return 0; }

// For immediate addressing, the operand is the byte after the opcode, so we
// just increment the program counter by one
// 1. read(PC++) is called in the CPU clock function, getting the byte at the
// address that is the value of the program counter
// 2. Respective addressing mode is called, IMMEDIATE returns the program
// counter, then increments
// 3. Opcode then uses that as the operand address for the operation (LDA, STA,
// etc)
uint16_t CPU_6502::IMMEDIATE() { return PC++; }

// For zero page addressing the operand address is the data at the address that
// is the value of the program counter, the data that is returned from read is
// uint8_t, so the hi byte is implicitly 0x00 when it gets return as uint16_t
uint16_t CPU_6502::ZERO_PAGE() { return static_cast<uint16_t>(read(PC++)); }

// For absolute addressing, and address is constructed by reading the next 2
// bytes using the program counter I then contruct then aboslute address by
// getting the lo byte and hi byte, then combining them
uint16_t CPU_6502::ABSOLUTE() {
  uint8_t lo = read(PC++);
  uint8_t hi = read(PC++);

  uint16_t addr =
      (hi << 8) | lo; // this effective combines the hi and lo into one address,
                      // shifts the hi 8 bits to the left, then ORs with the lo

  return addr;
}

// For relative addressing, gets a signed byte then adds/subtracts that value
// from the PC, now program excecution proceeds from the new PC value C++ will
// automatically convert a uint8_t to a signed int8_t using two's complement
// This is really only used for branch instructions
uint16_t CPU_6502::RELATIVE() {

  int8_t offset = read(PC++);
  return (PC + offset);
}

// For indirect addressing, the hi byte is read in first, then the lo byte
// Then a new addressing is construct
// Using that new address, I read in another hi byte then low byte to construct
// another address This is then added to the program counter then excecution
// procceeds from there

uint16_t CPU_6502::INDIRECT() {

  uint8_t hi = read(PC++);
  uint8_t lo = read(PC++);

  uint16_t addr = (hi << 8) | lo; // combine to make the address

  // Then use the new address to construct ANOTHER adress, now by getting the lo
  // first then the hi (man this is confusing sometimes lol)
  uint8_t new_lo = read(addr);
  uint8_t new_hi = read(addr + 1);

  uint16_t new_addr = (new_hi << 8) | lo; // combine final address

  return PC + new_addr; // add to program counter then return
}

// INDEXED ADDRESSING MODES

// For zero page indexed x addressing, we get the next byte, then add the x
// register, finally we get the zero page by ANDing it with a 2 byte mask
uint16_t CPU_6502::ZERO_PAGE_INDEXED_X() {

  // This can be done in one line but I want make this readable so I'm gonna do
  // it step by step
  uint8_t data = read(PC++);    // get data
  uint16_t combined = data + X; // add the X register
  uint16_t addr =
      combined & ZERO_PAGE_MASK; // get the zero page address, the mask is
                                 // 0x00FF so it effectivle just gets the low
                                 // byte also mirrors every 256 bytes
  return addr;
}

// For zero page indexed y addressing, we get the next byte, then add the y
// register, finally we get the zero page by ANDing it with a 2 byte mask
uint16_t CPU_6502::ZERO_PAGE_INDEXED_Y() {

  // This can be done in one line but I want make this readable so I'm gonna do
  // it step by step
  uint8_t data = read(PC++);    // get data
  uint16_t combined = data + Y; // add the y register
  uint16_t addr =
      combined & ZERO_PAGE_MASK; // get the zero page address, the mask is
                                 // 0x00FF so it effectivle just gets the low
                                 // byte also mirrors every 256 bytes
  return addr;
}
uint16_t CPU_6502::ABSOLUTE_INDEXED_Y() {}

uint16_t CPU_6502::ABSOLUTE_INDEXED_X() {}

uint16_t CPU_6502::INDEXED_INDIRECT() {}

uint16_t CPU_6502::INDIRECT_INDEXED() {}
