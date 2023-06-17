#ifndef PLAYER_H
#define PLAYER_H

/* Utilidades para manipular los datos del jugador */

struct coords {
	float x;
	float y;
};

struct hitbox {
	coords i;
	coords f;
};

#endif
