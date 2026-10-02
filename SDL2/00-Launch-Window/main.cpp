// this program lauunched a window with white background

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

    SDL_Surface* gSurface = SDL_GetWindowSurface(gWindow);
    if(gSurface == nullptr) {
        std::cerr << SDL_GetError() << "\n";
        return 1;
    }

    // White background color
    uint32_t bgcolor = SDL_MapRGB(gSurface->format, 0xff, 0xff, 0xff);

    // The main loop consists of
    // * event loop

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
        // fill the window with white color
        // when rect is set as nullptr, SDL_FilLRect() updates the entire surface instead of the rectangular region defined by rect

        SDL_FillRect(gSurface, nullptr, bgcolor);
        SDL_UpdateWindowSurface(gWindow);

        // Sleep phase
        // This determines the refresh rate
        // For refresh rate of 60fps, 1000ms/60fps = 17ms per frame
        SDL_Delay(17);
    }

    // Begin cleanup
    SDL_DestroyWindow(gWindow);

    return 0;
}