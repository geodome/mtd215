#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#define TITLE "Word App"
#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* argv[]) {
    // SDL_init phase
    // Compared to 00-Launch-Window, we are adding line 30-42 to the SDL_Init phase

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

    // To render text, first initialise the TTF subsystem
    // note the structural similiarity with SDL_Init(SDL_INIT_EVERTHING)
    if(TTF_Init() != 0) {
        std::cerr << TTF_GetError() << "\n";
        return 1;
    }

    // Load the font at font size 32
    TTF_Font* arial = TTF_OpenFont("./arial-geo-bold-webfont.ttf", 32);
    if(arial == nullptr) {
        std::cerr << TTF_GetError() << "\n";
        return 1;
    }

    // Render the text "Hello World" in black color
    SDL_Color black = {0x00, 0x00, 0x00, 0x00};
    SDL_Surface* textSurface = TTF_RenderText_Blended(arial, "Hello World", black);
    // since we are working with renderer, then we have to convert textSurface to texture format
    // texture is for GPU processing
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
    // specify where the text will be rendered in the window
    // in this case, the text will be center-aligned
    // note SDL_Rect format is {x, y, width, height}
    SDL_Rect dest{(WIDTH - textSurface->w)/2,(HEIGHT - textSurface->h)/2,textSurface->w, textSurface->h};

    // initial render with white background
    SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(gRenderer);
    // paste the text iunto the center of the window
    // note the source rect pointer is set nullptr, hence SDL_RenderCopy will copy the entire texture of the renndered text
    // &dest refers to the rectangular region in the window where the textTexture will be rendered
    SDL_RenderCopy(gRenderer, textTexture, nullptr, &dest);
    SDL_RenderPresent(gRenderer);

    bool quit = false;
    SDL_Event e ;
    while (!quit){
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                quit = true;
                std::cout << "quit event triggered" << "\n";
                break;
                default:
                break;
            }
        }

        // Sleep
        SDL_Delay(17);
    }

    // SDL Cleanup
    // To add clean up for SDL2_TTF components
    TTF_CloseFont(arial);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_Quit();
    // clean up for SDL2 components
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    return 0;
}

