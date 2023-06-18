#include "player.h"
#include <allegro5/allegro_primitives.h>

int nShoots = 0;

void draw_hitbox(Hitbox h, ALLEGRO_COLOR color){
	/*
	al_draw_filled_rectangle(
				h.a,
				h.ab,
				h.c,
				h.cd,
				color
			);
	*/
	al_draw_filled_circle(
				h.a + 5,
				h.ab + 5,
				(h.c - h.a) / 2,
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
	if(!shift){
		mov = fmov;
	}
	else{
		mov = sfmov;
		color = al_map_rgb(255, 0, 0);
	}
	
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

void shoot(int x, int y, int v, ALLEGRO_KEYBOARD_STATE * state, Shoot * shoots){
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

void refreshShoot(Shoot * shoots, Enemy * e, int * score){
	for(int i = 0; i < nShoots; i++){
		Shoot *s = &shoots[i];
		s->collision = enemyCollision(e, s);
		if(s->collision){
			*score += SCORE_FACTOR;
			e->life--;
		}

		s->ab -= s->vel;

		if(s->ab < 0 || s->collision){
			shoots[i] = shoots[nShoots - 1];
			nShoots--;
			i--;
		}
	}
}

void drawShoot(Shoot * shoots){
	for(int i = 0; i < nShoots; i++){
		Shoot * s = &shoots[i];

		al_draw_filled_circle(s->a, s->ab, 3, al_map_rgb(255, 255, 255));
	}
}

void shootControl(int x, int y, int v, ALLEGRO_KEYBOARD_STATE * state, Shoot * shoots, Enemy * e, int * score){
	shoot(x, y, v, state, shoots);
	refreshShoot(shoots, e, score);
	drawShoot(shoots);
}

bool enemyCollision(Enemy * e, Shoot * shoot){
	bool collision;
	bool colx;
	bool coly;

	colx = (shoot -> a) > (e -> a) && (shoot -> a) < (e -> c);
	coly = (shoot -> ab) > (e -> ab) && (shoot -> ab) < (e -> cd);

	(colx && coly) ? (collision = true) : (collision = false);

	return collision;
}

bool checkQuit(ALLEGRO_KEYBOARD_STATE * state){
	bool q = al_key_down(state, ALLEGRO_KEY_ESCAPE);
	if(q) return true;
	return false;
}	

