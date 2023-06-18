#include "enemy.h"
#include <math.h>
#include <allegro5/allegro_primitives.h>

int t = 0;

void drawEnemy(Enemy e, ALLEGRO_COLOR color){
	al_draw_filled_rectangle(
				e.a,
				e.ab,
				e.c,
				e.cd,
				color
			);
}

void drawLifeBar(Enemy e, ALLEGRO_COLOR color, float total){
	al_draw_line(
				e.a,
				e.ab - 7,
				e.a - ((((float)e.life)/total) * (e.a - e.c)),
				e.ab - 7,
				al_map_rgb(255, 255, 255),
				5
			);
}

void destroyEnemy(Enemy * e){
	e->a = 0;
	e->ab = 0;
	e->c = 0;
	e->cd = 0;
}

void enemyMovement(Enemy * e, Function f, ALLEGRO_COLOR color, bool life_bar, float total){
	bool limd;
	limd = e->a > 800; // destruir despues de dejar de ser visible

	e->a += f.x;
	e->ab += f.y;
	e->c += f.x;
	e->cd += f.y;

	drawEnemy(*e, color);
	if(life_bar) drawLifeBar(*e, color, total);
}

void enemyControl(Enemy * e, Function f, ALLEGRO_COLOR color, bool life_bar, float total){
	bool dead;
	dead = e->life < 0;
	if(!dead) enemyMovement(e, f, color, life_bar, total);
	else destroyEnemy(e);
}

Function SinusoidalMovement(){
	Function f;
	float v;
	if(t > MAX_TRIG) t = 0;

	v = (float)t / 60;
	f.x = 3.5*cos(v);
	f.y = 0.5*sin(v);

	t++;

	return f;
}
