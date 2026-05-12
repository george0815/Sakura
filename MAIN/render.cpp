#include "./render.h"
#include <SDL2/SDL.h>
#include <cstddef>
#include <cstdint>
#include <iostream>

using namespace std;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
SDL_Texture *texture = nullptr;

bool init_sdl() {

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
    cout << SDL_GetError() << endl;
    return false;
  }

  window = SDL_CreateWindow("sakura", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH * SCALE,
                            SCREEN_HEIGHT * SCALE, SDL_WINDOW_SHOWN);

  if (!window) {
    cout << SDL_GetError() << endl;
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    cout << SDL_GetError() << endl;
    return false;
  }

  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                              SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH,
                              SCREEN_HEIGHT);

  if (!texture) {
    cout << SDL_GetError() << endl;
    return false;
  }

  return true;
}

void render_frame(const array<uint32_t, 256 * 240> &framebuffer) {

  SDL_UpdateTexture(texture, nullptr, framebuffer.data(),
                    SCREEN_WIDTH * sizeof(uint32_t));

  SDL_RenderClear(renderer);

  SDL_RenderCopy(renderer, texture, nullptr, nullptr);

  SDL_RenderPresent(renderer);
}
