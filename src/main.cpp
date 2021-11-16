#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include <stdlib.h>     /* srand, rand */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string>
#include <iostream>

#define SDL_ASSERT_LEVEL 2 //DEBUG

bool isCol(int x1,int y1,int w1,int h1, int x2,int y2,int w2,int h2){
  return x1 < x2+w2 &&
         x2 < x1+w1 &&
         y1 < y2+h2 &&
         y2 < y1+h1;
}
//random function
int rnd(int s){
    return rand() % s + 1;
}

class Meteor
{
    public:
        Meteor(int pX=10,int pY=10){
            x = pX;
            y= pY;
            speedX = rnd(5);
            speedY = rnd(5);
        }
        int getX() {return x;}
        int getY() {return y;}
        void setX(int pX) {x = pX;}
        void setY(int pY) {y = pY;}
        int getW() {return w;}
        int getH() {return h;}
        int getSpeedX(){return speedX;}
        int getSpeedY(){return speedY;}
        void setSpeedX(){speedX=speedX*(-1);}
        void setSpeedY(){speedY=speedY*(-1);}
    private:
        int x,y,w,h,speedX,speedY;
};

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
    bool isRunning = true;

    char* shipPath {"./Ressources/Images/ship.png"};
    SDL_Texture *shipTex {LoadTexture(renderer, shipPath)};
    int shipWidth, shipHeight;
    SDL_QueryTexture(shipTex, NULL, NULL, &shipWidth, &shipHeight);
    int x {100},y{100};
    int xSpeed {5},ySpeed {xSpeed};

    char* pathMeteor {"./Ressources/Images/meteor.png"};
    SDL_Texture *meteorImg {LoadTexture(renderer, pathMeteor)};
    int meteorWidth, meteorHeight;
    SDL_QueryTexture(meteorImg, NULL, NULL, &meteorWidth, &meteorHeight);

    //INPUT
    bool up,left,right,down {false};

    Meteor m1 {50,50};
    int const lenMCst = 10;
    int lenM = lenMCst;
    Meteor lstM [lenMCst];

    for (int i=0;i<lenM;i++){
        lstM[i].setX(rnd(iGameWidth)-meteorWidth);
        lstM[i].setY(rnd(iGameHeight)-meteorHeight);
    }

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

            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        right = true;
                        break;
                    case SDLK_LEFT:
                        left = true;
                        break;
                    case SDLK_UP:
                        up = true;
                        break;
                    case SDLK_DOWN:
                        down = true;
                        break;
                    default:
                        break;  
                }
            }
            if (event.type == SDL_KEYUP)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        right = false;
                        break;
                    case SDLK_LEFT:
                        left = false;
                        break;
                    case SDLK_UP:
                        up = false;
                        break;
                    case SDLK_DOWN:
                        down = false;
                        break;
                    default:
                        break;  
                }
            }
        }

        //MOVE
        if (left){
            x-=xSpeed;
        }
        if (right){
            x+=xSpeed;
        }
        if (up){
            y-=ySpeed;
        }
        if (down){
            y+=ySpeed;
        }

        SDL_RenderClear(renderer);

        //DRAW
        for (int i=lenM-1;i>=0;i--){
            int mX {lstM[i].getX()};
            int mY {lstM[i].getY()};
            
            if (mX<0 || mX>iGameWidth){lstM[i].setSpeedX();}
            if (mY<0 || mY>iGameHeight){lstM[i].setSpeedY();}

            lstM[i].setX(mX+lstM[i].getSpeedX());
            lstM[i].setY(mY+lstM[i].getSpeedY());

            Meteor m = lstM[i];
            SDL_Rect rectDest = { mX, mY, meteorWidth, meteorHeight};
            SDL_RenderCopy(renderer, meteorImg, NULL, &rectDest);

            //collision
            bool col {isCol(x,y,shipWidth,shipHeight,mX,mY,meteorWidth,meteorHeight)};
            if (col) {
                if (lenM !=0){
                    for (int k=i; k < lenM-1; ++k){
                        lstM[i] = lstM[i+1];
                    }
                    lenM-=1;
                }
            }

        }
        SDL_Rect rectDest = { x, y, shipWidth, shipHeight };
        SDL_RenderCopy(renderer, shipTex, NULL, &rectDest);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(shipTex);
    SDL_DestroyTexture(meteorImg);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}