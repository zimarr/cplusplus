#include <SDL.h>
#include <iostream>
#include "Snek.h"
#include "globals.h"

void setColor(SDL_Renderer *rend, int r, int b, int g) {
    SDL_SetRenderDrawColor(rend, r, b, g, 255);
}

void fillRect(SDL_Renderer *rend, int x, int y, int w, int h) {
    SDL_Rect rect = {x, y, w, h};

    SDL_RenderFillRect(rend, &rect);
}





void mathStuff() {
    return;




}

// ============================================== //

void drawBoard(SDL_Renderer *rend) {
    setColor(rend, 31, 31, 31);
    fillRect(rend, 0, 0, 444, 444);
    
    setColor(rend, 0, 0, 0);

    for (int i = 0; i <= 11; i++) {
        fillRect(rend, i * 40, 0, 4, 444);
        fillRect(rend, 0, i * 40, 444, 4);
    }
}

void keyPress(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                snake.switchDirection(Position(0, -1));
                break;
            case SDLK_DOWN:
                snake.switchDirection(Position(0, 1));
                break;
            case SDLK_LEFT:
                snake.switchDirection(Position(-1, 0));
                break;
            case SDLK_RIGHT:
                snake.switchDirection(Position(1, 0));
                break;
        }
    }
}

void paint(SDL_Renderer *rend) {
    drawBoard(rend);

    
    snake.updateBody(rend);
    apple.drawFruit(rend);
    snake.drawBody(rend);
    
    // snake.printDirections();
    // cout << snake.getDirection() << endl;
    
    SDL_Delay(100);
}