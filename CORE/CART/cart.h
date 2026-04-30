#pragma once 
#include <string>
#include "../BUS/bus.h"


//main class for a cartridge

class CART {

  public:
   
    bool HAS_TRAINER();

    //The bus, the PRGROM data will be passed to the bus
    BUS* B;  
    
    
    //Reads file and maps data to a CART object 
    void PARSE_CART(std::string filename);

  private:


    //Parses first 4 bytes (bytes 0-3), in the iNES format this should be the ASCII codes for "NES", followed by the MSDOS EOF
    bool IS_VALID_NES_ROM();


    





};
