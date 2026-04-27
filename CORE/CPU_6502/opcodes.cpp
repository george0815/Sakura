#include <cstdint>
#include "core.h"

//for constants, will add later
namespace {


}




//Helper function for branching TODO
void BRANCH(){
  
}




//Helper function for setting flags TODO
void SET_FLAG(){

}





//OFFICIAL INSTRUCTIONS
  
//Add withn carry, adds the carry flag and a memory value to the accumulator
//carry flag is the set to the carry value coming out of bit 7
void ADC(uint16_t addr){


}


//Bitwise AND, ANDs a memory value with the accumulator, bit by bit
void AND(uint16_t addr){

  
}



//Arithmetic shift left, shifts all bits of a value one position to the left
//bit 7 is shifted into the carry flag, and 0 is shifted into bit 0
//equivalent to multiplying the unsigned value by 2 
void ASL(uint16_t addr){



}


//Branch if carry clear, if the carry is clear then branches by adding the offset to the PC 
//offset is signed and has a range of -128 -> 127
void BCC(uint16_t addr){




}


//Branch if carry set, if the carry is set then branches by adding the offset to the PC 
//offset is signed and has a range of -128 -> 127
void BCS(uint16_t addr){




}




//Branch if equal, if the zero flag is set then branches by adding the offset to the PC 
//offset is signed and has a range of -128 -> 127
void BEQ(uint16_t addr){





}




//Bit test, modifies flags but does not change memory or registers. 
//the zero flag is set depending on the reselt of the accumulator AND memory value 
//bits 7 and 6 of the memory value are loaded directly into the negative and overflow flags
void BIT(uint16_t addr){



}



//Branch if minus, if the negative flag is set then branches by adding the offset to the PC 
//offset is signed and has a range of -128 -> 127
void BMI(uint16_t addr){



}



//Branch if not equal, if the zero flag is clear then branches by adding the relative offset to the PC 
//offset is signed and has a range of -128 -> 127
void BNE(uint16_t addr){




}



//Branch if plus, if the negative flag is clear then branches by adding the relative offset to the PC 
//offset is signed and has a range of -128 -> 127
void BPL(uint16_t addr){





}


//Break, software IRQ (interrupt request), triggers an IRQ
//this instruction is the only way to trigger an IRQ via software
//pushes the current PC and flags to the stack, sets the IRQ flag, and jumps to the IRQ handler
//unlike a normal IRQ, sets the break flag in the flags byte and triggers an interrupt even if the interrupt disable flag is set
//the return address that is pushed to the stack skips the byte after the BRK opcode 
void BRK(uint16_t addr){




}





//Branch if overflow clear, if the overflow flag is clear then branches by adding the relative offset to the PC 
//offset is signed and has a range of -128 -> 127
void BVC(uint16_t addr){





}



//Branch if overflow set, if the overflow flag is set then branches by adding the relative offset to the PC 
//offset is signed and has a range of -128 -> 127
void BVS(uint16_t addr){




}



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


//UNIMPLEMENTED/INVALID 
void XXX(uint16_t addr);



