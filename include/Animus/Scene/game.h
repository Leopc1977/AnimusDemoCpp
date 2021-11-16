#ifndef GAMESCENE
#define GAMESCENE

SDL_Texture *texGameTxt;
SDL_Rect dstSceneTxt; 

SDL_Texture *texShip;
SDL_Rect dstShip;

int iLanderX, iLanderY;

float deltaTime;

void Initialize_Game(SDL_Renderer * pRenderer);
void LoadContent_Game();
void Update_Game();
void Draw_Game();
void Quit_Game();
#endif