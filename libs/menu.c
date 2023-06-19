#include "menu.h"
#include "ggame_utils.h"

#include <stdlib.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

void mainMenu(bool * quit, ALLEGRO_MOUSE_STATE * mstate, ALLEGRO_DISPLAY * display, ALLEGRO_FONT * tex){
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

	int mx, my;

	//char * starttext = "Jugar";
	//char * quittext = "Salir";

	Hitbox startbox = {500, 300, 650, 350};
	Hitbox quitbox = {520, 370, 670, 420};
	Hitbox gamebox = {540, 440, 690, 490};

	al_clear_to_color(al_map_rgb(0, 0, 0));

	while(!next){
		al_clear_to_color(al_map_rgb(0, 0, 0));
		
		al_get_mouse_state(mstate);
		mx = mstate->x;
		my = mstate->y;

		
		buttondown = al_mouse_button_down(mstate, 1);

		instartboxx = (mx > startbox.a) && (mx < startbox.c);
		instartboxy = (my > startbox.ab) && (my < startbox.cd);
		instartbox = instartboxx && instartboxy;

		inquitboxx = (mx > quitbox.a) && (mx < quitbox.c);
		inquitboxy = (my > quitbox.ab) && (my < quitbox.cd);
		inquitbox = inquitboxx && inquitboxy;

		ingameboxx = (mx > gamebox.a) && (mx < gamebox.c);
		ingameboxy = (my > gamebox.ab) && (my < gamebox.cd);
		ingamebox = ingameboxx && ingameboxy;

		//
		
		if(instartbox){
			al_draw_filled_rectangle(
				startbox.a, startbox.ab,
				startbox.c, startbox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(buttondown){
				(*quit) = false;
				next = true;
			}
		}

		if(inquitbox){
			al_draw_filled_rectangle(
				quitbox.a, quitbox.ab,
				quitbox.c, quitbox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(buttondown){
				(*quit) = true;
				next = true;
			}
		}

		if(ingamebox){
			al_draw_filled_rectangle(
				gamebox.a, gamebox.ab,
				gamebox.c, gamebox.cd,
				al_premul_rgba(255, 255, 0, 170)
			);
			if(buttondown){
			}
		}
		
		//
		al_draw_text(
			tex,
			al_map_rgb(255, 255, 255),
			100, 100,
			0,
			"Lluvia en Tlaco"
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
