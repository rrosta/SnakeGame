//
// Created by Rosta Roghani on 2018-12-27.
//
#include "view.h"
#include "structs.h"
#include "physics.h"
#include "logic.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void init_window(SDL_Renderer * renderer){
    SDL_SetRenderDrawColor(renderer,253, 245, 230, 255);

}

void quit_window(SDL_Window * window,SDL_Renderer * renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void draw_tank(Tank *tank,SDL_Renderer * renderer){
    filledCircleRGBA(renderer, tank->x, tank->y, 15, 0, 0, 0, 255);
    filledCircleRGBA(renderer,tank->x,tank->y,8 , 254, 243, 0, 150);
    thickLineRGBA(renderer, tank->x , tank->y , tank->x +  25 * cos(tank->angle) , tank-> y - 20 * sin(tank->angle) , 7 , 254, 243, 0 , 255);


}

void draw_tank_second(Tank *tank,SDL_Renderer * renderer){
    filledCircleRGBA(renderer, tank->x, tank->y, 15, 0, 0, 0, 255);
    filledCircleRGBA(renderer,tank->x,tank->y,8 , 255, 0 , 0, 150);
    thickLineRGBA(renderer, tank->x , tank->y , tank->x +  25 * cos(tank->angle) , tank-> y - 20 * sin(tank->angle) , 7 , 255, 0, 0 , 255);


}
// tank plumet = 20
void draw_bullet(Bullet * bullet,SDL_Renderer * renderer){
    for(int i = 0 ; i < 5 ;i ++){
        if((bullet+i)->shoot == 1 && (bullet+i)->vanish == 0){
            filledCircleRGBA(renderer, (bullet+i)->x, (bullet+i)->y, 4 , 0, 0, 0, 255);

        }
    }
}

void draw_mine(SDL_Renderer * renderer,Mine * mine){
    int t = 1 ;
    while( mine->plant == 1 && t < 400 ){
        filledCircleRGBA(renderer, mine->x , mine->y , 9 , 255 , 1 , 1 , 255);
        SDL_RenderPresent(renderer);
        t++;
    }

}

void draw_wall(Wall *wall,SDL_Renderer *renderer,int i){
    thickLineRGBA(renderer, ((wall + i)->x1) , ((wall +i ) ->y1)  , ((wall +i)->x2 ) , ((wall + i)->y2)  , 3 ,0, 0, 0 , 255);
}

void draw_menu(SDL_Renderer * renderer, int key) {
    int r[4] = {0}, g[4] = {0}, b[4] = {0};
    char *buffer = malloc(sizeof(char) * 50);
    SDL_SetRenderDrawColor(renderer, 191, 206, 209, 255);
    SDL_RenderClear(renderer);
    if (key % 4 == 0) {
        r[0] += 32;
        g[0] += 167;
        b[0] += 194;
    } else if (key % 4 == 1) {
        r[1] += 32;
        g[1] += 167;
        b[1] += 194;
    } else if(key % 4 == 2){
        r[2] += 32;
        g[2] += 167;
        b[2] += 194;
    }
    else{
        r[3] += 32;
        g[3] += 167;
        b[3] += 194;
    }

    // menu options

    roundedBoxRGBA(renderer, 170, 170, 500, 260, 3, r[0], g[0], b[0], 255);
    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "NEW GAME");
    stringRGBA(renderer, 190, 140, buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);

    roundedBoxRGBA(renderer, 170, 270, 500, 360, 3, r[1], g[1], b[1], 255);
    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "LOAD GAME");
    stringRGBA(renderer, 190, 205, buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);

    roundedBoxRGBA(renderer, 170, 370, 500, 460, 3, r[2], g[2], b[2], 255);
    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "TRAINING");
    stringRGBA(renderer, 190, 275, buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);


    roundedBoxRGBA(renderer, 170, 470, 500, 560, 3, r[3], g[3], b[3], 255);
    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "EXIT GAME");
    stringRGBA(renderer, 190, 340, buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);


    SDL_RenderPresent(renderer);

}


