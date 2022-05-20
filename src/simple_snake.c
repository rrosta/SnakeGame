#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>
#include "structs.h"
#include "logic.h"
#include "view.h"
#include "physics.h"
#include "logic.h"
//mapwidth = 710
//mapheight = 730

int wallnum ;
const int FPS = 200 ;

void read_map_file(Map *map,char *file_path){
    FILE * file = fopen(file_path,"r");
    fscanf(file,"%d",&wallnum);
    map->walls = malloc(sizeof(Wall) * wallnum);
    int x1,x2,y1,y2;
    for(int i = 0 ; i < wallnum ; i++){
        fscanf(file,"%d%d%d%d",&x1,&y1,&x2,&y2);
        (map->walls +i)->x1 = 117 * x1 ;
        (map->walls +i)->x2 = 117 * x2 ;
        (map->walls +i)->y1 = 103 * y1 ;
        (map->walls +i)->y2 = 103 * y2 ;
    }
    fclose(file);
}

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("map",300,220,705,723,SDL_WINDOW_OPENGL);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Map * map = malloc(sizeof(Map) * 1);
    Tank * tank_1 = malloc(sizeof(Tank) * 1);
    Tank * tank_2 = malloc(sizeof(Tank) * 1);
    Bullet * bullet_1 = malloc(sizeof(Bullet) * 5);
    Bullet * bullet_2 = malloc(sizeof(Bullet) * 5);
    Mine * mine = malloc(sizeof(Mine));
    tank_1->bullet = bullet_1 ;
    tank_2->bullet = bullet_2 ;
    SDL_Event event;
    const Uint8 * state  = SDL_GetKeyboardState(NULL);
    int d[5] = {0} , c[5] = {0} ; //time of each bullet
    int * pd = malloc(sizeof(int) * 5); // pointer to above
    int * pc = malloc(sizeof(int) * 5);
    int z = 1 ;
    pd = d;
    pc = c;
    bool x = true ;
    read_map_file(map,"mapmap.txt");
    event.key.keysym.sym  = SDLK_ESCAPE;
    int begining_of_time = SDL_GetTicks();
    handle_menu(window,renderer,map,tank_1,tank_2,mine,pc,pd,&x);
    while(x){
        int start_ticks = SDL_GetTicks();
        init_window(renderer);
        SDL_RenderClear(renderer);
        draw_tank(tank_1,renderer);
        draw_tank_second(tank_2,renderer);
        for(int i = 0 ; i < wallnum ; i++){
            draw_wall(map->walls,renderer,i);
        }
        if(SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (state[SDL_SCANCODE_ESCAPE]) {
                    handle_menu(window, renderer, map, tank_1, tank_2, mine, pc, pd, &x);
                    begining_of_time = SDL_GetTicks();
                }
                else
                    handle_events(window, renderer, tank_1, tank_2, mine, state, map, wallnum, &x);
            }
            else if (event.type == SDL_QUIT)
                x = false;
        }
        draw_bullet(tank_1->bullet,renderer);
        move_bullet(tank_1,tank_2,pc,pd,map,wallnum);
        draw_bullet(tank_2->bullet,renderer);
        move_bullet(tank_2,tank_1,pd,pc,map,wallnum);
        if(tank_1->point == 5 || tank_2->point == 5){
            draw_table(renderer,tank_1,tank_2,start_ticks - begining_of_time);
            SDL_Delay(8000);
            x = false;
            return 0 ;
        }
        char* buffer = malloc(sizeof(char) * 50);
        sprintf(buffer, "tank 1 point: %d", tank_1->point);
        stringRGBA(renderer, 5, 5, buffer, 0, 0, 0, 255);
        sprintf(buffer, "tank 2 point: %d", tank_2->point);
        stringRGBA(renderer, 5, 15, buffer, 0, 0, 0, 255);
        sprintf(buffer, "The Elapsed Time is %d s",start_ticks - begining_of_time);
        stringRGBA(renderer, 5, 25, buffer, 0, 0, 0, 255);
        if(start_ticks - begining_of_time >= 40000 * z ){
            for(int i = 0 ; i < 5 ; i++){
                (tank_1->bullet + i)->shoot = 0;
                (tank_2->bullet + i)->shoot = 0;
                (tank_1->bullet + i)->vanish = 0;
                (tank_2->bullet + i)->vanish = 0;
                d[i] = 0 ;
                c[i] = 0 ;
            }
            tank_1->number_of_shoots = 0 ;
            tank_2->number_of_shoots = 0 ;
            z ++ ;
        }
        if(start_ticks - begining_of_time >= 15000 && start_ticks - begining_of_time <= 40000 ){
            if(mine->owned == 0 && mine->plant == 0){
                filledCircleRGBA(renderer, mine->x ,mine->y , 9 , 255 , 1 , 1 , 255);
            }
        }
        else if(start_ticks - begining_of_time >= 75000 && start_ticks - begining_of_time <= 100000 ){
            if(mine->owned == 0 && mine->plant == 0){
                filledCircleRGBA(renderer, mine->x ,mine->y , 9 , 255 , 1 , 1 , 255);
            }
        }
        else if(start_ticks - begining_of_time >= 140000 && start_ticks - begining_of_time <= 175000 ){
            if(mine->owned == 0 && mine->plant == 0){
                filledCircleRGBA(renderer, mine->x ,mine->y , 9 , 255 , 1 , 1 , 255);
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/FPS);
    }

    quit_window(window,renderer);

}

