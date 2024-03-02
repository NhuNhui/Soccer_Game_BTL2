#ifndef PLAYER_H_
#define PLAYER_H_

#include "Main.h"

class Player {
private:
    int radius;
    int x, y;
    SDL_Renderer* renderer;

public:
    

    Player(SDL_Renderer* rend, int xPos, int yPos, int r) : renderer(rend), x(xPos), y(yPos), radius(r) {}

    void drawRed() {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Màu đỏ
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w;
                int dy = radius - h;
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    SDL_RenderDrawPoint(renderer, x + dx, y + dy);
                }
            }
        }
    }

    void drawBlue() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Màu xanh
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w;
                int dy = radius - h;
                if ((dx * dx + dy * dy) <= (radius * radius)) {
                    SDL_RenderDrawPoint(renderer, x + dx, y + dy);
                }
            }
        }
    }

    void move(int dx, int dy) {
        if(x + dx > 75 && x + dx < 1125)
            x += dx;
        if(y + dy > 65 && y + dy < 610)
            y += dy;
    }

    void set_x(int x) {
        this->x = x;
    }

    int get_x() {
        return this->x;
    }

    void set_y(int y) {
        this->y = y;
    }
    int get_y() {
        return this->y;
    }
};


#endif // !PLAYER_H_

