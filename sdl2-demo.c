#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

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

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow("Black Square Demo", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  screenSurface = SDL_GetWindowSurface(window);

  // Fill the screen with white
  clearScreen(screenSurface);

  // Draw a black square in the center of the screen
  drawRect(screenSurface, 100, 100, 100, 100,
           SDL_MapRGB(screenSurface->format, 0, 0, 0));

  SDL_UpdateWindowSurface(window);

  SDL_Event e;
  while (1) {
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