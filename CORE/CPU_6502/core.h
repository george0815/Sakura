#pragma once

#include "../BUS/bus.h"
#include <cstdint>

class CPU_6502 {

public:
  // The bus, the CPU will never talk to the PPU directly but rather through the
  // bus, the bus is basically the motherboard of the NES
  BUS *B;

  // connects bus, will implement later
  void connect_bus(BUS *bus);

  // 2 byte program counter, holds the address of the next opcode to be executed
  uint16_t PC = 0x0000;

  // 1 byte X register
  uint8_t X = 0x00;

  // 1 byte Y register
  uint8_t Y = 0x00;

  // 1 byte accumulator, uses the status register for carries, overflow
  // detection, etc
  uint8_t A = 0x00;

  // 1 byte stack pointer, accessed using interupts
  uint8_t SP = 0x00;

  // status register, I'm implementing it as a union so I can access specific
  // bits (using the struct inside) or it as a whole using the uint8_t
  union STATUS_REGISTER {

    uint8_t TOTAL_VALUE;
    struct FLAGS {

      uint8_t CARRY : 1;
      uint8_t ZERO : 2;
      uint8_t INTERRUPTDISABLE : 3;
      uint8_t DECIMAL : 4;
      uint8_t OVERFLOW : 7;
      uint8_t NEGATIVE : 8;
    };
  };

  // Read and write
  uint8_t read(uint16_t addr);
  void write(uint16_t addr, uint8_t data);

  // NES has 13 addressing modes, comprising of 6 indexed (basically, CPU takes
  // the base address and adds a register) and 7 other modes An addressing mode
  // basically tells the CPU where the data to conduct a given operation is, ie:
  // returns an address So for example for opcodes that use implicit addressing,
  // the location of the operand is implied, for immediate addressing, the
  // operand itself is used rather than an address

  // INDEXED ADDRESSING MODES
  uint16_t ZERO_PAGE_INDEXED_Y();
  uint16_t ZERO_PAGE_INDEXED_X();
  uint16_t ABSOLUTE_INDEXED_Y();
  uint16_t ABSOLUTE_INDEXED_X();
  uint16_t INDEXED_INDIRECT();
  uint16_t INDIRECT_INDEXED();

  // OTHER ADDRESSING MODES
  uint16_t ACCUMULATOR();
  uint16_t IMPLICIT();
  uint16_t IMMEDIATE();
  uint16_t ZERO_PAGE();
  uint16_t ABSOLUTE();
  uint16_t RELATIVE();
  uint16_t INDIRECT();
};
