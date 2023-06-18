#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "libs/ggame_utils.h"
#include "libs/player.h"
#include "libs/enemy.h"

int main(){
	int w = 800;
	int h = 800;

	int score = 0;
	char score_text[27];
	char *text_var = score_text;
	char *stage = "Calles de Tlacotepec - Encuentro con el Nahual";
	char *label = "Puntaje:";

	bool quit = false;

	Hitbox player = defHitboxS(400, 400, 10);
	Enemy e = defEnemyS(275, 80, 60, 1671);
	Shoot shoots[MAX_SHOOTS];

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	al_install_keyboard();

	ALLEGRO_DISPLAY * display;
	display = al_create_display(w, h);

	ALLEGRO_KEYBOARD_STATE state;

	ALLEGRO_COLOR white 	= al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR black 	= al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR red 		= al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green		= al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue 		= al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR yellow 	= al_map_rgb(255, 255, 0);

	ALLEGRO_BITMAP * tlaco;
	tlaco = al_load_bitmap("./img/tlacobg.jpg");

	ALLEGRO_FONT * tex = al_load_ttf_font("./fonts/cmunci.ttf", 24, 0);
	ALLEGRO_FONT * tex11 = al_load_ttf_font("./fonts/cmunci.ttf", 16, 0);

	al_set_window_title(display, "Rainfall");

	while(!quit){
		al_clear_to_color(black);

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
		move(&player, 10, 4, w - 210, h, &state, green);
		shootControl(player.a + 10, player.ab, 30, &state, shoots, &e, &score);
		enemyControl(&e, SinusoidalMovement(), yellow, true, 1671);

		quit = checkQuit(&state);

		// dibujar puntaje
		sprintf(text_var, "%d", score);
		al_draw_text(tex, white, 630, 150, 0, label);
		al_draw_text(tex, white, 630, 174, 0, text_var);
		al_draw_text(tex11, white, 5, 5, 0, stage);

		// liberar memoria
		al_flip_display();
	}
	al_destroy_display(display);
	return 0;
}
