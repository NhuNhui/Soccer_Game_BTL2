
#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "Main.h"
#include "Player.h"
#include "Ball.h"

class Game {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;

public:
    Game() {
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);
        window = SDL_CreateWindow("Game", 100, 100, SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.75, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        backgroundTexture = IMG_LoadTexture(renderer, san1);
    }

    void run() {
        bool quit = false;
        SDL_Event e;

        Player player1_team_one(renderer, 100, 340, 15);  // Tạo đối tượng hình tròn
        Player player2_team_one(renderer, 300, 200, 15);
        Player player3_team_one(renderer, 300, 480, 15);
        Player player4_team_one(renderer, 400, 400, 15);
        Player player5_team_one(renderer, 470, 270, 15);

        //giữa sân: 600, 340

        Player player1_team_two(renderer, 1100, 340, 15);
        Player player2_team_two(renderer, 900, 480, 15);
        Player player3_team_two(renderer, 900, 200, 15);
        Player player4_team_two(renderer, 800, 280, 15);
        Player player5_team_two(renderer, 730, 410, 15);

        Ball ball(renderer, ball_path, 600-20, 340-20);

        int move = 10;
        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                /*else if (e.type == SDL_KEYDOWN) {
                    switch (e.key.keysym.sym) {
                    case SDLK_a:
                        circle.move(-move, 0);
                        break;
                    case SDLK_d:
                        circle.move(move, 0);
                        break;
                    case SDLK_w:
                        circle.move(0, -move);
                        break;
                    case SDLK_s:
                        circle.move(0, move);
                        break;
                    }
                }*/
            }
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

            //vẽ cầu thủ
            player1_team_one.drawRed();
            player2_team_one.drawRed();
            player3_team_one.drawRed();
            player4_team_one.drawRed();
            player5_team_one.drawRed();

            player1_team_two.drawBlue();
            player2_team_two.drawBlue();
            player3_team_two.drawBlue();
            player4_team_two.drawBlue();
            player5_team_two.drawBlue();
            
            // vẽ quả bóng
            ball.draw(renderer);

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

#endif