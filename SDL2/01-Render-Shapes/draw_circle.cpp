#include <SDL2/SDL.h>
#include <iostream>

#define TITLE "Draw Circle App"
#define WIDTH 800
#define HEIGHT 600
#define WHITE {0xff, 0xff, 0xff, 0xff}
#define BLACK {0x00, 0x00, 0x00, 0xff}
#define UNIT 10

void fillCircle(SDL_Renderer* gRenderer, int radius, int x, int y, SDL_Color fgcolor);
void drawCircle(SDL_Renderer* gRenderer, int radius, int thickness, int x, int y, SDL_Color fgcolor, SDL_Color bgcolor);

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
    fillCircle(gRenderer, 50, 100, 100, BLACK);
    drawCircle(gRenderer, 50, 10, 300, 100, BLACK, WHITE);
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

void fillCircle(SDL_Renderer* gRenderer, int radius, int x, int y, SDL_Color fgcolor) {
    int x0 = x + radius;
    int y0 = y + radius;
    SDL_SetRenderDrawColor(gRenderer, fgcolor.r, fgcolor.g, fgcolor.b, fgcolor.a);
    for(int dx = 0; dx <= radius; dx++) {
        int dy = std::sqrt(radius*radius - dx*dx);
        int x1 = x0 + dx;
        int y1 = y0 + dy;
        int x2 = x1;
        int y2 = y0 - dy;
        int x3 = x0 - dx;
        int y3 = y2;
        int x4 = x0- dx;
        int y4 = y1; 
        SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
        SDL_RenderDrawLine(gRenderer, x3, y3, x4, y4);
    }
    
}

void drawCircle(SDL_Renderer* gRenderer, int radius, int thickness, int x, int y, SDL_Color fgcolor, SDL_Color bgcolor) {
    fillCircle(gRenderer, radius, x, y, fgcolor);
    fillCircle(gRenderer, radius - thickness, x + thickness, y + thickness, bgcolor);    
}
