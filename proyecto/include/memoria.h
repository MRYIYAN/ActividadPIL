/**
 * @file memoria.h
 * @brief Funciones de gestión de memoria y ficheros.
 *
 * Declara las funciones auxiliares para:
 * - abrir ficheros con comprobación de errores
 * - reservar memoria dinámica de forma segura
 * - redimensionar memoria dinámica
 */
#ifndef MEMORIA_H
#define MEMORIA_H

//==================================================================//
//                         IMPORTS                                 //
//==================================================================//

#include <stdio.h>

//==================================================================//
//                       PROTOTIPOS                                 //
//==================================================================//

// abre un fichero y sale si no se puede abrir
FILE *mifopen(const char *nombre, const char *modo);

// reserva memoria y comprueba que malloc no devuelve NULL
void *mimalloc(unsigned tam);

// redimensiona un bloque de memoria y comprueba errores
void *mirealloc(void *ptr, unsigned tam);

#endif
