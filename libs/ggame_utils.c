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