void draw_training(SDL_Renderer * renderer){


    SDL_SetRenderDrawColor(renderer, 191, 206, 209, 255);
    SDL_RenderClear(renderer);
    char *buffer = malloc(sizeof(char) * 50);


    roundedBoxRGBA(renderer, 170, 170, 500, 260, 3, 32, 167, 194 , 255);
    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "BACK TO MENU");
    stringRGBA(renderer, 170, 140, buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);


    rectangleRGBA(renderer,140,300,180,340,0,0,0,255);
    rectangleRGBA(renderer,140,350,180,390,0,0,0,255);
    rectangleRGBA(renderer,90,350,130,390,0,0,0,255);
    rectangleRGBA(renderer,190,350,230,390,0,0,0,255);
    rectangleRGBA(renderer,240,300,280,340,0,0,0,255);
    sprintf(buffer, "UP");
    stringRGBA(renderer, 150, 315, buffer, 255, 255, 255, 255);
    sprintf(buffer, "RIGHT");
    stringRGBA(renderer, 190, 365, buffer, 255, 255, 255, 255);
    sprintf(buffer, "LEFT");
    stringRGBA(renderer, 95, 365, buffer, 255, 255, 255, 255);
    sprintf(buffer, "M");
    stringRGBA(renderer, 255, 315, buffer, 255, 255, 255, 255);
    //player 2
    rectangleRGBA(renderer,500,300,540,340,0,0,0,255);
    rectangleRGBA(renderer,500,350,540,390,0,0,0,255);
    rectangleRGBA(renderer,450,350,490,390,0,0,0,255);
    rectangleRGBA(renderer,550,350,590,390,0,0,0,255);
    rectangleRGBA(renderer,600,300,640,340,0,0,0,255);
    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "R");
    stringRGBA(renderer, 340, 210, buffer, 255, 255, 255, 255);
    sprintf(buffer, "G");
    stringRGBA(renderer, 375, 245, buffer, 255, 255, 255, 255);
    sprintf(buffer, "D");
    stringRGBA(renderer, 310, 245, buffer, 255, 255, 255, 255);
    sprintf(buffer, "T");
    stringRGBA(renderer, 410, 210, buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);


    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "Player One");
    stringRGBA(renderer, 310 , 300 , buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);



    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "Player Two");
    stringRGBA(renderer, 95, 300, buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);
    SDL_RenderPresent(renderer);

}
void draw_table(SDL_Renderer * renderer , Tank * tank_1 , Tank * tank_2 ,int time){
    char *buffer = malloc(sizeof(char) * 50);
    int winner ;
    if(tank_1->point > tank_2->point)
        winner = 1 ;
    else
        winner = 2 ;
    SDL_SetRenderDrawColor(renderer, 241, 177, 194 , 255);
    SDL_RenderClear(renderer);
    SDL_RenderSetScale(renderer, 1.5, 1.5);
    sprintf(buffer, "The Winner is Tank %d",winner);
    stringRGBA(renderer, 100, 200, buffer, 255, 0, 0, 255);
    sprintf(buffer, "TANK 1 POINT: %d",tank_1->point);
    stringRGBA(renderer, 100, 220, buffer, 255, 255, 255, 255);
    sprintf(buffer, "TANK 2 POINT: %d",tank_2->point);
    stringRGBA(renderer, 100, 240, buffer, 255, 255, 255, 255);
    sprintf(buffer, "The Elapsed Time is %d s",time/1000);
    stringRGBA(renderer, 100, 260, buffer, 255, 255, 255, 255);
    SDL_RenderSetScale(renderer, 1, 1);
    SDL_RenderPresent(renderer);

}

void save_file(Tank * tank_1 , Tank * tank_2,Mine * mine){
    FILE * info = fopen("/Users/rostaroghani/Documents/GitHub/97105963/src/info.txt","w");
    fprintf(info,"%d %d\n",tank_1->x,tank_1->y);
    fprintf(info,"%d %d\n",tank_2->x,tank_2->y);
    fprintf(info,"%d %d\n",tank_1->point,tank_2->point);
    fprintf(info,"%f %f\n",tank_1->angle,tank_2->angle);
    fprintf(info,"%d %d\n",tank_1->number_of_shoots,tank_2->number_of_shoots);
    fprintf(info,"%d %d\n",tank_1->powerup,tank_2->powerup);
    for(int i = 0 ; i < 5 ; i ++) {
        fprintf(info, "%d %d\n", (tank_1->bullet + i)->shoot,(tank_1->bullet + i)->vanish);
        if ((tank_1->bullet + i)->shoot == 1  && (tank_1->bullet + i)->vanish == 0 ) {
            fprintf(info, "%d %d\n", (tank_1->bullet + i)->x, (tank_1->bullet + i)->y);
            fprintf(info, "%f\n", (tank_1->bullet + i)->angle);
        }
    }
    for(int i = 0 ; i < 5 ; i ++) {
        fprintf(info, "%d %d\n", (tank_2->bullet + i)->shoot,(tank_2->bullet + i)->vanish);
        if ((tank_2->bullet + i)->shoot == 1 && (tank_2->bullet + i)->vanish == 0) {
            fprintf(info, "%d %d\n", (tank_2->bullet + i)->x, (tank_2->bullet + i)->y);
            fprintf(info, "%f\n", (tank_2->bullet + i)->angle);
        }
    }
    fprintf(info, "%d %d\n",mine->x , mine->y );
    fprintf(info, "%d %d\n",mine->owned , mine->plant );

    fclose(info);
}

