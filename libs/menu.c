#include "menu.h"
#include "ggame_utils.h"
#include "player.h"
#include "enemy.h"

#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

void mainMenu(bool * quit, ALLEGRO_MOUSE_STATE * mstate, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * tex, bool * play, ALLEGRO_KEYBOARD_STATE * kstate, ALLEGRO_TIMER * timer){
	bool next = false;

	bool instartboxx;
	bool instartboxy;
	bool inquitboxx;
	bool inquitboxy;
	bool ingameboxx;
	bool ingameboxy;

	bool instartbox;
	bool inquitbox;
	bool ingamebox;

	bool buttondown;
	bool spacedown;
	bool upkey;
	bool downkey;

	int option = 0;
	bool cooldown;

	int mx, my;

	//char * starttext = "Jugar";
	//char * quittext = "Salir";

	Hitbox startbox = {500, 300, 650, 350};
	Hitbox quitbox = {520, 370, 670, 420};
	Hitbox gamebox = {540, 440, 690, 490};

	//al_clear_to_color(al_map_rgb(0, 0, 0));

	while(!next){
		al_clear_to_color(al_map_rgb(0, 0, 0));
		
		al_get_mouse_state(mstate);
		mx = mstate->x;
		my = mstate->y;

		al_get_keyboard_state(kstate);
		
		buttondown = al_mouse_button_down(mstate, 1);
		spacedown = al_key_down(kstate, ALLEGRO_KEY_SPACE);
		upkey = al_key_down(kstate, ALLEGRO_KEY_UP);
		downkey = al_key_down(kstate, ALLEGRO_KEY_DOWN);

		instartboxx = (mx > startbox.a) && (mx < startbox.c);
		instartboxy = (my > startbox.ab) && (my < startbox.cd);
		instartbox = instartboxx && instartboxy;

		inquitboxx = (mx > quitbox.a) && (mx < quitbox.c);
		inquitboxy = (my > quitbox.ab) && (my < quitbox.cd);
		inquitbox = inquitboxx && inquitboxy;

		ingameboxx = (mx > gamebox.a) && (mx < gamebox.c);
		ingameboxy = (my > gamebox.ab) && (my < gamebox.cd);
		ingamebox = ingameboxx && ingameboxy;

		cooldown = al_get_timer_count(timer) > 0;
		
		//
		if(downkey && option < 2 && cooldown){
			option++;
			al_stop_timer(timer);
			al_set_timer_count(timer, 0);
			al_start_timer(timer);
		}
		if(upkey && option > 0 && cooldown){
			option--;
			al_stop_timer(timer);
			al_set_timer_count(timer, 0);
			al_start_timer(timer);
		}
		
		//
		
		if(/*instartbox ||*/ option == 0){
			al_draw_filled_rectangle(
				startbox.a, startbox.ab,
				startbox.c, startbox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(/*buttondown ||*/ spacedown && cooldown){
				(*quit) = false;
				(*play) = false;
				next = true;
				al_stop_timer(timer);
				al_set_timer_count(timer, 0);
				al_start_timer(timer);
			}
		}

		if(/*inquitbox ||*/ option == 1){
			al_draw_filled_rectangle(
				quitbox.a, quitbox.ab,
				quitbox.c, quitbox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(/*buttondown ||*/ spacedown && cooldown){
				(*quit) = true;
				next = true;
				al_stop_timer(timer);
				al_set_timer_count(timer, 0);
				al_start_timer(timer);
			}
		}

		if(/*ingamebox ||*/ option == 2){
			al_draw_filled_rectangle(
				gamebox.a, gamebox.ab,
				gamebox.c, gamebox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(/*buttondown ||*/ spacedown){
			}
		}
		
		//
		al_draw_text(
			tex,
			al_map_rgb(255, 255, 255),
			100, 100,
			0,
			"Tlaco"
		);
		
		al_draw_text(
			tex,
			al_map_rgb(255, 255, 255),
			startbox.a + 30, startbox.ab + 10,
			0,
			"Jugar"
		);

		al_draw_text(
			tex,
			al_map_rgb(255, 255, 255),
			quitbox.a + 30, quitbox.ab + 10,
			0,
			"Salir"
		);

		al_draw_text(
			tex,
			al_map_rgb(255, 255, 255),
			gamebox.a + 30, gamebox.ab + 10,
			0,
			"Cambiar Juego"
		);

		//
		al_flip_display();

	}
}


void Pause(bool * quit, ALLEGRO_MOUSE_STATE * mstate, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * tex, ALLEGRO_KEYBOARD_STATE * kstate, ALLEGRO_TIMER * timer, bool * restart){
	bool continuar = false;

	bool inresumeboxx;
	bool inresumeboxy;
	bool inquittomainboxx;
	bool inquittomainboxy;
	bool inrestartboxx;
	bool inrestartboxy;

	bool inrestartbox;
	bool inquittomainbox;
	bool inresumebox;

	bool buttondown;
	bool spacedown;

	bool downkey;
	bool upkey;

	int option = 0;
	bool cooldown;

	int mx, my;

	//char * starttext = "Jugar";
	//char * quittext = "Salir";

	Hitbox resumebox = {500, 300, 650, 350};
	Hitbox quittomainbox = {520, 370, 670, 420};
	Hitbox restartbox = {540, 440, 690, 490};

	while(!continuar){
		al_clear_to_color(al_map_rgb(0, 0, 0));
		
		al_get_mouse_state(mstate);
		mx = mstate->x;
		my = mstate->y;

		al_get_keyboard_state(kstate);
		
		buttondown = al_mouse_button_down(mstate, 1);
		spacedown = al_key_down(kstate, ALLEGRO_KEY_SPACE);
		upkey = al_key_down(kstate, ALLEGRO_KEY_UP);
		downkey = al_key_down(kstate, ALLEGRO_KEY_DOWN);

		inresumeboxx = (mx > resumebox.a) && (mx < resumebox.c);
		inresumeboxy = (my > resumebox.ab) && (my < resumebox.cd);
		inresumebox = inresumeboxx && inresumeboxy;

		inquittomainboxx = (mx > quittomainbox.a) && (mx < quittomainbox.c);
		inquittomainboxy = (my > quittomainbox.ab) && (my < quittomainbox.cd);
		inquittomainbox = inquittomainboxx && inquittomainboxy;

		inrestartboxx = (mx > restartbox.a) && (mx < restartbox.c);
		inrestartboxy = (my > restartbox.ab) && (my < restartbox.cd);
		inrestartbox = inrestartboxx && inrestartboxy;

		cooldown = al_get_timer_count(timer) > 0;
		
		//
		if(downkey && option < 2 && cooldown){
			option++;
			al_stop_timer(timer);
			al_set_timer_count(timer, 0);
			al_start_timer(timer);
		}
		if(upkey && option > 0 && cooldown){
			option--;
			al_stop_timer(timer);
			al_set_timer_count(timer, 0);
			al_start_timer(timer);
		}

		//
		
		if(/*inresumebox ||*/ option == 0){
			al_draw_filled_rectangle(
				resumebox.a, resumebox.ab,
				resumebox.c, resumebox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(/*buttondown ||*/ spacedown && cooldown){
				(*quit) = false;
				continuar = true;
				al_stop_timer(timer);
				al_set_timer_count(timer, 0);
				al_start_timer(timer);
			}
		}
		else{
			al_draw_filled_rectangle(
				resumebox.a, resumebox.ab,
				resumebox.c, resumebox.cd,
				al_premul_rgba(0, 0, 0, 170)
			);
		}

		if(/*inquittomainbox ||*/ option == 1){
			al_draw_filled_rectangle(
				quittomainbox.a, quittomainbox.ab,
				quittomainbox.c, quittomainbox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(/*buttondown ||*/ spacedown && cooldown){
				(*quit) = true;
				continuar = true;
				al_stop_timer(timer);
				al_set_timer_count(timer, 0);
				al_start_timer(timer);
			}
		}
		else{
			al_draw_filled_rectangle(
				quittomainbox.a, quittomainbox.ab,
				quittomainbox.c, quittomainbox.cd,
				al_premul_rgba(0, 0, 0, 170)
			);
		}

		if(/*inrestartbox ||*/ option == 2){
			al_draw_filled_rectangle(
				restartbox.a, restartbox.ab,
				restartbox.c, restartbox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(/*buttondown ||*/ spacedown && cooldown){
				(*quit) = false;
				continuar = true;
				(*restart) = true;
				al_stop_timer(timer);
				al_set_timer_count(timer, 0);
				al_start_timer(timer);
			}
		}
		else{
			al_draw_filled_rectangle(
				restartbox.a, restartbox.ab,
				restartbox.c, restartbox.cd,
				al_premul_rgba(0, 0, 0, 170)
			);
		}
		
		//
		al_draw_text(
			tex,
			al_map_rgb(255, 255, 255),
			resumebox.a + 30, resumebox.ab + 10,
			0,
			"Continuar"
		);

		al_draw_text(
			tex,
			al_map_rgb(255, 255, 255),
			quittomainbox.a + 30, quittomainbox.ab + 10,
			0,
			"Menu"
		);

		al_draw_text(
			tex,
			al_map_rgb(255, 255, 255),
			restartbox.a + 30, restartbox.ab + 10,
			0,
			"Reiniciar"
		);

		//
		//al_flip_display();
		al_update_display_region(resumebox.a, resumebox.ab, resumebox.a - resumebox.c, resumebox.ab - resumebox.cd);
		al_update_display_region(quittomainbox.a, quittomainbox.ab, quittomainbox.a - quittomainbox.c, quittomainbox.ab - quittomainbox.cd);
		al_update_display_region(restartbox.a, restartbox.ab, restartbox.a - restartbox.c, restartbox.ab - restartbox.cd);

	}
}


void setShootArray(Shoot * arr, int msx){
	for (int i = 0; i < msx; i++){
		(arr + i)->a = 0.0;
		(arr + i)->ab = 0.0;
		(arr + i)->vel = 0.0;
		(arr + i)->collision = false;
	}
}

void setDShootArray(DShoot * arr, int msex){
	for (int i = 0; i < msex; i++){
		(arr + i)->a = 0.0;
		(arr + i)->ab = 0.0;
		(arr + i)->velx = 0.0;
		(arr + i)->vely = 0.0;
		(arr + i)->collision = false;
	}
}

void setAlltoZero(int * score, int * lifes,  bool * quit, bool * backtomain, bool * pause, Shoot * shoots, DShoot * enemy_shoots, Hitbox * player, Enemy * e, int msx, int msex, bool * restart){
		*score = 0;
		*lifes = 3;
		*quit = true;
		*backtomain = true;
		*pause = true;
		*restart = false;

		setShootArray(shoots, msx);
		setDShootArray(enemy_shoots, msex);

		*player = defHitboxS(400, 700, 8);
		*e = defEnemyS(275, 80, 50, 1671, true);
		
		restartGlobalVarShoots();
		restartGlobalVarPlayer();
}

void setRestart(int * score, int * lifes, Shoot * shoots, DShoot * enemy_shoots, Hitbox * player, Enemy * e, int msx, int msex, bool * restart){
		*score = 0;
		*lifes = 3;
		*restart = false;

		setShootArray(shoots, msx);
		setDShootArray(enemy_shoots, msex);

		*player = defHitboxS(400, 700, 8);
		*e = defEnemyS(275, 80, 50, 1671, true);
		
		restartGlobalVarShoots();
		restartGlobalVarPlayer();
}

