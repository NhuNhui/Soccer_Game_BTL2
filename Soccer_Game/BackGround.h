
#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "Main.h"
#include "Player.h"
#include "Ball.h"
#include "Score.h"
#include "Goal.h"
#include "fulltime.h"

class Game {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;
    SDL_Texture* textTexture;

    TTF_Font* font;
    SDL_Color textColor;

public:
    Game() {
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);
        SDL_Init(SDL_INIT_AUDIO);
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        TTF_Init();

        window = SDL_CreateWindow("Game", 100, 100, int(SCREEN_WIDTH * 0.75), int(SCREEN_HEIGHT * 0.75), SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        backgroundTexture = IMG_LoadTexture(renderer, san1);
        
        font = TTF_OpenFont("Font/ARIBL0.ttf", 30);
        textColor = { 0, 0, 0, 0 };

        
    }

    void drawScore(int score1,int score2) {
        std::string scoreText = std::to_string(score1) + "-" + std::to_string(score2);
        

        SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface); 

        SDL_Rect textRect;
        textRect.x = 545;
        textRect.y = -5;
        textRect.w = 100;
        textRect.h = 70;
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    }
    void drawTimer(int timer) {
        std::string scoreText = std::to_string(timer) + " : 00";


        SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), { 255, 255, 255, 255 });
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);

        SDL_Rect textRect;
        textRect.x = 900;
        textRect.y = -2;
        textRect.w = 140;
        textRect.h = 70;
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    }
    void drawScoreFulltime(int score1, int score2) {
        std::string scoreText = std::to_string(score1) + "    " + std::to_string(score2);


        SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);

        SDL_Rect textRect;
        textRect.x = 380;
        textRect.y = 350;
        textRect.w = 450;
        textRect.h = 200;
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    }

    void run() {
        bool quit = false;
        SDL_Event e;
        Mix_Music* sound_bg = Mix_LoadMUS("Sound/sound_san.mp3");
        Mix_Music* sound_coi = Mix_LoadMUS("Sound/coi.mp3");
       
        Player player_team_one(renderer, 400, 340, 40);  // Tạo đối tượng hình tròn
      
        
        //giữa sân: 600, 340

        Player player_team_two(renderer, 800, 340, 40);

        Ball ball(renderer, ball_path, 600-20, 340-20);
        Fulltime fulltime(renderer, 600 - 350, 340 - 200);

        int R_ball = 15;
        
        int move = 100;
        int x_move = 1;
        int y_move = 2;

        int score1 = 0;
        int score2 = 0;
        Score bg(renderer, score_path, 400,5);
        Goal goal(renderer, goal_path, 600-250, 340-250);
        Uint32 startTime = SDL_GetTicks();
        int timer = 90;
        bool is_goal = false;
        bool team_1_goal = false;
        bool team_2_goal = false;
        bool display_goal = false;
        Mix_PlayMusic(sound_bg, -1);

        while (!quit) {
            
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                else if (e.type == SDL_KEYDOWN) {       
                    
                    switch (e.key.keysym.sym) {
                    case SDLK_a:
                        player_team_one.move(-move, 0);
                        break;
                    case SDLK_d:
                        player_team_one.move(move, 0);
                        break;
                    case SDLK_w:
                        player_team_one.move(0, -move);
                        break;
                    case SDLK_s:
                        player_team_one.move(0, move);
                        break;
                    case SDLK_UP:
                        player_team_two.move(0, -move);
                        break;
                    case SDLK_DOWN:
                        player_team_two.move(0, move);
                        break;
                    case SDLK_LEFT:
                        player_team_two.move(-move, 0);
                        break;
                    case SDLK_RIGHT:
                        player_team_two.move(move, 0);
                        break;
                    }

                    
                    //std::cout << "x: " << ball.get_x() << ", y: " << ball.get_y() << "\n";
                }
                else if (e.type == SDL_MOUSEBUTTONDOWN) {
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    // Hiển thị tọa độ vị trí chuột
                    // printf("Toa do mouse: (%d, %d)\n", mouseX, mouseY);
                }
                
                
            }
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
            Uint32 currentTime = SDL_GetTicks();
            if (currentTime - startTime >= 1000) { // 1000 miliseconds = 1 second
                // Thực hiện hành động sau mỗi 1s ở đây
                timer--;
                startTime = currentTime;
                if (timer % 3 == 0) {
                    if (x_move < 0)
                        x_move--;
                    else
                        x_move++;
                    if (y_move < 0)
                        y_move--;
                    else
                        y_move++;
                }
            }

            //vẽ cầu thủ
            
            player_team_one.drawBlue();
            player_team_two.drawRed();

            
            ball.move(x_move, y_move);
            // di chuyển quả bóng
            /*if (ball.get_x() >= 75 && ball.get_x() <= 1125 && ball.get_y() <= 595 && ball.get_y() >= 80)
                */

            //phản xạ khi gặp 4 góc sân
            if (ball.get_x() <= 75 + 15 && ball.get_y() >= 290 && ball.get_y() <= 385) { //team2 ghi bàn
                is_goal = true;
                score2++;
                team_2_goal = true;
                display_goal = true;
                
            }
            else if (ball.get_x() >= 1125 - 15 && ball.get_y() >= 290 && ball.get_y() <= 385) { //team1 ghi bàn
                is_goal = true;
                score1++;
                team_1_goal = true;
                display_goal = true;
            }
            else if (ball.get_y() >= 610 - 15) {
                y_move = -y_move;
            }                
            else if (ball.get_y() <= 65 + 15) {
                y_move = -y_move;
            }
            else if (ball.get_x() < 75 + 15) {
                x_move = -x_move;
            }
            else if (ball.get_x() > 1125 - 15) {
                x_move = -x_move;
            }
            //phản xạ khi gặp cầu thủ 
            int x_ball = ball.get_x();
            int y_ball = ball.get_y();

            if (distance_point_to_point(x_ball, y_ball, player_team_one.get_x(), player_team_one.get_y()) <= 50) {
                int x = player_team_one.get_x();
                int y = player_team_one.get_y();
                if (x - 50 < x_ball && x + 50 > x_ball) {
                    y_move = -y_move;
                }
                else {
                    x_move = -x_move;
                }

            }
            if (distance_point_to_point(x_ball, y_ball, player_team_two.get_x(), player_team_two.get_y()) <= 50) {
                int x = player_team_two.get_x();
                int y = player_team_two.get_y();
                if (x - 50 < x_ball && x + 50 > x_ball) {
                    y_move = -y_move;
                }
                else {
                    x_move = -x_move;
                }

            }

            
            
            if (timer > 0) {
                bg.draw(renderer);
                ball.draw(renderer);
                drawScore(score1, score2);
                drawTimer(timer);
            }
            else {
                Mix_PlayMusic(sound_coi, 0);
                fulltime.draw(renderer);
                drawScoreFulltime(score1, score2);
                x_move = 0;
                y_move = 0;
            }
            //goal.draw(renderer);
                

            bool delay = false;
            
            if (is_goal && timer > 0) {
                
                goal.draw(renderer);

                
                
                ball.set_x(600 - 20);
                ball.set_y(340 - 20);
                if (team_1_goal) {
                    x_move = 1;
                    team_1_goal = false;
                }
                if (team_2_goal) {
                    x_move = -1;
                    team_2_goal = false;
                }
                
                y_move = 3;
                is_goal = false;
                delay = true;
                
            }
            
            

            SDL_RenderPresent(renderer);

            if (delay) {
                Mix_Music* Music = Mix_LoadMUS("Sound/goal.mp3");
                Mix_PlayMusic(Music, 0);
                SDL_Delay(4000);

                Mix_FreeMusic(Music);
                delay = false;
                Mix_PlayMusic(sound_bg, -1);
            }
        }
    }

    void cleanUp() {
        SDL_DestroyTexture(backgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        TTF_CloseFont(font);
        TTF_Quit();
    }
};

#endif