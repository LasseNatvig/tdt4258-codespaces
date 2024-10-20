#include <SDL2/SDL.h>
#include <stdio.h>
#include <signal.h>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

// Signal handler for making Ctrl+C work
volatile int running = 1;
void signal_handler(int signum) {
    running = 0;
}

void clearScreen(SDL_Surface *surface) {
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
}

void drawRect(SDL_Surface *surface, int x, int y, int width, int height,
              Uint32 color) {
  SDL_Rect rect = {x, y, width, height};
  SDL_FillRect(surface, &rect, color);
}

int main(int argc, char *argv[]) {
  SDL_Window *window = NULL;
  SDL_Surface *screenSurface = NULL;

  // Set up signal handler for Ctrl+C
  signal(SIGINT, signal_handler);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow("TDT4258 SDL Aanimation Demo", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  screenSurface = SDL_GetWindowSurface(window);

  // Fill the screen with white
  clearScreen(screenSurface);

  for (int i = 0; i < 200; i++) {
    drawRect(screenSurface, i,       i,       100, 100, SDL_MapRGB(screenSurface->format, 255, 0, 0)); 
    drawRect(screenSurface, i + 100, i + 100, 100, 100, SDL_MapRGB(screenSurface->format, 0, 0, 0));
    drawRect(screenSurface, i + 150, i + 150, 100, 100, SDL_MapRGB(screenSurface->format, 0, 255, 0));
    drawRect(screenSurface, 250 - i, 150 - i, 50, 50, SDL_MapRGB(screenSurface->format, 0, 0, 255));
    
    SDL_UpdateWindowSurface(window);
    SDL_Delay(100);
  }

  SDL_Event e;
  while (running) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        break;
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}