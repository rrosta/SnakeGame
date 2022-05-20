//
// Created by Rosta Roghani on 2018-12-27.
//

#include "logic.h"
#include "structs.h"
#include "view.h"
#include "physics.h"
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

#define max(a,b) (a >b) * (a) + (b >= a) * (b)
#define min(a,b) (a < b) * (a) + (b <= a) * (b)
#define M_PI 3.141592653589


//if the tank hits the walls it will return true else it returns false

bool movement_collids_walls(Map * map, Tank * tank, int n){
    for(int i = 0 ; i < n ; i++){
        if((map->walls+i)->x1 == (map->walls+i)->x2){ //divar e  amudi
            // az samte chap
            if(tank->x < (map->walls+i)->x1 && tank->x + 7 * cos(tank->angle) > (map->walls+i)->x1 - 16.5 && tank->y - 7 * sin(tank->angle) > min((map->walls+i)->y2,(map->walls+i)->y1) - 15 && tank->y - 7 * sin(tank->angle) < max((map->walls+i)->y1 , (map->walls+i)->y2) + 15 )
                return true ;
            //az samte rast
            if(tank->x > (map->walls+i)->x1 && tank->x + 7 * cos(tank->angle) < (map->walls+i)->x1 + 16.5 && tank->y - 7 * sin(tank->angle) > min((map->walls+i)->y2,(map->walls+i)->y1) - 15 && tank->y - 7 * sin(tank->angle) < max((map->walls+i)->y1 , (map->walls+i)->y2) + 15 )
            return true ;
        }
        if((map->walls+i)->y1 == (map->walls+i)->y2){ //divar e  ofoqi
            // az samte bala
            if(tank->y < (map->walls+i)->y1 && tank->y - 7 * sin(tank->angle) > (map->walls+i)->y1 - 16.5 && tank->x + 7 * cos(tank->angle) > min((map->walls+i)->x2,(map->walls+i)->x1) - 15 && tank->x + 7 * cos(tank->angle) < max((map->walls+i)->x1 , (map->walls+i)->x2) + 15 )
            return true ;
            //az samte rast
            if(tank->y > (map->walls+i)->y1 && tank->y - 7 * sin(tank->angle) < (map->walls+i)->y1 + 16.5 && tank->x + 7 * cos(tank->angle) > min((map->walls+i)->x2,(map->walls+i)->x1) - 15 && tank->x + 7 * cos(tank->angle) < max((map->walls+i)->x1 , (map->walls+i)->x2) + 15 )
            return true ;
        }
    }
    return false ;

}


// if the attacker hits himself returns -1 and if it hits the destination , return 1  if it doesn't hit anything return 0

int movement_collids_tanks(Bullet * bullet , Tank * attacker , Tank * destination ){
    if(sqrt(pow(attacker->x - bullet->x , 2) + pow(attacker->y - bullet->y , 2)) <= 19 ){
        return -1 ;
    }
    if(sqrt(pow(destination->x - bullet->x , 2) + pow(destination->y - bullet->y , 2)) <= 19 ){
        return 1 ;

    }
    return 0 ;
}

