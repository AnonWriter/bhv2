#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "ggame_utils.h"


void setAlltoZero(int * score, int * lifes,  bool * quit, bool * backtomain, bool * pause, Shoot * shoots, DShoot * enemy_shoots, Hitbox * player, Enemy * e, int msx, int msex, bool * restart, ALLEGRO_TIMER * t1, ALLEGRO_TIMER * t2, ALLEGRO_TIMER * t3, ALLEGRO_TIMER * t4);
void setRestart(int * score, int * lifes, Shoot * shoots, DShoot * enemy_shoots, Hitbox * player, Enemy * e, int msx, int msex, bool * restart, ALLEGRO_TIMER * t1, ALLEGRO_TIMER * t2, ALLEGRO_TIMER * t3, ALLEGRO_TIMER * t4);

void mainMenu(bool * quit, ALLEGRO_MOUSE_STATE * mstate, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * tex, bool * play, ALLEGRO_KEYBOARD_STATE * kstate, ALLEGRO_TIMER * timer, ALLEGRO_BITMAP * alebrije);
void Pause(bool * quit, ALLEGRO_MOUSE_STATE * mstate, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * tex, ALLEGRO_KEYBOARD_STATE * kstate, ALLEGRO_TIMER * timer, bool * restart);
void deadMenu(bool * quit, ALLEGRO_MOUSE_STATE * mstate, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * tex, ALLEGRO_KEYBOARD_STATE * kstate, ALLEGRO_TIMER * timer, bool * restart, char * score);
//
void setShootArray(Shoot * ,int msx);
void setDShootArray(DShoot * ,int msex);

#endif
