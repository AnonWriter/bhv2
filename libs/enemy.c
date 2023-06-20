#include "enemy.h"
#include <math.h>
#include <allegro5/allegro_primitives.h>


int t = 0;

void drawEnemy(Enemy e, ALLEGRO_COLOR color, ALLEGRO_BITMAP * sprite, bool show_hitbox){
	al_draw_scaled_bitmap(
				sprite,
				0, 0,
				al_get_bitmap_width(sprite), al_get_bitmap_height(sprite),
				e.a - 5, e.ab - 5,
				60, 60,
				0
			);

	if (show_hitbox){
		al_draw_filled_rectangle(
					e.a,
					e.ab,
					e.c,
					e.cd,
					color
				);
	}
}

void drawLifeBar(Enemy e, ALLEGRO_COLOR color, float total){
	/*
	al_draw_line(
				e.a,
				e.ab - 7,
				e.a - ((((float)e.life)/total) * (e.a - e.c)),
				e.ab - 7,
				al_map_rgb(255, 255, 255),
				5
			);
	*/
	al_draw_arc(
				e.a + 25,
				e.ab + 25,
				50,
				0,
				-(2*PI) * ((float)e.life/total),
				al_map_rgb(255, 255, 255),
				4
			);
}

void destroyEnemy(Enemy * e){
	e->a = 0;
	e->ab = 0;
	e->c = 0;
	e->cd = 0;
}

void enemyMovement(Enemy * e, Function f, ALLEGRO_COLOR color, bool life_bar, float total, ALLEGRO_BITMAP * sprite, bool show_hitbox){
	bool limd;
	limd = e->a > 800; // destruir despues de dejar de ser visible

	e->a += f.x;
	e->ab += f.y;
	e->c += f.x;
	e->cd += f.y;

	drawEnemy(*e, color, sprite, show_hitbox);
	if(life_bar) drawLifeBar(*e, color, total);
}

void enemyControl(Enemy * e, Function f, ALLEGRO_COLOR color, bool life_bar, float total, ALLEGRO_BITMAP * sprite, bool show_hitbox){
	bool dead;
	dead = e->life < 1;
	if(!dead) enemyMovement(e, f, color, life_bar, total, sprite, show_hitbox);
	else{
		e->alive = false;
		destroyEnemy(e);
	}
}

int nEShoots = 0;
void enemyShoot(float x, float y, float velx, float vely, Function f, DShoot * eshoots, bool shooting, int MAX_ESHOOTS){
	bool rlimit;

	rlimit = nEShoots < MAX_ESHOOTS;

	if(shooting && rlimit){
		DShoot es;
		es.a = x;
		es.ab = y;
		es.velx = velx + f.x;
		es.vely = vely + f.y;

		eshoots[nEShoots] = es;
		nEShoots++;
	}
}

void refreshEnemyShoot(DShoot * eshoots, Hitbox * player, int * lifes, ALLEGRO_TIMER * timer){
	for(int i = 0; i < nEShoots; i++){
		//add player collision
		DShoot *es = &eshoots[i];
		//bool dlim;
		//dlim = s->ab > 800;

		es->a += es->velx;
		es->ab += es->vely;

		/*
		if(dlim){
			eshoots[i] = eshoots[0];
			nEShoots = 0;
			i--;
		}
		*/
		es->collision = playerCollision(*player, es, timer);
		if(es->collision){
			(*lifes)--;
		}
	}
}

bool playerCollision(Hitbox phx, DShoot * shoot, ALLEGRO_TIMER * timer){
	bool timecond;
	bool collision;
	bool colx;
	bool coly;

	timecond = al_get_timer_count(timer) > 2;

	colx = (shoot -> a) > (phx.a) && (shoot -> a) < (phx.c);
	coly = (shoot -> ab) > (phx.ab) && (shoot -> ab) < (phx.cd);
	collision = colx && coly && timecond;

	if(collision){
		al_stop_timer(timer);
		al_set_timer_count(timer, 0);
		al_start_timer(timer);
	}

	return collision;
}

void drawEnemyShoot(DShoot * eshoots){
	for(int i = 0; i < nEShoots; i++){
		DShoot * s = &eshoots[i];

		al_draw_filled_circle(s->a, s->ab, 3, al_map_rgb(0, 0, 255));
	}
}

void enemyShootControl(float x, float y, float velx, float vely, Function f, DShoot * eshoots, bool shooting, int MAX_ESHOOTS, Hitbox * player, int * lifes, ALLEGRO_TIMER * timer){
	enemyShoot(x, y, velx, vely, f, eshoots, shooting, MAX_ESHOOTS);
	refreshEnemyShoot(eshoots, player, lifes, timer);
	drawEnemyShoot(eshoots);
}

Function SinusoidalMovement(float a, float b, float c, float d, float e, float g, float h, float i){
	Function f;
	float v;
	if(t > MAX_TRIG) t = 0;

	v = (float)t / (2*PI);
	f.x = a*cos(c*v + e) + h;
	f.y = b*sin(d*v + g) + i;

	t++;

	return f;
}

Function AbsSinusoidalMovement(float a, float b, float c, float d, float e, float g, float h, float i){
	Function f;
	float v;
	if(t > MAX_TRIG) t = 0;

	v = (float)t / (2*PI);
	f.x = fabs(a*cos(c*v + e)) + h + -sqrt(2)/2;
	f.y = fabs(b*sin(d*v + g)) + i + 0;

	t++;

	return f;
}

Function FollowPlayer(float a, float vel, Hitbox player, Enemy e, ALLEGRO_TIMER * timer){
	Function f;
	if((al_get_timer_count(timer) % 2) == 0) {
	float diff = ((e.a + (e.c - e.a)/2) - (player.a + (player.a - player.c)/2))/60;
	f.x = -diff;
	}
	f.y = vel;

	return f;
}

void restartGlobalVarShoots(){
	nEShoots = 0;
	t = 0;
}
