#ifndef GGAME_UTILS_H
#define GGAME_UTILS_H

typedef struct ordered_pair {
	/* Pares ordenados de la forma (a, b) := {{a},{a, b}} */
	float a;
	float ab;
} Point;

typedef struct four_points {
	// p
	float a;
	float ab;
	// q
	float c;
	float cd;
} Hitbox;

typedef struct shoot {
	float a;
	float ab;
	float vel;
} Shoot;

Point defPoint(float , float );
Hitbox defHitbox(float , float , float , float );
Hitbox defHitboxS(float, float, float );
Hitbox defHibox2P(Point , Point );

#endif