void bullet_hits_wall(Bullet * bullet , Map * map , int n ){
    for(int i = 0 ; i < n ; i++){
        if((map->walls+i)->x1 == (map->walls+i)->x2){ //divar e  amudi
            // az samte chap
            if(bullet->x < (map->walls+i)->x1 && bullet->x + 3 * cos(bullet->angle) > (map->walls+i)->x1 - 3.5 && bullet->y - 3 * sin(bullet->angle) > min((map->walls+i)->y2,(map->walls+i)->y1) - 2 && bullet->y - 3 * sin(bullet->angle) < max((map->walls+i)->y1 , (map->walls+i)->y2) + 2 )
                bullet->angle = M_PI - bullet->angle ;
            //az samte rast
            if(bullet->x > (map->walls+i)->x1 && bullet->x + 3 * cos(bullet->angle) < (map->walls+i)->x1 + 3.5 && bullet->y - 3 * sin(bullet->angle) > min((map->walls+i)->y2,(map->walls+i)->y1) - 2 && bullet->y - 3 * sin(bullet->angle) < max((map->walls+i)->y1 , (map->walls+i)->y2) + 2 )
                bullet->angle = M_PI - bullet->angle ;
        }
        if((map->walls+i)->y1 == (map->walls+i)->y2){ //divar e  ofoqi
            // az samte bala
            if(bullet->y < (map->walls+i)->y1 && bullet->y - 3 * sin(bullet->angle) > (map->walls+i)->y1 - 3.5 && bullet->x + 3 * cos(bullet->angle) > min((map->walls+i)->x2,(map->walls+i)->x1) - 2 && bullet->x + 3 * cos(bullet->angle) < max((map->walls+i)->x1 , (map->walls+i)->x2) + 2 )
                bullet->angle = - bullet->angle ;
            //az samte rast
            if(bullet->y > (map->walls+i)->y1 && bullet->y - 3 * sin(bullet->angle) < (map->walls+i)->y1 + 3.5 && bullet->x + 3 * cos(bullet->angle) > min((map->walls+i)->x2,(map->walls+i)->x1) - 2 && bullet->x + 3 * cos(bullet->angle) < max((map->walls+i)->x1 , (map->walls+i)->x2) + 2 )
                bullet->angle = - bullet->angle ;
        }
    }
}


void get_mine(Tank * tank ,Tank * tank_2,  Mine * mine,SDL_Renderer * renderer){
    if(sqrt(pow(tank->x - mine->x , 2) + pow(tank->y - mine->y , 2)) <= 22 ) {
        if (mine->owned == 0 && mine->plant == 0) {
            tank->powerup = 1;
            mine->owned = 1;
        }
    }
    if(sqrt(pow(tank->x - mine->x , 2) + pow(tank->y - mine->y , 2)) <= 27 ){
        if(mine->owned == 0 && mine->plant == 1){
            draw_mine(renderer,mine);
            tank_2->point += 1 ;
            mine->plant = 0 ;
            srand(time(0));
            mine->x = rand() % 700 + 7;
            mine->y = rand() % 715 + 7;
            tank->x = rand() % 700 + 7;
            tank->y = rand() % 715 + 7;
            tank_2->x = rand() % 700 + 7;
            tank_2->y = rand() % 715 + 7;
        }
    }

}
//
//bool check_location(Map * map, Tank * tank , int n){
//    for(int i = 0 ; i < n ; i++ ){
//        if((map->walls+i)->x1 == (map->walls+i)->x2){
//            if(abs(tank->x - (map->walls+i)->x1) <= 16.5 && tank->y >= min((map->walls+i)->y2,(map->walls+i)->y1) - 15 && tank->y <= max((map->walls+i)->y2,(map->walls+i)->y1) + 15  ){
//                return false ;
//            }
//        }
//        if((map->walls+i)->y1 == (map->walls+i)->y2){
//            if(abs(tank->y - (map->walls+i)->y1) <= 16.5 && tank->x >= min((map->walls+i)->x2,(map->walls+i)->x1) - 15 && tank->y <= max((map->walls+i)->x2,(map->walls+i)->x1) + 15  ){
//                return false ;
//            }
//        }
//        if(tank->x <= 300 || tank->y>= 723 || tank->x >= 705 || tank->y <= 200){
//            return false ;
//        }
//    }
//    return true;
//}


//bool movement_collids_walls(Map * map ,Tank * tank , int n){
//    for(int i = 0 ; i < n ; i ++){
//        //horizental
//        if((map->walls+i)->x1 == (map->walls + i)->x2 ){
//            if((map->walls + i)->y1  <= tank->y && tank->y <= (map->walls + i)->y2  && (map->walls+i)->x1 - 15 <= tank->x && tank->x <= (map->walls + i)->x1 + 15){
//                return false;
//            }
//        }
//        //vertical
//        if( (map->walls+i) -> y1 == (map->walls + i)->y2 ){
//            if( (map->walls + i)->x1 <= tank->x && tank->x <= (map->walls + i)->x2 && (map->walls + i)->y1 - 15 <= tank->y && tank->y <= (map->walls + i)->y1 + 15 ){
//                return false;
//            }
//        }
//    }
//    return true;
//}


