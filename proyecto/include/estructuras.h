/**
 * @file estructuras.h
 * @brief Definición de estructuras y prototipos del proyecto.
 *
 * Contiene la declaración de las funciones
 */
#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

//==================================================================//
//                       TIPOS DE DATOS                             //
//==================================================================//

// punto2D guarda la posición en el plano y su identificador
typedef struct{
    double x, y;   // coordenadas del punto
    unsigned ID;   // id del punto
}punto2D;

// triangulo guarda punteros a los tres nodos que forman el triángulo
typedef struct{
    punto2D *nodo1, *nodo2, *nodo3; // punteros a los puntos del triángulo
    unsigned ID, capa;              // id del triángulo y capa del elemento
}triangulo;

//==================================================================//
//                       PROTOTIPOS                                  //
//==================================================================//

// lectura de datos
punto2D *leerPuntos(const char *nombreFichero, unsigned *numPuntos);
triangulo *leerTriangulos(const char *nombreFichero, punto2D *puntos, unsigned numPuntos, unsigned *numTriangulos);
punto2D *buscarPuntoPorId(punto2D *puntos, unsigned numPuntos, unsigned idBuscado);

// calculos geométricos
double distancia(punto2D *p1, punto2D *p2);
double areaTriangulo(triangulo *t);
double perimetroTriangulo(triangulo *t);
punto2D baricentroTriangulo(triangulo *t);

// impresión de resultados
void imprimirPuntos(punto2D *puntos, unsigned numPuntos);
void imprimirTriangulos(triangulo *triangulos, unsigned numTriangulos);

#endif
