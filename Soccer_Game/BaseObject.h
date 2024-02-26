#ifndef BASIC_OBJECT_H_
#define BASIC_OBJECT_H_

#include "Main.h"

class Circle {
private:
    int centerX;
    int centerY;
    int radius;
    SDL_Renderer* renderer;

public:
    Circle(SDL_Renderer* renderer, int x, int y, int r) : renderer(renderer), centerX(x), centerY(y), radius(r) {}

    void draw() {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Màu trắng
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w; // Tính khoảng cách từ tâm đến điểm đang xét
                int dy = radius - h; // Tính khoảng cách từ tâm đến điểm đang xét
                if ((dx * dx + dy * dy) <= (radius * radius)) { // Kiểm tra nếu điểm đang xét nằm trong hình tròn
                    SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
                }
            }
        }
    }
};


#endif


