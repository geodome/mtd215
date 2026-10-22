#include <SDL2/SDL.h>
#include <iostream>

#define TITLE "Load Picture"
#define WIDTH 800
#define HEIGHT 600
#define WHITE {0xff, 0xff, 0xff, 0xff}
#define BLACK {0x00, 0x00, 0x00, 0xff}
#define UNIT 10

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << SDL_GetError() << "\n";
        return 1;
    };

    SDL_Window* gWindow = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if(gWindow == nullptr) {
        std::cerr << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Renderer *gRenderer = SDL_CreateRenderer(gWindow,-1, 0);
    if(gRenderer == nullptr) {
        std::cerr << SDL_GetError() << "\n";
        return 1;
    }

    // load sprite sheet
    SDL_Surface *spritesheet = SDL_LoadBMP("./spritesheet.bmp");
    if(spritesheet == nullptr) {
        std::cerr << SDL_GetError() << "\n";
        return 1;
    }

    SDL_Texture *spritesheet_texture = SDL_CreateTextureFromSurface(gRenderer, spritesheet);
    if(spritesheet_texture == nullptr) {
        std::cerr << SDL_GetError() << "\n";
        SDL_FreeSurface(spritesheet);
        return 1;
    }
    SDL_Rect src{0, 0, 400, 366}, dest{100,100,400,366}; 


    // initial render with white background and black circle
    SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, spritesheet_texture, &src, &dest);
    SDL_RenderPresent(gRenderer);

    bool quit = false;
    SDL_Event e ;
    while (!quit){
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                quit = true;
                std::cout << "quit event triggered\n";
                break;
                default:
                break;
            }
        }

        // update
        // render phase

        // Sleep
        SDL_Delay(17);
    }

    // SDL Cleanup
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    return 0;
}