void handle_menu(SDL_Window * window ,SDL_Renderer * renderer ,Map * map , Tank * tank_1, Tank * tank_2,Mine * mine, int *pointer_1,int * pointer_2,bool * z){
    FILE * info = fopen("/Users/rostaroghani/Documents/GitHub/97105963/src/info.txt","r");
    static int x = 0 ;
    int key = 0 ;
    bool t = true ;
    bool d = true ;
    SDL_Event menu;
    x ++ ;
    if(x % 2 != 0){
        while(t){
            draw_menu(renderer,key);
            if(SDL_PollEvent(&menu)) {
                if(menu.type == SDL_KEYDOWN) {
                    switch (menu.key.keysym.sym) {
                        case SDLK_DOWN:
                            key++;
                            draw_menu(renderer, key);
                            break;
                        case SDLK_RETURN:
                            if (key % 4 == 0) { // new game
                                srand(time(0));
                                tank_1->x = rand() % 700 + 7;
                                tank_1->y = rand() % 715 + 7;
                                tank_2->x = rand() % 700 + 7;
                                tank_2->y = rand() % 715 + 7;
                                mine->x = rand() % 700 + 7;
                                mine->y = rand() % 715 + 7;
                                mine->plant = 0;
                                mine->owned = 0;
                                tank_1->powerup = 0;
                                tank_2->powerup = 0;
                                for (int i = 0; i < 5; i++) {
                                    (tank_1->bullet + i)->shoot = 0;
                                    (tank_2->bullet + i)->shoot = 0;
                                    *(pointer_1 + i) = 0;
                                    *(pointer_2 + i) = 0;
                                    (tank_1->bullet + i)->vanish = 0;
                                    (tank_2->bullet + i)->vanish = 0;
                                }
                                tank_1->number_of_shoots = 0;
                                tank_2->number_of_shoots = 0;
                                tank_1->angle = 0;
                                tank_2->angle = 0;
                                tank_1->point = 0;
                                tank_2->point = 0;
                                t = false;
                            }
                            if (key % 4 == 1) { //load game
                                fscanf(info, "%d%d", &(tank_1->x), &(tank_1->y));
                                fscanf(info, "%d%d", &(tank_2->x), &(tank_2->y));
                                fscanf(info, "%d%d", &(tank_1->point), &(tank_2->point));
                                fscanf(info, "%lf%lf", &(tank_1->angle), &(tank_2->angle));
                                fscanf(info, "%d%d", &(tank_1->number_of_shoots), &(tank_2->number_of_shoots));
                                fscanf(info, "%d%d", &(tank_1->powerup), &(tank_2->powerup));
                                for (int i = 0; i < 5; i++) {
                                    fscanf(info, "%d%d", &((tank_1->bullet + i)->shoot),
                                           &((tank_1->bullet + i)->vanish));
                                    if ((tank_1->bullet + i)->shoot == 1 && (tank_1->bullet + i)->vanish == 0) {
                                        fscanf(info, "%d%d", &((tank_1->bullet + i)->x), &((tank_1->bullet + i)->y));
                                        fscanf(info, "%lf", &((tank_1->bullet + i)->angle));
                                    }
                                }
                                for (int i = 0; i < 5; i++) {
                                    fscanf(info, "%d%d", &((tank_2->bullet + i)->shoot),
                                           &((tank_2->bullet + i)->vanish));
                                    if ((tank_2->bullet + i)->shoot == 1 && (tank_2->bullet + i)->vanish == 0) {
                                        fscanf(info, "%d%d", &((tank_2->bullet + i)->x), &((tank_2->bullet + i)->y));
                                        fscanf(info, "%lf", &((tank_2->bullet + i)->angle));
                                    }
                                }
                                fscanf(info, "%d%d", &(mine->x), &(mine->y));
                                fscanf(info, "%d%d", &(mine->owned), &(mine->plant));
                                fclose(info);
                                t = false;
                            }
                            if (key % 4 == 2) {
                                while (d) {
                                    draw_training(renderer);
                                    if (SDL_PollEvent(&menu)) {
                                        if (menu.type == SDL_KEYDOWN) {
                                            switch (menu.key.keysym.sym) {
                                                case SDLK_RETURN:
                                                    handle_menu(window, renderer, map, tank_1, tank_2, mine, pointer_1,
                                                                pointer_2, z);
                                                    d = false;
                                                    break;
                                                case SDLK_F4:
                                                    quit_window(window, renderer);
                                                    *(z) = false;
                                                    return;
                                            }
                                        } else if (menu.type == SDL_QUIT) {
                                            quit_window(window, renderer);
                                            *(z) = false;
                                            return;
                                        }
                                    }

                                }
                            }
                            if (key % 4 == 3) { // exit game
                                    quit_window(window, renderer);
                                    *(z) = false;
                                    return;
                            }
                            break;
                        case SDLK_F4:
                            quit_window(window, renderer);
                            *(z) = false;
                            return;
                    }
                }
                else if(menu.type == SDL_QUIT) {
                    quit_window(window,renderer);
                    *(z) = false ;
                    return;
                }
            }
            d =true ;
        }
    }

}


