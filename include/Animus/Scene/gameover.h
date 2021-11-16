#ifndef GAMEOVERSCENE
#define GAMEOVERSCENE

SDL_Texture *texGameoverTxt;
SDL_Rect dstGameoverTxt; 

void Initialize_Gameover(SDL_Renderer * pRenderer); 
void LoadContent_Gameover();
void Update_Gameover(void);
void Draw_Gameover();
void Quit_Gameover();
#endif