#include "ggame_utils.h"

Point defPoint(float x, float y){
	Point point;
	point.a 	= x;
	point.ab 	= y;
	return point;
}

Hitbox defHitbox(float a, float ab, float c, float cd){
	Hitbox h;
	h.a = a;
	h.ab = ab;
	h.c = c;
	h.cd = cd;
	return h;
}

Hitbox defHitboxS(float a, float ab, float lside){
	Hitbox h;
	h.a = a;
	h.ab = ab;
	h.c = a + lside;
	h.cd = ab + lside;
	return h;
}

Hitbox defHitbox2P(Point p, Point q){
	Hitbox h;
	h.a = p.a;
	h.ab = p.ab;
	h.c = q.a;
	h.cd = q.ab;
	return h;
}

Enemy defEnemyS(float a, float ab, float lside, float life, bool alive){
	Enemy e;
	e.a = a;
	e.ab = ab;
	e.c = a + lside;
	e.cd = ab + lside;
	e.life = life;
	e.alive = alive;
	return e;
}

Player defPlayerS(Hitbox h, int lives){
	Player p;
	p.h = h;
	p.lives = lives;
	return p;
}
