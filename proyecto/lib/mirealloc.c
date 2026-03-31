/**
 * @file mirealloc.c
 * @brief Redimensionamiento seguro de memoria dinámica.
 *
 * Implementa una función para redimensionar memoria utilizando realloc.
 * Si la operación falla, el programa finaliza mostrando un mensaje de error.
 * Si la operación tiene éxito, devuelve un puntero al bloque de memoria redimensionado.
 */

#include <stdio.h>
#include <stdlib.h>

void *mirealloc(void *ptr, unsigned tam)
{
    void *p;

    if ((p = realloc(ptr, tam)) == NULL) {
        printf("\nError in mirealloc:");
        printf("\n Memory allocation failed! \n Bye...\n\n");
        exit(1);
    }
    else
        return p;
}
