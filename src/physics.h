//
// Created by Rosta Roghani on 2018-12-27.
//

#ifndef PROJECT_NAME_PHYSICS_H
#define PROJECT_NAME_PHYSICS_H

#include <SDL_render.h>
#include "structs.h"

void move_tank(Map * map , Tank * tank  ,Tank * tank_2 , Mine * mine ,SDL_Renderer * renderer, int n);
void turn_tank(Tank *tank, int dir);
void move_bullet(Tank * attacker,Tank * destination,int *pointer_1 , int *pointer_2,Map * map, int n);
void fire(Tank *tank);
#endif //PROJECT_NAME_PHYSICS_H
