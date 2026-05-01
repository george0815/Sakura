#pragma once
#include "../CART/cart.h"
#include "../CPU_6502/core.h"
#include <array>
#include <cstdint>
#include <vector>

class CPU_6502;
struct CART;

class BUS {

public:
  std::array<uint8_t, 0x0800> CPU_RAM;
  // CPU has access to 2KB of internal RAM, its fixed so I'll be using an array

  // Program ROM can either be 16KB or 32KB, so I'll be using a vector
  std::vector<uint16_t> PRG_ROM;

  void insert_cartridge(CART &cart);

  void connect_cpu(CPU_6502 &cpu);

  uint8_t read(uint16_t addr);
  void write(uint16_t addr, uint8_t data);
};
