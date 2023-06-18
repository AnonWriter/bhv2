#ifndef ENEMY_H
#define ENEMY_H

#include "ggame_utils.h"
#include <allegro5/allegro_color.h>

#define PI 3.1415
#define MAX_TRIG PI*10000

void drawEnemy(Enemy , ALLEGRO_COLOR );
void drawLifeBar(Enemy , ALLEGRO_COLOR , float);
void destroyEnemy(Enemy * );
void enemyMovement(Enemy * , Function f, ALLEGRO_COLOR , bool, float);
void enemyControl(Enemy * , Function f, ALLEGRO_COLOR , bool, float);

Function SinusoidalMovement();

#endif
