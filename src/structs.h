//
// Created by Rosta Roghani on 2018-12-27.
//

#ifndef PROJECT_NAME_STRUCTS_H
#define PROJECT_NAME_STRUCTS_H

typedef struct{
    int x;
    int y;
    double angle;
    int shoot;
    int vanish;
}Bullet;
typedef struct {
    int x;
    int y;
    int point;
    double angle;
    Bullet *bullet;
    int number_of_shoots ;
    int powerup;
} Tank;
typedef struct{
    int x1;
    int x2;
    int y1;
    int y2;

}Wall;
typedef struct{
   //Tank * tanks;
    Wall * walls;
} Map;

typedef struct{
    int x ;
    int y ;
    int owned ;
    int plant ;
} Mine;
#endif //PROJECT_NAME_STRUCTS_H
