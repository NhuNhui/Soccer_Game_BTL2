
#ifndef SCORE_H_
#define SCORE_H_

#include "Main.h"

class Score {
private:
    SDL_Surface* surface;
    SDL_Texture* texture;
    int x, y, width, height;


public:
    Score(SDL_Renderer* renderer, const char* imagePath, int x, int y) {
        surface = IMG_Load(imagePath);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        this->x = x;
        this->y = y;
        width = surface->w;
        height = surface->h;

        SDL_FreeSurface(surface);
    }

    void draw(SDL_Renderer* renderer) {
        SDL_Rect destRect = { x, y, 400, 55 };
        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    }


};

#endif // !SCORE_H_
