//
// Created by Rosta Roghani on 2018-12-27.
//

#ifndef PROJECT_NAME_VIEW_H
#define PROJECT_NAME_VIEW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_render.h>
#include "structs.h"
#include <stdbool.h>

void init_window(SDL_Renderer * renderer);
void quit_window(SDL_Window * window,SDL_Renderer * renderer);
void draw_tank(Tank *tank,SDL_Renderer * renderer);
void draw_tank_second(Tank *tank,SDL_Renderer * renderer);
//void handle_events(SDL_Window * window ,SDL_Renderer * renderer , Tank * tank_1, Tank * tank_2,Mine * mine, SDL_Event event,Map *map,int n,bool * z);
void handle_menu(SDL_Window * window ,SDL_Renderer * renderer ,Map * map , Tank * tank_1, Tank * tank_2,Mine * mine, int *pointer_1,int * pointer_2,bool * z);
void draw_bullet(Bullet * bullet,SDL_Renderer * renderer);
void draw_wall(Wall *wall,SDL_Renderer *renderer,int i);
void draw_menu(SDL_Renderer * renderer, int key);
void draw_mine(SDL_Renderer * renderer,Mine * mine);
void draw_table(SDL_Renderer * renderer , Tank * tank_1 , Tank * tank_2 , int time);
void draw_training(SDL_Renderer * renderer);
void save_file(Tank * tank_1 , Tank * tank_2,Mine * mine);
void handle_events(SDL_Window * window ,SDL_Renderer * renderer , Tank * tank_1, Tank * tank_2,Mine * mine, const Uint8 * state,Map *map,int n,bool * z);
#endif //PROJECT_NAME_VIEW_H
