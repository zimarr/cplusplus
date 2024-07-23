#include <SDL.h>
#include <iostream>
#include "drawStuff.h"
#include "Snek.h"
#include "globals.h"

using namespace std;

void draw(SDL_Renderer *rend) {
    paint(rend);
}

int main(int argc, char *argv[]) {
    if(SDL_Init( SDL_INIT_VIDEO ) != 0) {
        cout << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Thing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 444, 444, SDL_WINDOW_SHOWN);
    if (!window) {
        cout << "Error making window." << endl;
        return 1;
    }

    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!rend) {
        cout << "Error making renderer." << endl;
        return 1;
    }

    SDL_Event e;
    bool quit = false;
    while(quit == false) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                quit = true; 
            }

            keyPress(e);
        }

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        draw(rend);

        SDL_RenderPresent(rend);
    }

    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}