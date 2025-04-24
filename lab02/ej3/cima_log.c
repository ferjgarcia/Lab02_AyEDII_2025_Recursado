#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool es_cima(int a[], int mid) {
    return a[mid] > a[mid - 1] && a[mid] > a[mid + 1];
}

int cima_rec(int a[], int lft, int rgt) {
    int mid = (lft + rgt) / 2;

    if (es_cima(a, mid)) {
        return mid;
    } else if (a[mid] > a[mid - 1]) {
        // Estamos en la parte creciente -> buscamos a la derecha
        return cima_rec(a, mid + 1, rgt);
    } else {
        // Estamos en la parte decreciente -> buscamos a la izquierda
        return cima_rec(a, lft, mid - 1);
    }
}

int cima_log(int a[], int length) {
    return cima_rec(a, 1, length - 2);  // Evitamos desbordes en a[mid +- 1]
}