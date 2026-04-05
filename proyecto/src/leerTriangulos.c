/**
 * @file leerTriangulos.c
 * @brief Funciones para leer triángulos desde fichero.
 *
 * Se encarga de:
 * - Leer triángulos desde archivo
 * - Enlazar los puntos mediante punteros
 */

//==================================================================//
//                         IMPORTS                                 //
//==================================================================//

#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "memoria.h"

//==================================================================//
//                         FUNCIONES                               //
//==================================================================//

/**
 * @brief Busca un punto por su identificador
 *
 * Recorre el array de puntos y devuelve un puntero al punto cuyo id coincide con el valor buscado según lo que entendí.
 *
 * @param puntos Array de puntos
 * @param numPuntos Número total de puntos
 * @param idBuscado Identificador del punto a buscar.
 * @return Puntero al punto encontrado o NULL si no existe.
 */
punto2D *buscarPuntoPorId(punto2D *puntos, unsigned numPuntos, unsigned idBuscado)
{
    unsigned i; // índice para buscar en el array

    // busco el punto con el ID solicitado
    for (i = 0; i < numPuntos; i++) {
        if (puntos[i].ID == idBuscado) {
            return &puntos[i]; // devuelvo la dirección del punto encontrado
        }
    }
    return NULL; // si no existe el ID, devuelvo NULL
}

/**
 * @brief Lee los triángulos desde el nombre del fichero de texto.
 *
 * Abre el fichero indicado, lee los datos de cada triángulo y reserva memoria dinámica para almacenarlos, además cada triángulo guarda punteros a los puntos que lo forman
 *
 * @param puntos Array de puntos previamente leído
 * @param numPuntos Número total de puntos
 * @param numTriangulos Dirección donde se guardará la cantidad de triángulos leídos
 * @return Puntero al array dinámico de triángulos
 */
triangulo *leerTriangulos(const char *nombreFichero, punto2D *puntos, unsigned numPuntos, unsigned *numTriangulos)
{
    FILE *fichero;               // fichero de entrada con datos de triángulos
    triangulo *triangulos;       // array dinámico de triángulos
    triangulo trianguloLeido;    // triángulo temporal para cada línea leída
    unsigned capacidad;          // capacidad actual del array de triángulos
    unsigned contador;           // número de triángulos leídos
    unsigned idNodo1;
    unsigned idNodo2;
    unsigned idNodo3;

    fichero = mifopen(nombreFichero, "r"); // abro el fichero de triángulos

    capacidad = 10; // empezamos con capacidad para 10 triángulos
    contador = 0;
    triangulos = mimalloc(capacidad * sizeof(triangulo));

    // leo cada triángulo en el fichero
    while (fscanf(fichero, "%u %u %u %u %u",
                  &trianguloLeido.ID,
                  &idNodo1,
                  &idNodo2,
                  &idNodo3,
                  &trianguloLeido.capa) == 5) {

        // si ya no cabe más, duplico la capacidad
        if (contador == capacidad) {
            capacidad = capacidad * 2;
            triangulos = mirealloc(triangulos, capacidad * sizeof(triangulo));
        }

        // enlazo los nodos del triángulo con los puntos leídos antes
        trianguloLeido.nodo1 = buscarPuntoPorId(puntos, numPuntos, idNodo1);
        trianguloLeido.nodo2 = buscarPuntoPorId(puntos, numPuntos, idNodo2);
        trianguloLeido.nodo3 = buscarPuntoPorId(puntos, numPuntos, idNodo3);

        triangulos[contador] = trianguloLeido; // guardo el triángulo en el array
        contador++;
    }

    // cierro el fichero cuando termino la lectura
    fclose(fichero);

    *numTriangulos = contador; // devuelvo el total de triángulos leídos

    // si no hubo triángulos, libero la memoria y devuelvo NULL
    if (contador == 0) {
        free(triangulos);
        return NULL;
    }

    // redimensiono al tamaño exacto para no desperdiciar memoria
    triangulos = mirealloc(triangulos, contador * sizeof(triangulo));

    return triangulos;
}
