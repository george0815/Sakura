
#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 240;
const int SCALE = 3;

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;

bool init_sdl();

void render_frame(const array<uint32_t, 256 * 240> &framebuffer);
