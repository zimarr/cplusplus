#ifndef DRAWSTUFF_H
#define DRAWSTFF_H

#include <SDL.h>

void setColor(SDL_Renderer *rend, int r, int b, int g);
void fillRect(SDL_Renderer *rend, int x, int y, int w, int h);
void drawRecs(SDL_Renderer *rend);
void keyPress(SDL_Event &e);
void paint(SDL_Renderer *rend);

#endif