/*
MEHDI NAOUI
2025
Pong
SDL2 https://www.libsdl.org/
Learning to code a pong game using YT video published by Daniel HIRSCH
https://youtu.be/m_jDyqcvaQU?si=yy_pF8O90e-_n6XL
*/

//TODO Add ball movement,Ep.3.I already watched til 13.04 but didn't add anything to the code yet.

//include SDL libray wich allow to draw things on a window.
#include <SDL.h>
#include <stdio.h>

//Speed constant
static int MOVEMENT_SPEED = 10;
static int LEFT_INNER_BORDER = 80;
static int RIGHT_INNER_BORDER = 560;
static int PL_WIDTH = 40;
static int PL_HEIGHT= 200;



//Structure for x and y axes speeds.We're using integer.
//Use typdef to make an alias and use more readable declarations.
typedef struct Speed {
    int x;
    int y;
} Speed;

typedef struct Ball {
    Speed speed;
    SDL_Rect* rect;
} Ball;




/*Function designed to move a piece of rectangle*/
void move_rect(SDL_Surface *surface,SDL_Rect *rect,Speed* speed,int player)
{
    //Fill old rectangle in black.
    SDL_FillRect(surface, rect, 0x000000000);

    //Change rectangle position
    rect->y += speed->y;
    rect->x += speed->x;

    //Print coordinates in the console for debugging
    /*
    if(player==1){
        printf("y_pl1: %d\n",rect->y);
        printf("surface height= %d",surface->h);
    }else if(player==2){
        printf("y_pl2: %d\n",rect->y);
        printf("surface height= %d",surface->h);
        
    }else{
        printf("x_speed_Ball: %d\n",speed->x);
        printf("y_speed_Ball: %d\n",speed->y);
    }
        */
    //Re-draw the rectangle  
    SDL_FillRect(surface, rect, 0xffffffff);
}

void move_ball(SDL_Surface* surface, SDL_Rect* ball,SDL_Rect* player1, SDL_Rect* player2,Speed* ball_speed)
{
    //Bounce back the ball when in contact with player one.
    if(ball->x <= LEFT_INNER_BORDER){
        if(((ball->y + ball->h) > player1->y) && (ball->y < player1->y + player1->h)){
            //change to opposite direction on x axis
            ball_speed->x = -ball_speed->x; 
            //Normalize Y axis movement
            double hit_fraction = ((double)(ball->y+(ball->h/ (double) 2)) - (double)(player1->y + (player1->h/(double) 2)))/ ((double) PL_HEIGHT / 2);
            printf("hit fraction: %f\n",hit_fraction);
            //Apply normalization to ball speed on y axis
            ball_speed->y = (double)(hit_fraction * (double)MOVEMENT_SPEED );
            printf("ball_speed_y: %f\n",ball_speed->y);

        }

    }
    //Bounce back the ball when in contact with player two.
    if(ball->x + ball->w >= RIGHT_INNER_BORDER){
        if(((ball->y + ball->h) > player2->y) && (ball->y < player2->y + player2->h)){
            ball_speed->x = -ball_speed->x;

             //Normalize Y axis movement
            double hit_fraction = ((double)(ball->y+(ball->h/ (double) 2)) - (double)(player2->y + (player2->h/(double) 2)))/ ((double) PL_HEIGHT / 2);
            printf("hit fraction: %f",hit_fraction);
            //Apply normalization to ball speed on y axis
            ball_speed->y = (double)(hit_fraction * (double)MOVEMENT_SPEED);
            printf("ball_speed_y: %f\n",ball_speed->y);
        }
    }
    //Use to slower ball's speed.
    SDL_Delay(1);
    move_rect(surface, ball, ball_speed,3);
}

/*Direction shall be +-1 */
void move_player(SDL_Surface* surface,SDL_Rect* player,int direction, int player_number){

    
    if(direction < 0 && player->y <= 0){
        //player->y=player->y+5;

        return;
    }

    
    if(direction > 0 && player->y >= surface->h - player->h){
        //player->y=player->y-5; //TODO
        return;
    }

    Speed speed = (Speed){0,direction*MOVEMENT_SPEED};                   
    move_rect(surface,player,&speed,player_number);
}



int main(int argc, char *argv[]) {
    //Initializing the SDL video system.
    SDL_InitSubSystem(SDL_INIT_VIDEO);

    //Create a window and assign is adress to a variable of SDL_Window type.
    SDL_Window *window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,0);

    //Create a rectangle and assign is adress to a variable of SDL_Surface type.
    //Pass the pointer from the just created window as a parameter for the function.
    SDL_Surface *surface = SDL_GetWindowSurface(window);

    //Create a rectangle using a compound syntax and store it in a SDL_Rect type variable.
    SDL_Rect rect_player1 = (SDL_Rect) {LEFT_INNER_BORDER - PL_WIDTH,40,PL_WIDTH,PL_HEIGHT};
    
    //White color stored in color.
    Uint32 color = 0xffffffff;

    //Fill the surface with the rectangle and color given in arguments.
    SDL_FillRect(surface,&rect_player1,color);

    //Reclangle for second player:

    SDL_Rect rect_player2 = (SDL_Rect) {RIGHT_INNER_BORDER,150,PL_WIDTH,PL_HEIGHT};
   
    SDL_FillRect(surface,&rect_player2,color);

    SDL_Rect ball = (SDL_Rect) {320,240,20,20};
    SDL_FillRect(surface,&ball,color);
    Speed ball_speed = (Speed){1,0};

    SDL_Rect border = (SDL_Rect) {320,0,1,480};
    SDL_FillRect(surface,&border,color);


    //Update the window
    SDL_UpdateWindowSurface(window);
    
    

    int running = 1;
    SDL_Event event ;
    SDL_KeyboardEvent keydown;

    //Event loop
    while (running){

        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT){
            running = 0;
        }

            if(event.type == SDL_KEYDOWN){
                //printf("Key down!\n");

                //Player1_upward
                if (event.key.keysym.sym == SDLK_CAPSLOCK ){

                    
                    move_player(surface,&rect_player1,-1,1);          
                }

                //Player1_downward
                if (event.key.keysym.sym == SDLK_LSHIFT){
                   
                    move_player(surface,&rect_player1,+1,1);    
                }

             

                //Player2_upward
                if (event.key.keysym.sym == SDLK_UP  ){
                    
                    
                    move_player(surface,&rect_player2,-1,2); 
                }

                 //Player2_downward
                if (event.key.keysym.sym == SDLK_DOWN){
                
                
                    move_player(surface,&rect_player2,+1,2); 
                
            }
            

        }
        
       
    //Move the ball
    move_ball(surface, &ball, &rect_player1, &rect_player2,&ball_speed);
    //move_rect(surface, &ball, &ball_speed,3);
    
    //Redraw the border after the ball crossed it
    SDL_FillRect(surface,&border,color);
    
    //Refresh the window and redraws elements
    SDL_UpdateWindowSurface(window);
    }

    SDL_Delay(50);
    return 0;
}