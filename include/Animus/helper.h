#ifndef HELPER
#define HELPER

#include <SDL2/SDL.h>
#include <stdlib.h>     /* srand, rand */

float toRad(float deg);
bool collision2D(SDL_Rect rect1, SDL_Rect rect2);
int rnd(int, int);

//random function
int rnd(int s){
    return rand() % s + 1;
}

struct Ship
{
    int x;
    int y;
    int speed;
    int vie;
    char sVie[5];
};

#endif