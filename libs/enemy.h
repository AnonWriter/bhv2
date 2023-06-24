#ifndef ENEMY_H
#define ENEMY_H

#include "ggame_utils.h"
#include <allegro5/allegro_color.h>

#define PI 3.1415
#define MAX_TRIG PI*10000

//#define MAX_ESHOOTS 200

void drawEnemy(Enemy , ALLEGRO_COLOR , ALLEGRO_BITMAP *, bool show_hitbox);
void drawLifeBar(Enemy , ALLEGRO_COLOR , float);
void destroyEnemy(Enemy * );
void enemyMovement(Enemy * , Function f, ALLEGRO_COLOR , bool, float, ALLEGRO_BITMAP * , bool show_hitbox);
void enemyControl(Enemy * , Function f, ALLEGRO_COLOR , bool, float, ALLEGRO_BITMAP * , bool show_hitbox);


void enemyShoot(float x, float y, float velx, float vely, Function f, DShoot * eshoots, bool shooting, int MAX_ESHOOTS);
void refreshEnemyShoot(DShoot * eshoots, Hitbox * player, int * lifes, ALLEGRO_TIMER * timer, Function f);
bool playerCollision(Hitbox h, DShoot * shoot, ALLEGRO_TIMER * timer);
void drawEnemyShoot(DShoot * eshoots);
void enemyShootControl(float x, float y, float velx, float vely, Function f, DShoot * eshoots, bool shooting, int MAX_ESHOOTS, Hitbox * player, int * lifes, ALLEGRO_TIMER * timer);

Function SinusoidalMovement(float a, float b, float c, float d, float e, float g, float h, float i);
Function SinusoidalMovementDerivative(float a, float b, float c, float d, float e, float g, float h, float i);
Function AbsSinusoidalMovement(float a, float b, float c, float d, float e, float g, float h, float i);
Function FollowPlayer(float a, float vel, Hitbox player, DShoot * cshoot);
Function RandomMovement(ALLEGRO_TIMER * timer);
void restartGlobalVarShoots();

#endif
