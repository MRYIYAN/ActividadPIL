/**
 * @file imprimirTriangulos.c
 * @brief Funciones de impresión de triángulos.
 *
 * Imprime:
 * - Información básica
 * - Área, perímetro y baricentro
 * - Usará las funciones de geometría.c
 */

//==================================================================//
//                         IMPORTS                                 //
//==================================================================//

#include <stdio.h>
#include <math.h>
#include "estructuras.h"

//==================================================================//
//                         FUNCIONES                               //
//==================================================================//

/**
 * @brief Imprime la lista de triángulos con sus propiedades geométricas.
 *
 * @param triangulos Array de triángulos
 * @param numTriangulos Número de triángulos
 */
void imprimirTriangulos(triangulo *triangulos, unsigned numTriangulos)
{
    double suma = 0.0; // acumulador de areas para el resumen final
    unsigned i; // contador de triángulos procesados

    printf("\n"); // separador antes del bloque principal

    printf("===============================================================\n");
    printf("                 ANALISIS DE TRIANGULOS                        \n");
    printf("===============================================================\n");
    printf("Total de triangulos: %u\n", numTriangulos);
    printf("---------------------------------------------------------------\n");

    printf("%-8s %-8s %-18s %-18s %-22s\n",
           "ID", "CAPA", "AREA", "PERIMETRO", "BARICENTRO");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < numTriangulos; i++) {
        triangulo *t = &triangulos[i];
        double area = areaTriangulo(t);
        double peri = perimetroTriangulo(t);
        punto2D bari = baricentroTriangulo(t);

        suma += area;

        printf("%-8u %-8u %-18.15lf %-18.15lf (%.6lf, %.6lf)\n",
               t->ID, t->capa, area, peri, bari.x, bari.y);
    }

    printf("===============================================================\n");
    printf("Suma total de areas: %.15lf\n", suma);

    if (fabs(suma - 3.0) < 0.000001)
        printf("[ TODO CORRECTO ;)] La region es correcta (area = 3)\n");
    else
        printf("[INCORRECTO ;(] La suma de areas no coincide\n");

    printf("===============================================================\n\n");
}
