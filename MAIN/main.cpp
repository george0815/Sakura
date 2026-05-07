#include "main.h"
#include "../CORE/CART/cart.h"

#include <iostream>

using namespace std;

int main(int arc, char *argv[]) {

  CART cart;

  int test = PARSE_FILE("nestest.nes", cart);

  bus.insert_cartridge(cart);
  bus.connect_cpu(cpu);
  bus.connect_ppu(ppu);
  cpu.connect_bus(&bus);
  cpu.RESET_HANDLER();

  cout << "\nDONE" << endl;

  for (int i = 0; i < 100; i++) {
    bus.step();
  }
}
