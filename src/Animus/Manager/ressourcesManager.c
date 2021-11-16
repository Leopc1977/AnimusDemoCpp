#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <stdio.h>

#include "animus/manager/ressourcesManager.h"

TTF_Font* PixelMaster = NULL;
SDL_Color color={255,255,255};

Mix_Music *coolMusique = NULL;
Mix_Music *technoMusique = NULL;

void Load_ressourcesManager(){
    //FONT
    PixelMaster = TTF_OpenFont("src/ressources/font/PixelMaster.ttf", 24);
    if (PixelMaster == NULL) {
        printf("Failed to load font: %s \n", TTF_GetError());
    }
    
    //SOUND
    coolMusique = Mix_LoadMUS("src/ressources/sound/cool.mp3");
    if (coolMusique == NULL) {
        printf("Failed to load coolMusique: %s \n", Mix_GetError());
    }
    technoMusique = Mix_LoadMUS("src/ressources/sound/techno.mp3");
    if (technoMusique == NULL) {
        printf("Failed to load technoMusique: %s \n", Mix_GetError());
    }
}

void QuitApp_ressourcesManager(){
    TTF_CloseFont(PixelMaster); 

    Mix_FreeMusic(coolMusique);
    Mix_FreeMusic(technoMusique);
}