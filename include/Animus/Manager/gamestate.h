#ifndef GAMESTATE
#define GAMESTATE

#include "animus/scenes/loadScene.h"

SDL_Renderer *renderer;

extern Scene currentScene;

void (*Update)(void);
void (*Draw)(void);
void (*Quit)(void);

void ChangeScene(char pScene[], SDL_Renderer * pRenderer);
void ChangeScene2(enumScene pScene, SDL_Renderer *pRenderer);

void Quit_GameState();

#endif