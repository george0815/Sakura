#include "core.h"




//Helper function for branching, takes in a condition and a target
//checks for page crossing, then sets new PC
//Every time branch is called it costs a cycle, with an addional extra cycle if a page is crossed
void CPU_6502::BRANCH(uint16_t target, bool condition){
 

  cycles++; //increment cycles 
 
  if(condition){
    
    if (target && PAGE_MASK != PC && PAGE_MASK){ //check for page crossing 
      PAGE_CROSSED =  true;
      cycles++; //increment cycle again
      PC = target; // set PC to target
      
    } 


  }


}


//Reset, basically just resets the CPU to a known state
//The status register is cleared except for the unused bit
//A new program counter is then read form the reset vector, which is 0xFFFC
void CPU_6502::RESET_HANDLER(){
  
  //clear status register except unused bit
  STATUS_REGISTER = 0x00 | UNUSED;

  //clear other registers
  A = 0x00;
  X = 0x00;
  Y = 0x00;



  //construct new PC from vecor 
  uint8_t lo = read(RESET_VECTOR);
  uint8_t hi = read(RESET_VECTOR + 1);
  PC = (hi << 8) | lo;

  //Set cycles 
  CYCLES++;

}


//Interrupt request, its similar to a reset in the sense that a new PC is loaded from a vector
//But can only happen if the interrupt disable flag is set to 0
//The current instruction finishes, PC and status register are stored on the stack,
//then a new PC is loaded from the IRQ vector 
void CPU_6502::IRQ_HANDLER(){
  
  //clear status register except unused bit
  STATUS_REGISTER = 0x00 | UNUSED;

  //clear other registers
  A = 0x00;
  X = 0x00;
  Y = 0x00;



  //construct new PC from vecor 
  uint8_t lo = read(RESET_VECTOR);
  uint8_t hi = read(RESET_VECTOR + 1);
  PC = (hi << 8) | lo;

  //Set cycles 
  CYCLES++;

}

//Reset, basically just resets the CPU to a known state
//The status register is cleared except for the unused bit
//A new program counter is then read form the reset vector, which is 0xFFFC
void CPU_6502::RESET_HANDLER(){
  
  //clear status register except unused bit
  STATUS_REGISTER = 0x00 | UNUSED;

  //clear other registers
  A = 0x00;
  X = 0x00;
  Y = 0x00;



  //construct new PC from vecor 
  uint8_t lo = read(RESET_VECTOR);
  uint8_t hi = read(RESET_VECTOR + 1);
  PC = (hi << 8) | lo;

  //Set cycles 
  CYCLES++;

}

//Read a value from memory, this basically just calls the bus's read fucntion, which
//determines what region the CPU is access (stack, 2kb internal ram, etc)
uint8_t CPU_6502::read(uint16_t addr) {
  return B->read(addr);
}



//Write a value to memory, again, basically just calls the buses read function 
void write CPU_6502::write(uint16_t addr, uint8_t data){
  B->write(addr, data);
}


//Push a value onto the stack on page one
//I construct the address by just adding the stack pointer to the end of the first page
void push(uint8_t data){
  
  write(0x0100 + SP, data);
  SP--;


}


//Pull a value from the stack on page one
//I construct the address by just adding the stack pointer to the end of the first page
void pull(){
  
  SP++;
  uint8_t data = read(0x0100);
  return data;

}

//Helper function for setting flags TODO
void CPU_6502::SET_FLAG(STATUS value, bool condition){


  switch (value){

    case STATUS::CARRY:
      STATUS_REGISTER.FLAGS.CARRY = condition;

    case STATUS::ZERO:
      STATUS_REGISTER.FLAGS.ZERO = condition;

    case STATUS::INTERRUPT_DISABLE:
      STATUS_REGISTER.FLAGS.INTERRUPT_DISABLE = condition;

    case STATUS::DECIMAL:
      STATUS_REGISTER.FLAGS.DECIMAL = condition;

    case STATUS::OVERFLOW:
      STATUS_REGISTER.FLAGS.OVERFLOW = condition;

    case STATUS::NEGATIVE:
      STATUS_REGISTER.FLAGS.NEGATIVE = condition;
  }
    
}

