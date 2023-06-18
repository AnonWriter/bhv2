#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "libs/ggame_utils.h"
#include "libs/player.h"

int main(){
	int w = 800;
	int h = 800;

	Hitbox player = defHitboxS(400, 400, 20);

	al_init();
	al_install_keyboard();

	ALLEGRO_DISPLAY * display;
	display = al_create_display(w, h);

	ALLEGRO_KEYBOARD_STATE state;

	ALLEGRO_COLOR white = al_premul_rgba(255, 255, 255, 255);
	ALLEGRO_COLOR black = al_premul_rgba(0, 0, 0, 255);

	al_set_window_title(display, "Rainfall");

	while(1){
		al_clear_to_color(black);

		// registrar teclado
		al_get_keyboard_state(&state);

		// dibujisticos
		move(&player, 10, 4, w - 200, h, &state, white);
		shootControl(player.a + 10, player.ab, 25, &state);

		// liberar memoria
		al_flip_display();
	}
	al_destroy_display(display);
	return 0;
}
