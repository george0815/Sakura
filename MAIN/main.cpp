#include "main.h"
#include "../CORE/CART/cart.h"

int main(int arc, char *argv[]) {

  CART cart;

  bus.insert_cartridge(cart);
  bus.connect_cpu(cpu);
  cpu.connect_bus(&bus);
  cpu.RESET_HANDLER();
}
