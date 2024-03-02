#ifndef MAIN_H_
#define MAIN_H_

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const char* UCL = "Image/UCL";
const char* background = "Image/background";
const char* san1 = "Image/San1.jpg";
const char* ball_path = "Image/ball.png";
const char* score_path = "Image/black.jpg";
const char* goal_path = "Image/Goal.png";

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

const int RENDER_DRAW_COLOR = 0XFF;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

int distance_point_to_line(int x0, int y0, int A, int B, int C) {
	return int((A * x0 + B * y0 + C) / sqrt(A * A + B * B));
}

int distance_point_to_point(int x1, int y1, int x2, int y2) {
	int div_x = abs(x1 - x2);
	int div_y = abs(y1 - y2);

	return int(sqrt(div_x * div_x + div_y * div_y));
}

#endif // !MAIN_H_

