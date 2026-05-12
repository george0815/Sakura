#include "main.h"
#include "../CORE/BUS/bus.h"
#include "../CORE/CART/cart.h"
#include "../CORE/LOGGER/logger.h"
#include "./render.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_timer.h>
#include <cstdint>
#include <iostream>

using namespace std;

int main(int arc, char *argv[]) {

  if (!init_sdl()) {
    return -1;
  }

  const double TARGET_FRAME_MS = 1000.0 / 60.0988;

  CART cart;
  LOGGER *logger = new LOGGER(false);

  int test = PARSE_FILE("smb.nes", cart);
  // int test = PARSE_FILE("nestest.nes", cart);

  bus.insert_cartridge(cart);
  cpu.connect_bus(&bus);
  bus.connect_cpu(cpu);
  bus.connect_ppu(ppu);

  cpu.RESET_HANDLER();

  cpu.init_logger(logger);

  bool running = true;

  SDL_Event event;

  cout << "\nDONE" << endl;

  while (running) {

    uint64_t start = SDL_GetTicks64();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
      if (event.type == SDL_KEYDOWN) {
        // cout << "KEY PRESSED: " << event.key.keysym.sym;
        switch (event.key.keysym.sym) {
        case SDLK_a:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::A, true);
          break;
        case SDLK_b:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::B, true);
          break;
        case SDLK_s:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::SELECT, true);
          break;
        case SDLK_f:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::START, true);
          break;
        case SDLK_UP:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::UP, true);
          break;
        case SDLK_DOWN:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::DOWN, true);
          break;
        }
      } else if (event.type == SDL_KEYUP) {
        // cout << "KEY RELEASED: " << event.key.keysym.sym;
        switch (event.key.keysym.sym) {
        case SDLK_a:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::A, false);
          break;
        case SDLK_b:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::B, false);
          break;
        case SDLK_s:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::SELECT, false);
          break;
        case SDLK_f:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::START, false);
          break;
        case SDLK_UP:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::UP, false);
          break;
        case SDLK_DOWN:
          bus.SET_CONTROLLER_BUTTON(0, BUS::CONTROLLER_BUTTON::DOWN, false);
          break;
        }
      }
    }

    while (!ppu.FRAME_COMPLETE()) {
      cpu.step();
    }

    ppu.CLEAR_FRAME_FLAG();

    render_frame(ppu.FRAMEBUFFER_DATA());

    uint64_t elapsed = SDL_GetTicks64() - start;

    if (elapsed < TARGET_FRAME_MS) {
      SDL_Delay((uint32_t)TARGET_FRAME_MS - elapsed);
    }
  }
}
