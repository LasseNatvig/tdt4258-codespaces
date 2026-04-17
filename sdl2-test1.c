// sdl2-test1.c (Based in Mikkel codespaces)
//*****************************************************
#include <SDL2/SDL.h>
#include <stdio.h>
#include <signal.h>
#include "VGAsim.h"
void colorDemo() {
    clearScreen(7);
    for (int c = 0; c < 8; c++) {
        bigPixel(c, c, c);
    }
}

int main() {
  if (initVGA() != 0) {
      return 1;
  }

//   clearScreen(7); // white is 7
//   drawRect(100, 100, 100, 100, SDL_MapRGB(screenSurface->format, 0, 0, 0));
//   updateVGA();
  clearScreen(7); // white is 7
  colorDemo();
  updateVGA();
  
  runVGA();   // Run the main loop
  return 0;
}   