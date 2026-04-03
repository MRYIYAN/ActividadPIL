/**
 * @file estructuras.h
 * @brief Definición de estructuras y prototipos del proyecto.
 *
 * Contiene la declaración de las funciones(de memoria) utilizadas en el programa.
 */
#define ESTRUCTURAS_H

typedef struct{
    double x, y;
    unsigned ID;
}punto2D;

typedef struct{
    punto2D *nodo1, *nodo2, *nodo3;
    unsigned ID, capa;
}triangulo;

punto2D *leerPuntos(const char *nombreFichero, unsigned *numPuntos);
triangulo *leerTriangulos(const char *nombreFichero, punto2D *puntos, unsigned numPuntos, unsigned *numTriangulos);
punto2D *buscarPuntoPorId(punto2D *puntos, unsigned numPuntos, unsigned idBuscado);
