#ifndef MAIN_H_
#define MAIN_H_

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const char* UCL = "Image/UCL";
const char* background = "Image/background";
const char* san1 = "Image/San1.jpg";
const char* ball_path = "Image/ball.png";

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

const int RENDER_DRAW_COLOR = 0XFF;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;



#endif // !MAIN_H_

