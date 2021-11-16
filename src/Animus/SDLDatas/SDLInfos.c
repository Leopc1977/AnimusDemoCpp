#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <stdbool.h>

#include "animus/SDLInfos/SDLInfos.h"

int32_t SDLInitFlags = SDL_INIT_EVERYTHING;

int frequency = 44100;
int16_t format = MIX_DEFAULT_FORMAT;
int channels = 2;
int chunksizes = 2048;

bool showCursor = true;

SDLInfos _SDLInfos;

void Init_SDLInfos(){
    _SDLInfos.SDLInitFlags = SDLInitFlags;
    _SDLInfos.frequency = frequency;
    _SDLInfos.format = format;
    _SDLInfos.channels = channels;
    _SDLInfos.chunksizes = chunksizes;
    _SDLInfos.showCursor = showCursor;
}