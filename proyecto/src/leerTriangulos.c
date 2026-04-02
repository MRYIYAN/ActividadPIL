/**
 * @file leerTriangulos.c
 * @brief Funciones para leer triángulos desde fichero.
 *
 * Se encarga de:
 * - Leer triángulos desde archivo
 * - Enlazar los puntos mediante punteros
 * - No me quedó claro lo siguiente en este punto: Además, guardar puntos y reservar la memoria.
 */

#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "memoria.h"

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
    unsigned i;

    for(i = 0; i < numPuntos; i++){
        if (puntos[i].id == idBuscado){
            return &puntos[i];
        }
    }
    return NULL;
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
    FILE *fichero;
    triangulo *triangulos;
    triangulo trianguloLeido;
    unsigned capacidad;
    unsigned contador;
    unsigned idNodo1;
    unsigned idNodo2;
    unsigned idNodo3;

    fichero = mifopen(nombreFichero, "r");

    capacidad = 10;
    contador = 0;
    triangulos = mimalloc(capacidad * sizeof(triangulo));

    while(fscanf(fichero, "%u %u %u %u %u",
                  &trianguloLeido.id,
                  &idNodo1,
                  &idNodo2,
                  &idNodo3,
                  &trianguloLeido.capa) == 5){

        if(contador == capacidad){
            capacidad = capacidad * 2;
            triangulos = mirealloc(triangulos, capacidad * sizeof(triangulo));
        }

        trianguloLeido.nodo1 = buscarPuntoPorId(puntos, numPuntos, idNodo1);
        trianguloLeido.nodo2 = buscarPuntoPorId(puntos, numPuntos, idNodo2);
        trianguloLeido.nodo3 = buscarPuntoPorId(puntos, numPuntos, idNodo3);

        triangulos[contador] = trianguloLeido;
        contador++;
    }

    fclose(fichero);

    *numTriangulos = contador;

    if (contador == 0){
        free(triangulos);
        return NULL;
    }

    triangulos = mirealloc(triangulos, contador * sizeof(triangulo));

    return triangulos;
}
