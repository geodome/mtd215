#include <iostream>
#include <SDL2/SDL.h>

#define TITLE "Chapter 00: MacOS Setup"
#define WIDTH 400
#define HEIGHT 400

/**
 * The main program creates a blank Window which closes
 */
 int main(int argc, char* argv[]) {
    // initialise SDL2
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << SDL_GetError() << std::endl;
        return 1;
    }
    // create a blank window
    SDL_Window* gWindow = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if(gWindow == nullptr) {
        std::cerr << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    // create renderer
    SDL_Renderer* gRenderer = SDL_CreateRenderer(gWindow,-1,0);
    if(gRenderer == nullptr) {
        std::cerr << SDL_GetError() << std::endl;
        SDL_DestroyWindow(gWindow);
        SDL_Quit();
        return 1;
    }

    // main loop
    bool quit = false;
    SDL_Event e;
    while(!quit) {
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                quit = true;
                break;
                default:
                break;
            }
        }
        // nothing to render since this is supposed to be a blanks screen;
        // 17ms delay means 60 fps animation
        SDL_Delay(17);
    }

    // clean up
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();

    return 0;
 
}