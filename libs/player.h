#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include "ggame_utils.h"

#define MAX_SHOOTS 200

void draw_hitbox(Hitbox h, ALLEGRO_COLOR color);
void move(Hitbox *h, float fmov, float sfmov, float limw, float limh, ALLEGRO_KEYBOARD_STATE * state, ALLEGRO_COLOR color);

void shoot(int x, int y, int v, ALLEGRO_KEYBOARD_STATE * state);
void refreshShoot();
void drawShoot();
void shootControl(int x, int y, int v, ALLEGRO_KEYBOARD_STATE * state);

#endif
