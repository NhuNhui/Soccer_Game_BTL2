/*
#include "Main.h"
#include "BaseObject.h"
#include "BackGround.h"

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_VIDEO);

    Game game;
    game.loadAndRenderImage("Image/background.jpg", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.75);  // Thay đổi tỉ lệ hình ảnh
    game.loadAndRenderImage("Image/start.png", 400, 20, 840, 410, 0.5);

    game.loadAndRenderImage("Image/UCL.png", 250, 350, 700, 250, 1);


    SDL_Renderer* renderer = SDL_CreateRenderer(game.getWindow(), -1, SDL_RENDERER_ACCELERATED);

    Circle circle(renderer, 320, 240, 100);

    bool shouldRender = false;
    int x = 300, y = 300;

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_w) {
                    y -= 10;  // Di chuyển lên
                    shouldRender = true;
                }
                else if (e.key.keysym.sym == SDLK_s) {
                    y += 10;  // Di chuyển xuống
                    shouldRender = true;
                }
                else if (e.key.keysym.sym == SDLK_a) {
                    x -= 10;  // Di chuyển sang trái
                    shouldRender = true;
                }
                else if (e.key.keysym.sym == SDLK_d) {
                    x += 10;  // Di chuyển sang phải
                    shouldRender = true;
                }
            }
        }
        if (shouldRender) {
            // Xóa màn hình
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Màu trắng
            SDL_RenderClear(renderer);

            // Vẽ lại hình ảnh sau khi di chuyển
            game.loadAndRenderImage("Image/background.jpg", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.75);

            // Cập nhật màn hình
            SDL_RenderPresent(renderer);

            shouldRender = false;
        }
    }

    game.cleanUp();

    return 0;
}
*/

#include "Main.h"
#include "BackGround.h"

int main(int argc, char* args[]) {
    Game game;
    game.run();
    game.cleanUp();

    return 0;
}
