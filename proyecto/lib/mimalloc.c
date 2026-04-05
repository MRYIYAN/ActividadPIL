/**
 * @file mimalloc.c
 * @brief Reserva segura de memoria dinámica.
 *
 * Implementa una función para reservar memoria utilizando malloc.
 * Si la reserva falla, el programa finaliza mostrando un mensaje de error.
 * Si la reserva tiene éxito, devuelve un puntero al bloque de memoria reservado.
 */

//==================================================================//
//                         IMPORTS                                 //
//==================================================================//

#include <stdio.h>
#include <stdlib.h>

//==================================================================//
//                         FUNCIONES                               //
//==================================================================//

void *mimalloc(unsigned tam)
{
    void *ptr;

    // reservar memoria dinámica
    if ((ptr = malloc(tam)) == NULL) {
        printf("\nError in miealloc:");
        printf("\n Memory allocation failed! \n Bye...\n\n");
        exit(1);
    }
    else
        return ptr;
}
