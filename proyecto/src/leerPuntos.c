/**
 * @file leerPuntos.c
 * @brief Funciones para leer puntos desde fichero.
 *
 * Contiene la implementación de la función leerPuntos, encargada de la gestión de memoria dinámica y lectura de datos.
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
    FILE *fichero;            // puntero al fichero de entrada
    punto2D *puntos;          // array dinámico de puntos que vamos construyendo
    unsigned capacidad;       // capacidad actual del array dinámico
    unsigned contador;        // cuantos puntos hemos leído hasta ahora
    punto2D puntoLeido;       // punto temporal para cada línea leída

    // abro el fichero de forma segura usando mifopen
    fichero = mifopen(nombreFichero, "r");

    capacidad = 10; // empezamos con espacio para 10 puntos
    contador = 0;
    puntos = mimalloc(capacidad * sizeof(punto2D));

    // leo línea a línea hasta que no haya más datos válidos
    while (fscanf(fichero, "%u %lf %lf",
                  &puntoLeido.ID,
                  &puntoLeido.x,
                  &puntoLeido.y) == 3) {

        // si llegamos al límite de la capacidad, duplicamos el tamaño
        if (contador == capacidad) {
            capacidad = capacidad * 2;
            puntos = mirealloc(puntos, capacidad * sizeof(punto2D));
        }

        // guardo el punto leído en el array y avanzo el contador
        puntos[contador] = puntoLeido;
        contador++;
    }

    // cierro el fichero cuando termino la lectura
    fclose(fichero);

    // devuelvo la cantidad real de puntos leídos
    *numPuntos = contador;

    // redimensiono el array al tamaño exacto que necesitamos
    puntos = mirealloc(puntos, contador * sizeof(punto2D));

    return puntos;
}
