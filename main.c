/*
MEHDI NAOUI
2025
Pong
SDL2 https://www.libsdl.org/
Learning to code a pong game using YT video published by Daniel HIRSCH
https://youtu.be/m_jDyqcvaQU?si=yy_pF8O90e-_n6XL
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
    SDL_Rect rect_player1 = (SDL_Rect) {40,40,40,200};
    
    //White color stored in color.
    Uint32 color = 0xffffffff;

    //Fill the surface with the rectangle and color given in arguments.
    SDL_FillRect(surface,&rect_player1,color);

    //Reclangle for second player:

    SDL_Rect rect_player2 = (SDL_Rect) {560,150,40,200};
   
    SDL_FillRect(surface,&rect_player2,color);

    //Update the window
    SDL_UpdateWindowSurface(window);
    
    

    int running = 1;
    SDL_Event event ;
    SDL_KeyboardEvent keydown;

    while (running){

        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
            running = 0;
        }

            if(event.type == SDL_KEYDOWN){
                //printf("Key down!\n");

                if (event.key.keysym.sym == SDLK_DOWN){
                

                //Fill old rectangle in black.
                SDL_FillRect(surface,&rect_player1,0x0000000);

                //Change rectangle position
                rect_player1.y += 10; 

                //Print coordinates in the console for debugging
                printf("x_pl1: %d y_pl1: %d\n",rect_player1.x,rect_player1.y);

                //Re-draw the rectangle  
                SDL_FillRect(surface,&rect_player1,color);
            
                }


            

            
                if (event.key.keysym.sym == SDLK_UP ){
                

                //Fill old rectangle in black.
                SDL_FillRect(surface,&rect_player1,0x00000000);

                //Change rectangle position
                rect_player1.y -= 10; 

                //Print coordinates in the console for debugging
                printf("x_pl1: %d y_pl1: %d\n",rect_player1.x,rect_player1.y);

                //Re-draw the rectangle  
                SDL_FillRect(surface,&rect_player1,color);
                
            }

        }

        
    //Refresh the window and redraws elements
    SDL_UpdateWindowSurface(window);
    }

    SDL_Delay(50);
    return 0;
}