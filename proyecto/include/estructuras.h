/**
 * @file estructuras.h
 * @brief Definición de estructuras y prototipos del proyecto.
 *
 * Contiene la declaración de las funciones(de memoria) utilizadas en el programa.
 */
typedef struct{
    double x, y;
    unsigned ID;
}punto2D;

typedef struct{
    punto2D *nodo1, *nodo2, *nodo3;
    unsigned ID, capa;
}triangulo;
