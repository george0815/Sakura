#include <cstdint>
class core {

public:
  // 2 byte program counter, holds the address of the next opcode to be executed
  uint16_t PC = 0x0000;

  // 1 byte X register
  uint8_t X = 0x00;

  // 1 byte Y register
  uint8_t Y = 0x00;

  // 1 byte accumulator, uses the status register for carries, overflow
  // detection, etc
  uint8_t A = 0x00;

  // 1 byte stack pointer, accessed using interupts
  uint8_t SP = 0x00;

  // status register, I'm implementing it as a union so I can access specific
  // bits (using the struct inside) or it as a whole using the uint8_t
  union STATUS_REGISTER {

    uint8_t TOTAL_VALUE;
    struct FLAGS {

      uint8_t CARRY : 1;
      uint8_t ZERO : 2;
      uint8_t INTERRUPTDISABLE : 3;
      uint8_t DECIMAL : 4;
      uint8_t OVERFLOW : 7;
      uint8_t NEGATIVE : 8;
    };
  };
};
