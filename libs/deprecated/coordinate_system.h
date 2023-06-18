/* Título		-	CoordinateSystem
 * Archivo 		- 	coordinate_system.h
 * Autor 		- 	Adiel Z(s).
 * Descripción 	- 	Utilidades para definir entes matemáticos en un plano cartesiano.
 					Definición de funciones para asignar y manipular las propiedades
				   	de los objetos con análisis vectorial.
 * Comentario	-	Reescrito de bh.c (código original)
 *
 */

#ifndef COORDINATE_SYSTEM_H
#define COORDINATE_SYSTEM_H

struct point {
	float x;
	float y;
};
typedef struct point Point;

struct line {
	Point p;
	Point q;
};
typedef struct line Line;

struct rect2p { // área rectangular definida por dos puntos
	Point ipos;
	Point fpos;
};
typedef struct rect2p Rect2P;

struct polygon {
	Point points[20];
};
typedef struct polygon Polygon;


/* Asignaciones y definiciones */
Point defPoint(float , float );
Rect2P defRect2P(Point , Point );
Rect2P defSquare2P(Point, float );
Polygon * defPolygon(const int , ...);

/* Operaciones entre entes matemáticos */
Point sumOfPoints(Point , Point );
Point scaledDirectionPoint(Point, float );
float scalarProductOfPoints(Point, Point );

#endif
