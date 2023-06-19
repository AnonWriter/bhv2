#ifndef GGAME_UTILS_H
#define GGAME_UTILS_H

#include <stdbool.h>

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

typedef struct player {
	Hitbox h;
	int lives;
} Player;

typedef struct shoot {
	float a;
	float ab;
	float vel;
	bool collision;
} Shoot;

typedef struct enemy {
	float a;
	float ab;
	float c;
	float cd;

	int life;
	bool alive;
} Enemy;

Point defPoint(float , float );
Hitbox defHitbox(float , float , float , float );
Hitbox defHitboxS(float, float, float );
Hitbox defHibox2P(Point , Point );

typedef struct biparametrical_function {
	float x;
	float y;
} Function;

typedef struct vector2 {
	float a;
	float ab;
	float velx;
	float vely;
	bool collision;
} DShoot;

Enemy defEnemyS(float, float, float, float, bool);
Player defPlayerS(Hitbox h, int lives);

#endif
