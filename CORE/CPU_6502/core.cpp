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
  
  uint8_t data = read(0x0100);
  SP++;
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

