
#ifndef FULL_TIME_H_
#define FULL_TIME_H_

#include "Main.h"

class Fulltime {
private:
    SDL_Surface* surface;
    SDL_Texture* texture;
    int x, y, width, height;


public:
    Fulltime(SDL_Renderer* renderer, int x, int y) {
        surface = IMG_Load("Image/fulltime.jpg");
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        this->x = x;
        this->y = y;
        width = surface->w;
        height = surface->h;

        SDL_FreeSurface(surface);
    }

    void draw(SDL_Renderer* renderer) {
        SDL_Rect destRect = { x, y, 700, 400 };
        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    }


};

#endif // !SCORE_H_

