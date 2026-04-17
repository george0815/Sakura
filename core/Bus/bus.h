#include <cstdint>
class Bus {

public:
  uint8_t read(uint16_t addr);
  void write(uint16_t addr, uint8_t data);
  uint8_t peek(uint16_t addr);

  void connect_cart(); // stub for later

  void connect_cpu(); // stub for later
  void connect_ppu(); // stub for later
};
