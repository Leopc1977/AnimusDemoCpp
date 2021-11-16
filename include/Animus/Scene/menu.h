#ifndef MENUSCENE
#define MENUSCENE

SDL_Renderer *rendererMenu;
SDL_Texture *texTxtMenu;
SDL_Rect dstSceneTxt; 

void Initialize_Menu(SDL_Renderer * pRenderer);
void LoadContent_Menu();
void Update_Menu();
void Draw_Menu();
void Quit_Menu();

#endif