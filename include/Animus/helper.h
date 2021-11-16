#ifndef HELPER
#define HELPER

void PrintKeyInfo( SDL_KeyboardEvent *key );
float toRad(float deg);
bool collision2D(SDL_Rect rect1, SDL_Rect rect2);
int rnd(int, int);

struct Metetor
{
    int x;
    int y;
    int vX;
    int vY;
    int speed;
    bool bDraw;
};

struct Ship
{
    int x;
    int y;
    int speed;
    int vie;
    char sVie[5];
};

#endif