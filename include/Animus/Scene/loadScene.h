#ifndef LOADSCENE
#define LOADSCENE

#include "animus/scenes/scene.h"

extern struct Scene lstScene [];

typedef enum {
    MENU, GAME, GAMEOVER
} enumScene;

extern enumScene eScene;

void LoadScene();

#endif