void handle_events(SDL_Window * window ,SDL_Renderer * renderer , Tank * tank_1, Tank * tank_2,Mine * mine, const Uint8 * state,Map *map,int n,bool * z){
    if(state[SDL_SCANCODE_LEFT]) {
        turn_tank(tank_1, -1);
    }
    if(state[SDL_SCANCODE_RIGHT]) {
        turn_tank(tank_1, 1);
    }
    if(state[SDL_SCANCODE_UP]) {
        move_tank(map, tank_1, tank_2, mine, renderer, n);
    }
    if(state[SDL_SCANCODE_D]) {
        turn_tank(tank_2, -1);
    }
    if(state[SDL_SCANCODE_G]) {
        turn_tank(tank_2, 1);
    }
    if(state[SDL_SCANCODE_R]) {
        move_tank(map, tank_2, tank_1, mine, renderer, n);
    }
    if(state[SDL_SCANCODE_S]) {
        save_file(tank_1, tank_2, mine);
    }
    if(state[SDL_SCANCODE_F4]) {
        quit_window(window, renderer);
        *(z) = false;
    }
    if(state[SDL_SCANCODE_M]) {
        if (tank_1->number_of_shoots < 5 && tank_1->powerup == 0) {
            fire(tank_1);
            tank_1->number_of_shoots++;
        }
        if (tank_1->powerup == 1) {
            mine->x = tank_1->x - 20;
            mine->y = tank_1->y - 20;
            mine->owned = 0;
            mine->plant = 1;
            tank_1->powerup = 0;
            //draw_mine(renderer,mine);
        }
    }
    if(state[SDL_SCANCODE_T]) {
        if (tank_2->number_of_shoots < 5 && tank_2->powerup == 0) {
            fire(tank_2);
            tank_2->number_of_shoots++;
        }
        if (tank_2->powerup == 1) {
            mine->x = tank_2->x - 20;
            mine->y = tank_2->y - 20;
            mine->owned = 0;
            mine->plant = 1;
            tank_2->powerup = 0;
            //draw_mine(renderer,mine);
        }
    }
}


//void handle_events(SDL_Window * window ,SDL_Renderer * renderer , Tank * tank_1, Tank * tank_2,Mine * mine, SDL_Event event,Map *map,int n,bool * z){
//    switch(event.key.keysym.sym){
//        case SDLK_LEFT:
//            turn_tank(tank_1,-1);
//            break;
//        case SDLK_RIGHT:
//            turn_tank(tank_1,1);
//            break;
//        case SDLK_UP:
//            move_tank(map,tank_1,tank_2,mine,renderer,n);
//            break;
//        case SDLK_d:
//            turn_tank(tank_2,-1);
//            break;
//        case SDLK_g:
//            turn_tank(tank_2,1);
//            break;
//        case SDLK_r:
//            move_tank(map,tank_2,tank_1,mine,renderer,n);
//            break;
//        case SDLK_s:
//           save_file(tank_1,tank_2,mine);
//           break;
//        case SDLK_F4:
//            quit_window(window,renderer);
//            *(z) = false ;
//            break;
//        case SDLK_m:
//            if(tank_1->number_of_shoots < 5 && tank_1->powerup == 0) {
//                fire(tank_1);
//                tank_1->number_of_shoots ++;
//            }
//            if(tank_1->powerup == 1){
//                mine->x = tank_1->x - 20 ;
//                mine->y = tank_1->y - 20;
//                mine->owned = 0 ;
//                mine->plant = 1 ;
//                tank_1->powerup = 0;
//                //draw_mine(renderer,mine);
//            }
//            break;
//        case SDLK_t:
//            if(tank_2->number_of_shoots < 5 && tank_2->powerup == 0) {
//                fire(tank_2);
//                tank_2->number_of_shoots ++ ;
//            }
//            if(tank_2->powerup == 1){
//                mine->x = tank_2->x - 20 ;
//                mine->y = tank_2->y - 20 ;
//                mine->owned = 0 ;
//                mine->plant = 1;
//                tank_2->powerup = 0 ;
//                //draw_mine(renderer,mine);
//            }
//            break;
//    }
//
//}




