#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include "ggame_utils.h"

#define MAX_SHOOTS 200
#define SCORE_FACTOR 7;

void draw_hitbox(Hitbox h, ALLEGRO_COLOR color);
void move(Hitbox *h, float fmov, float sfmov, float limw, float limh, ALLEGRO_KEYBOARD_STATE * state, ALLEGRO_COLOR color);

void shoot(int x, int y, int v, ALLEGRO_KEYBOARD_STATE * state, Shoot * shoots);
void refreshShoot(Shoot * shoots, Enemy * e, int * score);
void drawShoot(Shoot * shoots);
void shootControl(int x, int y, int v, ALLEGRO_KEYBOARD_STATE * state, Shoot * shoots, Enemy * e, int * score);
bool enemyCollision(Enemy * e, Shoot * shoots);

bool checkQuit(ALLEGRO_KEYBOARD_STATE * state);

#endif
