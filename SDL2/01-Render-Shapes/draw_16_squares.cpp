// Solutiuon for MTD215 Jul2020 Q4a(i)

#include <SDL2/SDL.h>
#include <iostream>

#define TITLE "Draw Shape App"
#define WIDTH 800
#define HEIGHT 600
#define WHITE {0xff, 0xff, 0xff, 0xff}
#define GAP 20
#define SIDE 100

void drawShape(SDL_Renderer* gRenderer);

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

    // initial render with white background and black circle
    SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(gRenderer);
    drawShape(gRenderer);
    SDL_RenderPresent(gRenderer);

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                quit = true;
                break;
                default:
                break;
            }
        }
    }
}
void drawShape(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xff);
    bool fillRect = true;
    for(int row = 0; row < 4; row++) {
        for(int col=0; col < 4; col++) {
            int x = (col + 1) * GAP + col*SIDE;
            int y = (row + 1) * GAP + row*SIDE;
            SDL_Rect rect{x,y,SIDE,SIDE};
            if(fillRect) {
                SDL_RenderFillRect(gRenderer,&rect);
            } else {
                SDL_RenderDrawRect(gRenderer, &rect);
            }
            fillRect = !fillRect;
        }
        fillRect = ! fillRect;
    }
}