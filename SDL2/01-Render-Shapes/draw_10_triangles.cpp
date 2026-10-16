
#include <SDL2/SDL.h>
#include <iostream>

#define TITLE "Draw Shape App"
#define WIDTH 800
#define HEIGHT 600
#define WHITE {0xff, 0xff, 0xff, 0xff}
#define UNIT 50
#define GAP 10
#define SIDE 10

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
//draw 10 triangles
void drawShape(SDL_Renderer* gRenderer) {
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xff);
    int x0 = GAP;
    int y0 = GAP;
    for(int n = 4; n > 0; n--) {
        for(int i=0; i < n; i++) {
            int x1 = x0 + UNIT;
            int y1 = y0;
            int x2 = x0;
            int y2 = y0 + 2*UNIT;
            int x3 = x2 + 2*UNIT;
            int y3 = y2;
            SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
            SDL_RenderDrawLine(gRenderer, x2, y2, x3, y3);
            SDL_RenderDrawLine(gRenderer, x3, y3, x1, y1);
            x0 += 2*UNIT + GAP;
        }
        // reset x0 and set y0 for next row
        x0 = GAP;
        y0 += 2*UNIT + GAP;
    }
}
