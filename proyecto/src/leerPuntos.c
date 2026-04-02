/**
 * @file leerPuntos.c
 * @brief Funciones para leer puntos desde fichero.
 *
 * Contiene la implementación de la función leerPuntos, encargada de la gestión de memoria dinámica y lectura de datos.
 */
#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "memoria.h"

/**
 * @brief Lee los puntos desde un fichero de texto y los almacena en memoria dinámica.
 *
 * Abre el fichero indicado, lee los identificadores y coordenadas de cada punto y en principio ("en principio") construye un array dinámico de estructuras punto2D. 
 * La cantidad de puntos leídos se devolverá mediante el parámetro numPuntos.
 *
 * @param numPuntos Dirección donde se guardará la cantidad de puntos leídos.
 * @return Puntero al array dinámico de puntos.
 */
punto2D *leerPuntos(const char *nombreFichero, unsigned *numPuntos)
{
    FILE *fichero;
    punto2D *puntos;
    unsigned capacidad;
    unsigned contador;
    punto2D puntoLeido;

    fichero = mifopen(nombreFichero, "r");

    capacidad = 10;
    contador = 0;
    puntos = mimalloc(capacidad * sizeof(punto2D));

    while (fscanf(fichero, "%u %lf %lf",
                  &puntoLeido.id,
                  &puntoLeido.x,
                  &puntoLeido.y) == 3) {

        if (contador == capacidad) {
            capacidad = capacidad * 2;
            puntos = mirealloc(puntos, capacidad * sizeof(punto2D));
        }

        puntos[contador] = puntoLeido;
        contador++;
    }

    fclose(fichero);

    *numPuntos = contador;

    puntos = mirealloc(puntos, contador * sizeof(punto2D));

    return puntos;
}
