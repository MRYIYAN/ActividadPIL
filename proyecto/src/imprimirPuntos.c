/**
 * @file imprimirPuntos.c
 * @brief Funciones de impresión de puntos.
 *
 * Muestra por consola la información de los puntos en formato estructurado
 */

//==================================================================//
//                         IMPORTS                                 //
//==================================================================//

#include <stdio.h>
#include "estructuras.h"

//==================================================================//
//                         FUNCIONES                               //
//==================================================================//

/**
 * @brief Imprime la lista de puntos en formato tabular.
 *
 * @param puntos Array de puntos
 * @param numPuntos Número de puntos
 */
void imprimirPuntos(punto2D *puntos, unsigned numPuntos)
{
    unsigned i; // contador para recorrer los puntos

    printf("\n");

    printf("███████ ███    ██  █████  ██      ██ ███████  █████  ██████   ██████  ██████  \n");
    printf("██   ██ ████   ██ ██   ██ ██      ██    ███  ██   ██ ██   ██ ██    ██ ██   ██ \n");
    printf("███████ ██ ██  ██ ███████ ██      ██   ███   ███████ ██   ██ ██    ██ ██████  \n");
    printf("██   ██ ██  ██ ██ ██   ██ ██      ██  ███    ██   ██ ██   ██ ██    ██ ██   ██ \n");
    printf("██   ██ ██   ████ ██   ██ ███████ ██ ███████ ██   ██ ██████   ██████  ██   ██ \n");

    printf("\n");

    printf("===============================================================\n");
    printf("              ANALISIS DE MALLA TRIANGULAR EN C                 \n");
    printf("===============================================================\n\n");

    printf("Total de puntos cargados: %u\n", numPuntos);
    printf("---------------------------------------------------------------\n");
    printf("%-8s %-22s %-22s\n", "ID", "X", "Y");
    printf("---------------------------------------------------------------\n");

    // imprimir TODOS los puntos con su ID y coordenadas en formato tabular aunque satura un poco la consola.....
    for (i = 0; i < numPuntos; i++) {
        printf("%-8u %-22.15lf %-22.15lf\n",
               puntos[i].ID,
               puntos[i].x,
               puntos[i].y);
    }

    printf("===============================================================\n\n");
}