//    while(x){
//        int start_ticks = SDL_GetTicks();
//        init_window(renderer);
//        SDL_RenderClear(renderer);
//        draw_tank(tank_1,renderer);
//        draw_tank_second(tank_2,renderer);
//        for(int i = 0 ; i < wallnum ; i++){
//            draw_wall(map->walls,renderer,i);
//        }
//        if(SDL_PollEvent(&event)) {
//            if(event.type == SDL_KEYDOWN){
//                switch(event.key.keysym.sym){
//                    case SDLK_ESCAPE:
//                        handle_menu(window,renderer,map,tank_1,tank_2,mine,pc,pd,&x);
//                        begining_of_time = SDL_GetTicks();
//                        break;
//                    default:
//                        handle_events(window,renderer,tank_1,tank_2,mine,event,map,wallnum,&x);
//                        break;
//                }
//            }
//            else if(event.type == SDL_QUIT)
//                x = false;
//        }
//        draw_bullet(tank_1->bullet,renderer);
//        move_bullet(tank_1,tank_2,pc,pd,map,wallnum);
//        draw_bullet(tank_2->bullet,renderer);
//        move_bullet(tank_2,tank_1,pd,pc,map,wallnum);
//        if(tank_1->point == 5 || tank_2->point == 5){
//            draw_table(renderer,tank_1,tank_2,start_ticks - begining_of_time);
//            SDL_Delay(8000);
//            x = false;
//            return 0 ;
//        }
//        char* buffer = malloc(sizeof(char) * 50);
//        sprintf(buffer, "tank 1 point: %d", tank_1->point);
//        stringRGBA(renderer, 5, 5, buffer, 0, 0, 0, 255);
//        sprintf(buffer, "tank 2 point: %d", tank_2->point);
//        stringRGBA(renderer, 5, 15, buffer, 0, 0, 0, 255);
//        sprintf(buffer, "The Elapsed Time is %d s",start_ticks - begining_of_time);
//        stringRGBA(renderer, 5, 25, buffer, 0, 0, 0, 255);
//        if(start_ticks - begining_of_time >= 40000 * z ){
//            for(int i = 0 ; i < 5 ; i++){
//                (tank_1->bullet + i)->shoot = 0;
//                (tank_2->bullet + i)->shoot = 0;
//                (tank_1->bullet + i)->vanish = 0;
//                (tank_2->bullet + i)->vanish = 0;
//                d[i] = 0 ;
//                c[i] = 0 ;
//            }
//            tank_1->number_of_shoots = 0 ;
//            tank_2->number_of_shoots = 0 ;
//            z ++ ;
//        }
//        if(start_ticks - begining_of_time >= 15000 && start_ticks - begining_of_time <= 40000 ){
//            if(mine->owned == 0 && mine->plant == 0){
//                filledCircleRGBA(renderer, mine->x ,mine->y , 9 , 255 , 1 , 1 , 255);
//            }
//        }
//        else if(start_ticks - begining_of_time >= 75000 && start_ticks - begining_of_time <= 100000 ){
//            if(mine->owned == 0 && mine->plant == 0){
//                filledCircleRGBA(renderer, mine->x ,mine->y , 9 , 255 , 1 , 1 , 255);
//            }
//        }
//        else if(start_ticks - begining_of_time >= 140000 && start_ticks - begining_of_time <= 175000 ){
//            if(mine->owned == 0 && mine->plant == 0){
//                filledCircleRGBA(renderer, mine->x ,mine->y , 9 , 255 , 1 , 1 , 255);
//            }
//        }
//        SDL_RenderPresent(renderer);
//        SDL_Delay(1000/FPS);
//    }
