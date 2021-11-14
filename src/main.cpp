#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string>

#define SDL_ASSERT_LEVEL 2 //DEBUG

SDL_Texture* LoadTexture(SDL_Renderer *renderer, char *path)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, path);
    if(texture == NULL) {
        printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
        return NULL;
    }
    return texture;
}

int main(int argc, char *argv[])
{
    setvbuf (stdout, NULL, _IONBF, 0);
    printf("Start\n");

    int iGameWidth {1024},iGameHeight {768};

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Failed to initialise SDL\n");
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Animus Demo in C++!",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          iGameWidth,
                                          iGameHeight,
                                          SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        SDL_Log("Could not create a window: %s", SDL_GetError());
        return -1;
    }

    SDL_Renderer *renderer =
         SDL_CreateRenderer(window,
                            -1,
                            SDL_RENDERER_ACCELERATED |
                            SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        SDL_Log("Could not create a renderer: %s", SDL_GetError());
        return -1;
    }
    else
    {
        // Initialize PNG loading
        int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
        if(!(IMG_Init( imgFlags ) & imgFlags))
        {
            printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            return -1;
        }
    }

    //LOAD
    char* path = "./Ressources/Images/ship.png";
    SDL_Texture *img = LoadTexture(renderer, path);
    int w, h;
    SDL_QueryTexture(img, NULL, NULL, &w, &h);
    int x {100},y{100};
    int xSpeed {5},ySpeed {xSpeed};
    bool isRunning = true;

    //UPDATE
    while (isRunning)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
                break;
            }

            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        x+=xSpeed;
                        break;
                    case SDLK_LEFT:
                        x-= ySpeed;
                        break;
                    case SDLK_UP:
                        y-= ySpeed;
                        break;
                    case SDLK_DOWN:
                        y+= ySpeed;
                        break;
                    default:
                        break;  
                }
            }
        }

        SDL_RenderClear(renderer);

        //DRAW
        SDL_Rect rectDest = { x, y, w, h };
        SDL_RenderCopy(renderer, img, NULL, &rectDest);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(img);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}