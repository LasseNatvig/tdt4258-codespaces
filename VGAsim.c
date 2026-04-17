#include "VGAsim.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <signal.h>

// Define constants
const int VGA_MAX_X = 320;
const int VGA_MAX_Y = 240;
SDL_Window * window; 
SDL_Surface *screenSurface;
// Signal handler for making Ctrl+C work
volatile int running = 1;
void signal_handler() {
    running = 0;
}
void clearScreen(int c) {
  SDL_FillRect(screenSurface, NULL, color(c));
}
void drawRect(int x, int y, int width, int height,  Uint32 color) {
  SDL_Rect rect = {x, y, width, height};
  SDL_FillRect(screenSurface, &rect, color);
}
void updateVGA() {
    SDL_UpdateWindowSurface(window);  
}   
int color(int colorNo) {
    switch(colorNo) {
        case 0: return SDL_MapRGB(screenSurface->format, 0, 0, 0);       // Black   
        case 1: return SDL_MapRGB(screenSurface->format, 128, 128, 128); // Grey
        case 2: return SDL_MapRGB(screenSurface->format, 255, 0, 0);     // Red
        case 3: return SDL_MapRGB(screenSurface->format, 0, 255, 0);     // Green
        case 4: return SDL_MapRGB(screenSurface->format, 255, 255, 0);   // Yellow
        case 5: return SDL_MapRGB(screenSurface->format, 139, 69, 19);   // Brown
        case 6: return SDL_MapRGB(screenSurface->format, 0, 0, 255);     // Blue
        case 7: return SDL_MapRGB(screenSurface->format, 255, 255, 255); // White
        default: return SDL_MapRGB(screenSurface->format, 0, 0, 0);      // Default to black
    }
}
int initVGA() {
    window = NULL;   
    screenSurface = NULL;
    // Set up signal handler for Ctrl+C
    signal(SIGINT, signal_handler);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow("SDL simulated VGA (320x240 pix)", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    screenSurface = SDL_GetWindowSurface(window);
    return 0;     
}
void runVGA() {
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = 0;  // Exit the loop
            }
        }
        SDL_Delay(16); // Small delay to prevent high CPU usage
    }
    // Cleanup when exiting
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void bigPixel(int x, int y, int colorNo) {
    if ( (x < 0) || (x > 7) || (y < 0) || (y > 7) ) {
        printf("*** Error: Illegal parameters to bigPixel: ");
        printf("%d %d\n", x, y);
    } else {
        drawRect(x*BIG_PIXEL_SIZE, y*BIG_PIXEL_SIZE, BIG_PIXEL_SIZE, BIG_PIXEL_SIZE, color(colorNo));
    }
}

void setPixel(int x, int y, uint32_t color) {
  SDL_Rect rect = {x, y, 1, 1};
  SDL_FillRect(screenSurface, &rect, color);
}

void setPixel_safe(int x, int y, int c) {
    if ( (x < 0) || (x > VGA_MAX_X) || (y < 0) || (y > VGA_MAX_Y) ) {
        printf("*** Error: Illegal parameters to setPixel_safe: %d %d\n", x, y);
        return;
    } else {
        setPixel(x, y, color(c));
    }
}
