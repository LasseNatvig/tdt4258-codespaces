// VGAsim.h

#include <SDL2/SDL.h>
#include <stdio.h>
#include <signal.h>

// Declare external variables
extern volatile int running;
extern const int VGA_MAX_X;
extern const int VGA_MAX_Y;
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define BIG_PIXEL_SIZE 30

int initVGA();
void runVGA();
void drawRect(int x, int y, int width, int height,  Uint32 color);
void clearScreen(int color);
int color(int c);
void updateVGA();
void bigPixel(int x, int y, int color);
void setPixel(int x, int y, uint32_t color);
void setPixel_safe(int x, int y, int c);
