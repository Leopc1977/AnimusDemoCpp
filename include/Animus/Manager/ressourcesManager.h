#ifndef RESSOURCESMANAGER
#define RESSOURCESMANAGER

#include <SDL2/SDL_mixer.h>

extern TTF_Font *PixelMaster;
extern SDL_Color color;
extern Mix_Music *coolMusique;
extern Mix_Music *technoMusique;

void Load_ressourcesManager();
void QuitApp_ressourcesManager();

#endif