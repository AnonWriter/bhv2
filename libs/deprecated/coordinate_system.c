/* Título		-	CoordinateSystem
 * Archivo 		- 	coordinate_system.c
 * Autor 		- 	Adiel Z(s).
 * Descripción 	- 	Utilidades para definir entes matemáticos en un plano cartesiano.
 					Definición de funciones para asignar y manipular las propiedades
				   	de los objetos con análisis vectorial.
 * Comentario	-	Reescrito de bh.c (código original)
 *
 */

#include "coordinate_system.h"
#include <stdarg.h>

/* Operaciones con puntos */
Point defPoint(float a, float b){
	Point p;
	p.x = a;
	p.y = b;
	return p;
}

Point sumOfPoints(Point p, Point q){
	Point r;
	r.x = p.x + q.x;
   	r.y = p.y + q.y;
	return r;
}

Point scaledDirectionPoint(Point p, float m){
	p.x *= m;
	p.y *= m;
	return p;
}

float scalarProductOfPoints(Point p, Point q){
	float result;
	result = (p.x * q.x) + (p.y * q.y);
	return result;
}

/* Operaciones con rectángulo de dos puntos */
Rect2P defRect2P(Point a, Point b){
	Rect2P rect;
	rect.ipos = a;
	rect.fpos = b;
	return rect;
}

Rect2P defSquare2P(Point a, float length_side){
	Rect2P square;
	Point p = defPoint(length_side, length_side);
	Point b = sumOfPoints(a, b);

	square.ipos = a;
	square.fpos = b;
	return square;
}

Polygon * defPolygon(const int n, ...){
	va_list list;
	int i;
	Polygon *f;

	va_start(list, n);
	for(i = 0; i < n; i++){
		(*f).points[i] = va_arg(list, Point);
	}

	va_end(list);

	return f;
}
