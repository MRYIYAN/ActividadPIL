/**
 * @file mifopen.c
 * @brief Apertura segura de ficheros.
 *
 * Implementa una función para abrir archivos de forma segura.
 * Si ocurre un error al abrir el fichero, el programa finaliza
 * mostrando un mensaje por consola.
 */

//==================================================================//
//                         IMPORTS                                 //
//==================================================================//

#include <stdio.h>
#include <stdlib.h>

//==================================================================//
//                         FUNCIONES                               //
//==================================================================//



FILE *mifopen(const char *nombre, const char *modo)
{
    FILE *fp;

    // debe abrir el fichero con el modo que lo pasan
    if ((fp = fopen(nombre, modo)) == NULL) {
        printf("\nError in mifopen:");
        printf("\nFile %s could not be opened", nombre);
        printf("\nBye ...\n\n");
        exit(1);
    }
    else
        return fp; // si todo es correcto, devuelvo el puntero al archivo abierto
}
