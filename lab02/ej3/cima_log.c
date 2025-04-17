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
    return (a[mid] > a[mid-1]) && (a[mid] > a[mid+1]);
}

int cima_rec(int a[], int lft, int rgt) {
    int res;
    int mid = (lft + rgt)/2;

    if (es_cima(a,mid) || mid == lft || mid == rgt) {
        res = mid;
    } else if (es_cima(a ,mid) && mid > 1) {
        res = cima_rec(a, lft, mid-1);
    } else if (es_cima(a, mid) && mid < rgt) {
        res = cima_rec(a, mid+1, rgt);
    } 

    return res;
}

int cima_log(int a[], int length) {  
    return cima_rec(a,0,length);
}