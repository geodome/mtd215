// this program lauunched a window with white background
// This example uses gRenderer instead of gSurface

#include <SDL2/SDL.h>
#include <iostream>

#define TITLE "First SDL App"
#define WIDTH 800
#define HEIGHT 600
#define WHITE {0xff, 0xff, 0xff, 0xff}

// SDL2 requires this version of the main() function. It won't work with the int main() version.
int main(int argc, char* argv[]) {

    // First initialise SDL2 subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        // SD_Init() returns 0 if successful
        std::cerr << SDL_GetError() << "\n";
        // By convention, main() returns non-zero value if error happens
        return 1;
    }

    // SDL_CreateWindow() returns null pointer if error
    // the flags parameter is set 0, so no window flag is turned on.
    SDL_Window* gWindow = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if(gWindow == nullptr) {
        std::cerr << SDL_GetError() << "\n";
        return 1;
    }

    
    SDL_Renderer* gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    if(gRenderer == nullptr) {
        std::cerr << SDL_GetError() << "\n";
        return 1;
    }

    // initial render white background
    SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff); // set color
    SDL_RenderClear(gRenderer); // clear the window
    SDL_RenderPresent(gRenderer); // print the image data to the display

    bool quit = false;
    SDL_Event e;
    while(!quit) {
        // The event loop polls the event queue for GUI events.
        // responsible for assigning event handlers
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                quit = true;
                std::cout << "quit event triggered\n";
                break;
            }
        }

        // update phase
        // The update phase is empty because there are no graphical objects to update

        // render phase
        // empty because there is nothing to render
        
        // Sleep phase
        // This determines the refresh rate
        // For refresh rate of 60fps, 1000ms/60fps = 17ms per frame
        SDL_Delay(17);
    }

    // Begin cleanup
    SDL_DestroyWindow(gWindow);

    return 0;
}