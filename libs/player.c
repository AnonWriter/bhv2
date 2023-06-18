#include "player.h"
#include <allegro5/allegro_primitives.h>

Shoot shoots[MAX_SHOOTS];
int nShoots = 0;

void draw_hitbox(Hitbox h, ALLEGRO_COLOR color){	
	al_draw_filled_rectangle(
				h.a,
				h.ab,
				h.c,
				h.cd,
				color
			);
}

void move(Hitbox *h, float fmov, float sfmov, float limw, float limh, ALLEGRO_KEYBOARD_STATE * state, ALLEGRO_COLOR color){
	float mov;

	bool left;
	bool right;
	bool up;
	bool down;
	bool shift;

	bool lim_l;
	bool lim_r;
	bool lim_u;
	bool lim_d;

	lim_l = h->a > 0;
	lim_r = h->c < limw;
	lim_u = h->ab > 0;
	lim_d = h->cd < limh;

	left = al_key_down(state, ALLEGRO_KEY_LEFT);
	right = al_key_down(state, ALLEGRO_KEY_RIGHT);
	up = al_key_down(state, ALLEGRO_KEY_UP);
	down = al_key_down(state, ALLEGRO_KEY_DOWN);

	shift = al_key_down(state, ALLEGRO_KEY_LSHIFT);

	(!shift) ? (mov = fmov) : (mov = sfmov);
	
	if(left && lim_l){
		h->a -= mov;
		h->c -= mov;
	}
	if(right && lim_r){
		h->a += mov;
		h->c += mov;
	}
	if(up && lim_u){
		h->ab -= mov;
		h->cd -= mov;
	}
	if(down && lim_d){
		h->ab += mov;
		h->cd += mov;
	}

	draw_hitbox(*h, color);
}

void shoot(int x, int y, int v, ALLEGRO_KEYBOARD_STATE * state){
	bool z;
	bool rlimit;

	rlimit = nShoots < MAX_SHOOTS;
	z = al_key_down(state, ALLEGRO_KEY_Z);

	if(z && rlimit){
		Shoot s;
		s.a = x;
		s.ab = y;
		s.vel = v;

		shoots[nShoots] = s;
		nShoots++;
	}
}

void refreshShoot(){
	for(int i = 0; i < nShoots; i++){
		Shoot *s = &shoots[i];

		s->ab -= s->vel;

		if(s->ab < 0){
			shoots[i] = shoots[nShoots - 1];
			nShoots--;
			i--;
		}
	}
}

void drawShoot(){
	for(int i = 0; i < nShoots; i++){
		Shoot *s = &shoots[i];

		al_draw_filled_circle(s->a, s->ab, 5, al_map_rgb(255, 255, 255));
	}
}

void shootControl(int x, int y, int v, ALLEGRO_KEYBOARD_STATE * state){
	shoot(x, y, v, state);
	refreshShoot();
	drawShoot();
}
