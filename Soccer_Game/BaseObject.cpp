/*
#include "Main.h"

class Circle {
private:
    int radius;
    int x, y;
    SDL_Renderer* renderer;

public:
    Circle(SDL_Renderer* rend, int xPos, int yPos, int r) : renderer(rend), x(xPos), y(yPos), radius(r) {}

    void draw() {
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

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
};

class Game {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;

public:
    Game() {
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);
        window = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        backgroundTexture = IMG_LoadTexture(renderer, "background.png");
    }

    void run() {
        bool quit = false;
        SDL_Event e;
        Circle circle(renderer, 400, 300, 50);  // Tạo đối tượng hình tròn

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                else if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                    case SDLK_a:
                        circle.move(-5, 0);
                        break;
                    case SDLK_d:
                        circle.move(5, 0);
                        break;
                    case SDLK_w:
                        circle.move(0, -5);
                        break;
                    case SDLK_s:
                        circle.move(0, 5);
                        break;
                    }
                }
            }
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
            circle.draw();
            SDL_RenderPresent(renderer);
        }
    }

    void cleanUp() {
        SDL_DestroyTexture(backgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
    }
};

int main(int argc, char* args[]) {
    Game game;
    game.run();
    game.cleanUp();

    return 0;
}
*/