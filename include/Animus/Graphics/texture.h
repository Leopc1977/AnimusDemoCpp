#ifndef RENDER 
#define RENDER 

SDL_Texture *LoadTexture(SDL_Renderer *renderer, char *path);
SDL_Texture *LoadFont(SDL_Renderer *renderer, TTF_Font *font, char text[], SDL_Color color);

#endif