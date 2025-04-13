#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int length)
{
    bool r = false;

    for (int i = 0; i < length - 1; i++)
    {
        if (a[i] < a[i + 1] && !r)
        {
            r = true;
            i++;
        }
        else if (a[i] > a[i + 1] && r)
        {
            i++;
        }
        else
        {
            return false;
        }

        if (i + 1 == length - 1)
        {
            return true;
        }
    }

    return -1;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
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
int cima(int a[], int length)
{
    if (length == 1)
    {
        return a[0];
    }
    else if (length == 2)
    {
        if (a[0] > a[1])
        {
            return a[0];
        }
        else
        {
            return a[1];
        }
    }
    else
    {
        for (int i = 0; i < length - 2; i++)
        {
            if (a[i] < a[i + 1] && a[i + 1] > a[i + 2])
                return a[i + 1];
        }
    }

    return -1;
}
