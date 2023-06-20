#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "ggame_utils.h"


void setAlltoZero(int * score, int * lifes,  bool * quit, bool * backtomain, bool * pause, Shoot * shoots, DShoot * enemy_shoots, Hitbox * player, Enemy * e, int msx, int msex, bool * restart);
void setRestart(int * score, int * lifes, Shoot * shoots, DShoot * enemy_shoots, Hitbox * player, Enemy * e, int msx, int msex, bool * restart);

void mainMenu(bool * quit, ALLEGRO_MOUSE_STATE * mstate, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * tex, bool * play, ALLEGRO_KEYBOARD_STATE * kstate, ALLEGRO_TIMER * timer);
void Pause(bool * quit, ALLEGRO_MOUSE_STATE * mstate, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * tex, ALLEGRO_KEYBOARD_STATE * kstate, ALLEGRO_TIMER * timer, bool * restart);
//

#endif
