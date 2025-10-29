/*
MEHDI NAOUI
2025
Pong
SDL2 https://www.libsdl.org/
Learning to code a pong game using YT video published by Daniel HIRSCH
*/

//include SDL libray wich allow to draw things on a window.
#include <SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    //Initializing the SDL video system.
    SDL_InitSubSystem(SDL_INIT_VIDEO);

    //Create a window and assign is adress to a variable of SDL_Window type.
    SDL_Window *window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);

    //Create a rectangle and assign is adress to a variable of SDL_Surface type.
    //Pass the pointer from the just created window as a parameter for the function.
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    //Create a rectangle using a compound syntax and store it in a SDL_Rect type variable.
    SDL_Rect rectangle = (SDL_Rect) {40,40,40,40};
    
    //White color stored in color.
    Uint32 color = 0xffffffff;

    //Fill the surface with the rectangle and color given in arguments.
    SDL_FillRect(surface,&rectangle,color);

    //Update the window
    SDL_UpdateWindowSurface(window);
    
    SDL_Delay(10000);
    return 0;
}