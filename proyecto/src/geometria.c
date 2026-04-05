/**
 * @file geometria.c
 * @brief Funciones de cálculo geométrico.
 *
 * Incluye funciones para:
 * - Distancia entre puntos
 * - Área de triángulos
 * - Perímetro
 * - Baricentro
 * - eje central de imprimirTriangulos.c
 */

#include <math.h>
#include "estructuras.h"

//==================================================================//
//                        FUNCIONES GEOMETRICAS                     //
//==================================================================//

/**
 * @brief Calcula la distancia entre dos puntos.
 *
 * @param p1 Primer punto
 * @param p2 Segundo punto
 * @return Distancia euclidiana entre los puntos
 */
double distancia(punto2D *p1, punto2D *p2)
{
    // calculo las diferencias en x e y
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;

    // uso la fórmula de distancia euclidiana
    return sqrt(dx * dx + dy * dy);
}

/**
 * @brief Calcula el área de un triángulo usando la fórmula de determinante.
 *
 * @param t Triángulo
 * @return Área del triángulo
 */
double areaTriangulo(triangulo *t)
{
    // extraigo las coordenadas de cada nodo
    double x1 = t->nodo1->x;
    double y1 = t->nodo1->y;
    double x2 = t->nodo2->x;
    double y2 = t->nodo2->y;
    double x3 = t->nodo3->x;
    double y3 = t->nodo3->y;

    // aplico la fórmula de área por determinante
    return 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

/**
 * @brief Calcula el perímetro de un triángulo.
 *
 * @param t Triángulo
 * @return Perímetro del triángulo
 */
double perimetroTriangulo(triangulo *t)
{
    // calculo cada lado usando la función de distancia
    double d1 = distancia(t->nodo1, t->nodo2);
    double d2 = distancia(t->nodo2, t->nodo3);
    double d3 = distancia(t->nodo3, t->nodo1);

    // el perímetro es la suma de los tres lados
    return d1 + d2 + d3;
}

/**
 * @brief Calcula el baricentro de un triángulo. 
 *
 * @param t Triángulo
 * @return Punto baricentro
 */
punto2D baricentroTriangulo(triangulo *t)
{
    punto2D b;

    // el baricentro es el promedio de las coordenadas de los tres nodos
    b.x = (t->nodo1->x + t->nodo2->x + t->nodo3->x) / 3.0;
    b.y = (t->nodo1->y + t->nodo2->y + t->nodo3->y) / 3.0; // 
    b.ID = 0; // el baricentro no necesita un ID real así que lo dejo en 0

    return b;
}