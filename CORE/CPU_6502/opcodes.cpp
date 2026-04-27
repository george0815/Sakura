#include <cstdint>
#include "core.h"

//for constants, will add later
namespace {


}


CPU_6502::

//Helper function for branching TODO
void CPU_6502::BRANCH(){
  
}




//Helper function for setting flags TODO
void CPU_6502::SET_FLAG(){

}





//OFFICIAL INSTRUCTIONS
  
//Add withn carry, adds the carry flag and a memory value to the accumulator
//carry flag is the set to the carry value coming out of bit 7
void CPU_6502::ADC(uint16_t addr){


}


//Bitwise AND, ANDs a memory value with the accumulator, bit by bit
void CPU_6502::AND(uint16_t addr){

  
}



//Arithmetic shift left, shifts all bits of a value one position to the left
//bit 7 is shifted into the carry flag, and 0 is shifted into bit 0
//equivalent to multiplying the unsigned value by 2 
void CPU_6502::ASL(uint16_t addr){



}


//Branch if carry clear, if the carry is clear then branches by adding the offset to the PC 
//offset is signed and has a range of -128 -> 127
void CPU_6502::BCC(uint16_t addr){




}


//Branch if carry set, if the carry is set then branches by adding the offset to the PC 
//offset is signed and has a range of -128 -> 127
void CPU_6502::BCS(uint16_t addr){




}




//Branch if equal, if the zero flag is set then branches by adding the offset to the PC 
//offset is signed and has a range of -128 -> 127
void CPU_6502::BEQ(uint16_t addr){





}




//Bit test, modifies flags but does not change memory or registers. 
//the zero flag is set depending on the reselt of the accumulator AND memory value 
//bits 7 and 6 of the memory value are loaded directly into the negative and overflow flags
void CPU_6502::BIT(uint16_t addr){



}



//Branch if minus, if the negative flag is set then branches by adding the offset to the PC 
//offset is signed and has a range of -128 -> 127
void CPU_6502::BMI(uint16_t addr){



}



//Branch if not equal, if the zero flag is clear then branches by adding the relative offset to the PC 
//offset is signed and has a range of -128 -> 127
void CPU_6502::BNE(uint16_t addr){




}



//Branch if plus, if the negative flag is clear then branches by adding the relative offset to the PC 
//offset is signed and has a range of -128 -> 127
void CPU_6502::BPL(uint16_t addr){





}


//Break, software IRQ (interrupt request), triggers an IRQ
//this instruction is the only way to trigger an IRQ via software
//pushes the current PC and flags to the stack, sets the IRQ flag, and jumps to the IRQ handler
//unlike a normal IRQ, sets the break flag in the flags byte and triggers an interrupt even if the interrupt disable flag is set
//the return address that is pushed to the stack skips the byte after the BRK opcode 
void CPU_6502::BRK(uint16_t addr){




}





//Branch if overflow clear, if the overflow flag is clear then branches by adding the relative offset to the PC 
//offset is signed and has a range of -128 -> 127
void CPU_6502::BVC(uint16_t addr){





}



//Branch if overflow set, if the overflow flag is set then branches by adding the relative offset to the PC 
//offset is signed and has a range of -128 -> 127
void CPU_6502::BVS(uint16_t addr){




}


//Clear carry, clears the carry flag  
void CPU_6502::CLC(uint16_t addr){



}



//Clear carry, clears the decimal flag  
void CPU_6502::CLD(uint16_t addr){



}




//Clear carry, clears the interrupt disable flag  
void CPU_6502::CLI(uint16_t addr){




}





//Clear carry, clears the overflow flag  
void CPU_6502::CLV(uint16_t addr){




}



//Compare A, compares the accumulator to a memory value
//sets flags as appropriate but does not modify any of the registers 
//comparison is implemented as a subtraction, setting carry if there is no borrow
//zero if the result is 0, negative if the result is negative
void CPU_6502::CMP(uint16_t addr){




}





//Compare X, compares Y to a memory value
//sets flags as appropriate but does not modify any of the registers 
//comparison is implemented as a subtraction, setting carry if there is no borrow
//zero if the result is 0, negative if the result is negative
void CPU_6502::CPX(uint16_t addr){



  
}





//Compare Y, compares Y to a memory value
//sets flags as appropriate but does not modify any of the registers 
//comparison is implemented as a subtraction, setting carry if there is no borrow
//zero if the result is 0, negative if the result is negative
void CPU_6502::CPY(uint16_t addr){



}





void CPU_6502::DEC(uint16_t addr){





}





void CPU_6502::DEX(uint16_t addr){





}





void CPU_6502::DEY(uint16_t addr){





}





void CPU_6502::EOR(uint16_t addr){






}





void CPU_6502::INC(uint16_t addr){





}





void CPU_6502::INY(uint16_t addr){





}





void CPU_6502::INX(uint16_t addr){






}





void CPU_6502::JMP(uint16_t addr){





}





void CPU_6502::JSR(uint16_t addr){






}





void CPU_6502::LDA(uint16_t addr){




}





void CPU_6502::LDX(uint16_t addr){





}





void CPU_6502::LDY(uint16_t addr){





}





void CPU_6502::LSR(uint16_t addr){





}





void CPU_6502::NOP(uint16_t addr){





}





void CPU_6502::ORA(uint16_t addr){





}






void CPU_6502::PHA(uint16_t addr){




}





void CPU_6502::PHP(uint16_t addr){




}






void CPU_6502::PLA(uint16_t addr){




}





void CPU_6502::PLP(uint16_t addr){




}





void CPU_6502::ROL(uint16_t addr){





}





void CPU_6502::ROR(uint16_t addr){





}





void CPU_6502::RTI(uint16_t addr){






}





void CPU_6502::RTS(uint16_t addr){





}





void CPU_6502::SBC(uint16_t addr){





}





void CPU_6502::SEC(uint16_t addr){





}





void CPU_6502::SED(uint16_t addr){





}





void CPU_6502::SEI(uint16_t addr){




}





void CPU_6502::STA(uint16_t addr){




}





void CPU_6502::STX(uint16_t addr){



}





void CPU_6502::STY(uint16_t addr){



}






void CPU_6502::TAX(uint16_t addr){




}





void CPU_6502::TAY(uint16_t addr){





}





void CPU_6502::TSX(uint16_t addr){




}





void CPU_6502::TXA(uint16_t addr){





}





void CPU_6502::TXS(uint16_t addr){




}




void CPU_6502::TYA(uint16_t addr){




}


//UNIMPLEMENTED/INVALID 


void CPU_6502::XXX(uint16_t addr){




}



