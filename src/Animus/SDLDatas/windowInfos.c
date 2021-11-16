#include <SDL2/SDL.h>

#include "animus/SDLInfos/WindowInfos.h"

int iScreenWidth = 1024, iScreenHeight = 768;

int x = SDL_WINDOWPOS_UNDEFINED;
int y = SDL_WINDOWPOS_UNDEFINED;

int32_t windowInitFlags = SDL_WINDOW_SHOWN;

WindowInfo _WindowInfo;

void Init_WindowInfos(){
    _WindowInfo.windowInitFlags = windowInitFlags;
    _WindowInfo.x = x;
    _WindowInfo.y = y;
    _WindowInfo.iScreenWidth = iScreenWidth;
    _WindowInfo.iScreenHeight = iScreenHeight;
}