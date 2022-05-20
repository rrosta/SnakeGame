//
// Created by Rosta Roghani on 2018-12-27.
//

#include "physics.h"
#include "structs.h"
#include "view.h"
#include "logic.h"
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

const int steptank = 7 ;
const int stepbullet = 3;

void move_tank(Map * map , Tank * tank  ,Tank * tank_2 , Mine * mine , SDL_Renderer * renderer, int n){
//    tank->x += steptank * cos(tank->angle);
//    tank->y -= steptank * sin(tank->angle);
//    if( !movement_collids_walls(map,tank, n) ){
//        tank->x -= steptank * cos(tank->angle);
//        tank->y += steptank * sin(tank->angle);
//    }
    if( !movement_collids_walls(map,tank, n) ){
        tank->x += steptank * cos(tank->angle);
        tank->y -= steptank * sin(tank->angle);
    }
    get_mine(tank,tank_2,mine,renderer);
}

void turn_tank(Tank *tank, int dir){
    if(dir == -1){
        tank->angle -= 0.2 ;
//        printf("right\n");
    }
    else{
        tank->angle += 0.2 ;
//        printf("left\n");
    }
}
void fire(Tank *tank){
    (tank->bullet+ tank->number_of_shoots )->x = tank->x + 35 * cos(tank->angle);
    (tank->bullet+ tank->number_of_shoots )->y = tank->y - 35 * sin(tank->angle);
    (tank->bullet + tank->number_of_shoots )->angle = tank->angle;
    (tank->bullet + tank->number_of_shoots )->shoot = 1 ;
}
void move_bullet(Tank * attacker,Tank * destination,int *pointer_1 , int *pointer_2,Map * map, int n) {
    for (int j = 0; j < 5; j++) {
        if ((attacker->bullet + j)->shoot == 1) {
            if (*(pointer_1 + j) < 700) {
                //if(!(bullet_hits_wall(attacker->bullet + j,map ,n )) ){
                bullet_hits_wall(attacker->bullet+j,map,n);
                    (attacker->bullet + j)->x += stepbullet * cos((attacker->bullet + j)->angle);
                    (attacker->bullet + j)->y -= stepbullet * sin((attacker->bullet + j)->angle);
                    *(pointer_1 + j) += 1;
                    if ((movement_collids_tanks(attacker->bullet + j, attacker, destination))) {
                        if (movement_collids_tanks(attacker->bullet + j, attacker, destination) == 1)
                            attacker->point++;
                        else
                            destination->point++;
                        if (attacker->point != 5 && destination->point != 5) {
                            srand(time(0));
                            attacker->x = rand() % 700 + 5;
                            attacker->y = rand() % 715 + 5;
                            destination->x = rand() % 700 + 5;
                            destination->y = rand() % 715 + 5;
                            srand(time(0));
                            for (int i = 0; i < 5; i++) {
                                (attacker->bullet + i)->shoot = 0;
                                (destination->bullet + i)->shoot = 0;
                            }
                            attacker->number_of_shoots = 0;
                            destination->number_of_shoots = 0;
                            for (int i = 0; i < 5; i++) {
                                *(pointer_1 + i) = 0;
                                *(pointer_2 + i) = 0;
                            }
                            attacker->angle = 0;
                            destination->angle = 0;
                        }

                    }
                //}
            }
            else
                (attacker->bullet + j)->vanish = 1;
//                (attacker->bullet + j)->shoot = 0;
        }
    }
}
