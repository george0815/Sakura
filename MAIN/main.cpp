#include "../CORE/CART/cart.h"
#include "main.h"


int main(int arc, char* argv[]){

  bus.insert_cartridge(cart);
  bus.connect_cpu(&cpu);
  cpu.connect_bus(&bus);
  cpu.reset();

  
}
