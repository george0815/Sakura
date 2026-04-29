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


 

//Helper function for setting flags TODO
void CPU_6502::SET_FLAG(){

}

