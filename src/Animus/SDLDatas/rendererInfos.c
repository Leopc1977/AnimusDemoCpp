#include <SDL2/SDL.h>

#include "animus/SDLInfos/rendererInfos.h"

int Index = -1;
int32_t rendererInitFlags=SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC;

RendererInfos _RendererInfos;

void Init_RendererInfos(){
    _RendererInfos.Index = Index;
    _RendererInfos.rendererInitFlags = rendererInitFlags;
}