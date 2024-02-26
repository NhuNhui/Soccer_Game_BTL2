#ifndef BALL_H_
#define BALL_H_

#include "Main.h"

class Ball {
private:
    SDL_Surface* surface;
    SDL_Texture* texture;
    int x, y, width, height;

public:
    Ball(SDL_Renderer* renderer, const char* imagePath, int x, int y) {
        surface = IMG_Load(imagePath);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        this->x = x;
        this->y = y;
        width = surface->w;
        height = surface->h;
        SDL_FreeSurface(surface);
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void draw(SDL_Renderer* renderer) {
        SDL_Rect destRect = { x, y, 40, 40 };
        SDL_RenderCopy(renderer, texture, NULL, &destRect);
    }

};

#endif // !BALL_H_