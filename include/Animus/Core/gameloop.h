#ifndef GAMELOOP 
#define GAMELOOP

#include <SDL2/SDL.h>

SDL_Renderer *GameloopRenderer;

void Init_Gameloop();
void Gameloop(SDL_Renderer *pRenderer, SDL_Event pEvent);
void Quit_Gameloop();

#endif