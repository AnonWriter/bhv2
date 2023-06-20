#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "libs/ggame_utils.h"
#include "libs/player.h"
#include "libs/enemy.h"
#include "libs/menu.h"

#define MAX_ESHOOTS 5000

//void setAlltoZero(int * score, int * lifes,  bool * quit, bool * backtomain, bool * pause, Shoot * shoots, DShoot * enemy_shoots, Hitbox * player, Enemy * e);
//void setShootArray(Shoot * arr);
//void setDShootArray(DShoot * arr);

int main(){
	int w = 800;
	int h = 800;

	int score = 0;
	char score_text[27];
	char lifes_text[7];
	char *text_var = score_text;
	char *stage = "Calles de Tlacotepec - Encuentro con el Nahual";
	char *label = "Puntaje:";
	char *labell = "Vidas:";

	int lifes = 3;

	bool quit = false;
	bool backtomain = false;
	bool pause = false;
	bool restart = false;

	Hitbox playerhitbox = defHitboxS(400, 700, 8);
	Player player = defPlayerS(playerhitbox, 3);

	Enemy e = defEnemyS(275, 80, 50, 1671, true);

	Shoot shoots[MAX_SHOOTS] = {0.0, 0.0, 0.0, false};
	DShoot enemy_shoots[MAX_ESHOOTS] = {0.0, 0.0, 0.0, 0.0, false};

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	al_install_keyboard();
	al_install_mouse();

	ALLEGRO_DISPLAY * display;
	display = al_create_display(w, h);

	ALLEGRO_KEYBOARD_STATE state;
	ALLEGRO_MOUSE_STATE mstate;

	ALLEGRO_TIMER * timer;
	timer = al_create_timer(1);

	ALLEGRO_TIMER * ptimer;
	ptimer = al_create_timer(0.150);

	ALLEGRO_COLOR white 	= al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR black 	= al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR red 		= al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green		= al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue 		= al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR yellow 	= al_map_rgb(255, 255, 0);

	ALLEGRO_BITMAP * tlaco;
	tlaco = al_load_bitmap("./img/tlacobg.jpg");

	ALLEGRO_BITMAP * sprite;
	sprite = al_load_bitmap("./img/ramen1.png");

	ALLEGRO_BITMAP * enemy_sprite;
	enemy_sprite = al_load_bitmap("./img/nahual.png");

	ALLEGRO_BITMAP * shoot_sprite;
	shoot_sprite = al_load_bitmap("./img/chohtos.png");

	ALLEGRO_FONT * tex = al_load_ttf_font("./fonts/cmunci.ttf", 24, 0);
	ALLEGRO_FONT * tex11 = al_load_ttf_font("./fonts/cmunci.ttf", 16, 0);

	al_set_window_title(display, "Tlacobullets");

	al_start_timer(timer);
	al_start_timer(ptimer);

	while(!quit){
		setAlltoZero(&score, &lifes, &quit, &backtomain, &pause, shoots, enemy_shoots, &playerhitbox, &e, MAX_SHOOTS, MAX_ESHOOTS, &restart);
		
		restartGlobalVarShoots();
		restartGlobalVarPlayer();

		mainMenu(&quit, &mstate, display, tex, &backtomain, &state, ptimer);

		while(!backtomain){
			al_clear_to_color(black);
			pause = al_key_down(&state, ALLEGRO_KEY_ESCAPE);
			if(pause) Pause(&backtomain, &mstate, display, tex, &state, ptimer, &restart);
			if(restart) setRestart(&score, &lifes, shoots, enemy_shoots, &playerhitbox, &e, MAX_SHOOTS, MAX_ESHOOTS, &restart);

	
			al_draw_scaled_bitmap(
				tlaco,
				0, 0,
				al_get_bitmap_width(tlaco), al_get_bitmap_height(tlaco),
				0, 0,
				600, 800,
				0
			);
	
			// registrar teclado
			al_get_keyboard_state(&state);
	
			// dibujisticos
			move(
				&playerhitbox,
				10, 3,
				w - 210, h,
				&state,
				green,
				sprite
			);
	
			shootControl(
				playerhitbox.a + 5,
				playerhitbox.ab,
				25,
				&state,
				shoots,
				&e,
				&score,
				shoot_sprite
			);
	
			enemyControl(
				&e,
				SinusoidalMovement(0, 0.25, 0, 0.1, 0, 0, 0, 0),
				yellow,
				true,
				1671,
				enemy_sprite,
				false
			);
	
			enemyShootControl(
				e.a + 25,
				e.ab + 30,
				0,
				0.001,
				SinusoidalMovement(2, 1.4, 1, 1, 0, 0, 0, 0), // a*cos(c*t + e) + h
				//FollowPlayer(0, 5, playerhitbox, e, timer),
				enemy_shoots,
				e.alive,
				MAX_ESHOOTS,
				&playerhitbox,
				&lifes,
				timer
			);

	
	
			// dibujar textp
			sprintf(text_var, "%d", score);
			al_draw_text(tex, white, 630, 150, 0, label);
			al_draw_text(tex, white, 630, 174, 0, text_var);
			al_draw_text(tex11, white, 5, 5, 0, stage);
	
			sprintf(lifes_text, "%d", lifes);
			al_draw_text(tex, white, 630, 210, 0, labell);
			al_draw_text(tex, white, 630, 234, 0, lifes_text);
	
			// liberar memoria
			al_flip_display();
		}

	}

	al_stop_timer(timer);
	al_stop_timer(ptimer);

	al_destroy_display(display);
	return 0;
}

