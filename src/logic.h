//
// Created by Rosta Roghani on 2018-12-27.
//

#ifndef PROJECT_NAME_LOGIC_H
#define PROJECT_NAME_LOGIC_H

#include "structs.h"
#include <stdbool.h>
#include <SDL_render.h>

bool movement_collids_walls(Map * map,Tank * tank ,int n);
int movement_collids_tanks(Bullet * bullet , Tank * attacker , Tank * destination ) ;
void bullet_hits_wall(Bullet * bullet , Map * map , int n ) ;
bool first_place (Map * map, Tank * tank, int n) ;
void get_mine(Tank * tank ,Tank * tank_2,  Mine * mine,SDL_Renderer * renderer);
bool check_location(Map * map, Tank * tank , int n);
#endif //PROJECT_NAME_LOGIC_H
