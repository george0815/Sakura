#pragma once

#include "../BUS/bus.h"
#include <array>
#include <cstdint>
#include <string>

class CPU_6502 {

public:


  //Builds lookup table, which is basically an vector of INSTRUCTION structs using the opcode as the index
  void CPU_6502::BUILD_LOOKUP();


  //Handles reset 
  void RESET_HANDLER();
  


  //Handles normal IRQ 
  void IRQ_HANDLER();


  //Handles NMI
  void NMI_HANDLER();


  //Helper function for branching 
  void BRANCH(uint16_t target, bool condition);


  //Helper function for setting flags
  void SET_FLAG(STATUS value, bool condition);


  //Helper function for getting flags
  void GET_FLAG();

  // The bus, the CPU will never talk to the PPU directly but rather through the
  // bus, the bus is basically the motherboard of the NES
  BUS *B;

  // bool for detecting whether a page has been crossed, used by addressing
  // modes
  bool PAGE_CROSSED = false;

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

  //Vector constants for interupts
  //during an interrupt, the CPU will push the current program counter to the stack
  //then load a new PC from one of the predetermined vectors 
  constexpr NMI_VECTOR = 0xFFFA;
  constexpr RESET_VECTOR = 0xFFFC;
  constexpr IRQ_VECTOR = 0xFFFE;


  //status enum
  enum STATUS {

    CARRY = 1 << 0,
    ZERO = 1 << 1,
    INTERRUPT_DISABLE = 1 << 2,
    DECIMAL = 1 << 3,
    B = 1 << 4,
    UNUSED = 1 << 5,
    OVERFLOW = 1 << 6,
    NEGATIVE = 1 << 7,

  }

    
  // status register
  uint8_t STATUS_REGISTER = 0x00 | STATUS::UNUSED;


  // Read and write
  uint8_t read(uint16_t addr);
  void write(uint16_t addr, uint8_t data);


  //Push and pull to/from stack
  uint8_t pull();
  void push(uint8_t data);

private:
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

  // OFFICIAL INSTRUCTIONS
  void ADC(uint16_t addr);
  void AND(uint16_t addr);
  void ASL(uint16_t addr);
  void BCC(uint16_t addr);
  void BCS(uint16_t addr);
  void BEQ(uint16_t addr);
  void BIT(uint16_t addr);
  void BMI(uint16_t addr);
  void BNE(uint16_t addr);
  void BPL(uint16_t addr);
  void BRK(uint16_t addr);
  void BVC(uint16_t addr);
  void BVS(uint16_t addr);
  void CLC(uint16_t addr);
  void CLD(uint16_t addr);
  void CLI(uint16_t addr);
  void CLV(uint16_t addr);
  void CMP(uint16_t addr);
  void CPX(uint16_t addr);
  void CPY(uint16_t addr);
  void DEC(uint16_t addr);
  void DEX(uint16_t addr);
  void DEY(uint16_t addr);
  void EOR(uint16_t addr);
  void INC(uint16_t addr);
  void INY(uint16_t addr);
  void INX(uint16_t addr);
  void JMP(uint16_t addr);
  void JSR(uint16_t addr);
  void LDA(uint16_t addr);
  void LDX(uint16_t addr);
  void LDY(uint16_t addr);
  void LSR(uint16_t addr);
  void NOP(uint16_t addr);
  void ORA(uint16_t addr);
  void PHA(uint16_t addr);
  void PHP(uint16_t addr);
  void PLA(uint16_t addr);
  void PLP(uint16_t addr);
  void ROL(uint16_t addr);
  void ROR(uint16_t addr);
  void RTI(uint16_t addr);
  void RTS(uint16_t addr);
  void SBC(uint16_t addr);
  void SEC(uint16_t addr);
  void SED(uint16_t addr);
  void SEI(uint16_t addr);
  void STA(uint16_t addr);
  void STX(uint16_t addr);
  void STY(uint16_t addr);
  void TAX(uint16_t addr);
  void TAY(uint16_t addr);
  void TSX(uint16_t addr);
  void TXA(uint16_t addr);
  void TXS(uint16_t addr);
  void TYA(uint16_t addr);

  // UNIMPLEMENTED/INVALID
  void XXX(uint16_t addr);

  // Struct representing an opcode, this is so that an opcode's corresponding
  // instruction and addressing mode can be called easily in the CPU's clock
  // function without having a huge fucking switch statement
  typedef struct {

    int cycles; // number of cycles, some instructions may take multiple cycles
                // so its important to know

    std::string mnemonic; // used for logging

    int bytes; // how many bytes the total opcode is

    void (*opcode)(uint16_t); // pointer to the opcode's instruction

    uint16_t (*addr_mode)(void); // pointer to the opcode's addressing mode

  } OPCODE;

  // Lookup table, this is basically the brain of the implementation, it is an
  // array of OPCODE structs using the opcode as the index for each execution of
  // an opcode, the opcode is read in then used to find it's respective
  // addressing mode and instruction
  std::array<OPCODE, 256> LOOKUP;
};
