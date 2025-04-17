#include <stdio.h>
#include <stdlib.h>
#include "k_esimo.h"

void array_dump(int a[], int length)
{
    fprintf(stdout, "[");
    for (int i = 0; i < length; i++)
    {
        fprintf(stdout, "%d", a[i]);
        
        if (i < length-1)
        {
            fprintf(stdout, ",");
        }
    }
    fprintf(stdout, "]\n");
}

int main(void) {
    int a[] = {8, 0, 9, -2, 13};
    int length = 5;
    int k = 3;
    int result;

    result = k_esimo(a, length, k);

    printf("Resultado: %i\n", result);
    array_dump(a, length);

    return EXIT_SUCCESS;
}
