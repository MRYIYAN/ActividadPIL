/**
 * @file main.c
 * @brief Programa principal del proyecto.
 *
 * Orquesta la ejecución del programa:
 * - Lee los puntos desde fichero
 * - Imprime los puntos
 * - Lee los triángulos
 * - Imprime los triángulos con sus propiedades
 */

#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

int main()
{
    unsigned npuntos, ntriang;
    punto2D *puntos;
    triangulo *triangulos;

    puntos = leerPuntos("puntos.txt", &npuntos);
    imprimirPuntos(puntos, npuntos);

    triangulos = leerTriangulos("triangulos.txt", puntos, npuntos, &ntriang);
    imprimirTriangulos(triangulos, ntriang);

    free(puntos);
    free(triangulos);

    printf("\n\n bye bye ...\n");

    return 0;
}
