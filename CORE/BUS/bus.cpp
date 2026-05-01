#include "bus.h"
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

/*The CPU has an addressable range of 64KB, here is the memory map chart
 * curtisey (that is definitely not how you spell it lol) of the NESDEV wiki
 *
 *$0000 - $07FF - 2KB internal CPU RAM
 *
 *$0800 - $1FFF - 2KB -> 8KB, mirrors the original 2KB, I will explain
 * mirroring later on in this file (different from nametable mirroring)
 *
 * $2000 - $2007 - PPU registers, this is accessed through the bus
 *
 * $2008 - $3FFF - Mirrors the PPU registers, basically for every 8 bytes in
 * this range, it will map to a byte in the range of $2000 - $2007 For
 * example: 2008 -> 2000, 2009 -> 2001, etc
 *
 *$4000 - $4017 - NES PPU
 *$4018 - $401F - APU and IO, normally disabled
 *$4020 - $FFFF - unmapped
 *
 * */

uint8_t BUS::read(uint16_t addr) {

  // If address is within the 8KB addressable range for the CPU RAM
  if (addr < 0x2000) {

    // mirrored every 2KB, ANDing (size - 1) is the basically the same as %
    // size (as long as your dealing with binary numbers) this is because when
    // you decrement a power of 2 (2048, etc) by 1, in binary all the lower
    // bits will be 1, and the bit that was originally 1 is now 0 0x0800 = 2KB
    // = 2048 = 0000 1000 0000 0000 -> 0x07FF = 2047 = 0000 0111 1111 1111
    return CPU_RAM[addr & 0x07FF]; // mirrored every 2KB, ANDing (size - 1) is
                                   // the basically the same as % size (as long
                                   // as your dealing with binary numbers)
  }

  else if (addr > 0x8000) {

    // If ROM size is 16KB (0x4000 = 16KB)
    if (PRG_ROM.size() == 0x4000) {
      return PRG_ROM
          [addr &
           0x3FFF]; // here I use the same principle discussed earlier, &
                    // 0x3FFF mirrors the addr every 16kb, so for every 16kb
                    // the address starts from 0 again
                    // 1. To properly emulate hardware behavior, since thats
                    // what the NES will do if it the address is outside the
                    // 16KB range for a 16KB ROM
                    // 2. To make the index fit into the PRG_ROM vector rnage
    }
    // If ROM size is 32KB
    else if (PRG_ROM.size() > 0x4000) {
      return PRG_ROM[addr -
                     0x8000]; // I subtract 0x8000 here because the PRG_ROM
                              // vector starts at index 0, but the CPU is
                              // addressing from 0x8000, so I'm normalizing
                              // the index I don't mirror here because the ROM
                              // in this situation is already 32 KB, so the
                              // CPU wont try an address thats out of range
    }
  }
}

void BUS::write(uint16_t addr, uint8_t data) {

  // If address falls into the 8KB addressable range for internal CPU CPU_RAM
  if (addr < 0x2000)
    CPU_RAM[addr & 0x07FF] = data; // here we mirror it every 2KB again
}

void BUS::connect_cpu(CPU_6502 &cpu) {
  CPU = &cpu;
  cout << "BUS <- CPU";
}

void BUS::insert_cartridge(CART &cart) { PRG_ROM = cart.PRG; }

void BUS::step() {
  cout << "STEP CPU";
  CPU->step();
}
