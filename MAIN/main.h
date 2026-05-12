#pragma once

#include "../CORE/BUS/bus.h"
#include "../CORE/CART/cart.h"
#include "../CORE/CPU_6502/core.h"
#include <SDL2/SDL_audio.h>
#include <cstdint>
#include <deque>
#include <mutex>

BUS bus;
CPU_6502 cpu;
PPU_2C02 ppu;

deque<int16_t> AUDIO_QUEUE;
mutex AUDIO_MUTEX;
SDL_AudioDeviceID AUDIO_DEVICE;

const uint32_t TARGET_AUDIO_LATENCY_MS = 40;

const uint32_t BYTES_PER_SAMPLE = sizeof(int16_t);
const uint32_t TARGET_QUEUE_BYTES =
    (44100 * TARGET_AUDIO_LATENCY_MS / 1000) * BYTES_PER_SAMPLE;
