#include <stdbool.h>
#include <stdio.h>
#include "k_esimo.h"

#define MAX_LENGTH 5
#define N_TESTCASES 10

struct testcase {
    int a[MAX_LENGTH];
    int length;
    int k;
    int result;
};

int main() {
    struct testcase tests[N_TESTCASES] = {
        // arreglo, largo, k, resultado esperado
        // 1. arreglo de un elemento (k = 0)
        { {8}, 1, 0, 8 },

        // 2. arreglo de dos elementos ordenados, con k = 0
        { {1, 5}, 2, 0, 1 },

        // 3. arreglo de dos elementos ordenados, con k = 1
        { {1, 5}, 2, 1, 5 },

        // 4. arreglo de dos elementos desordenados, con k = 0
        { {5, 1}, 2, 0, 1 },

        // 5. arreglo de dos elementos desordenados, con k = 1
        { {5, 1}, 2, 1, 5 },

        // 6. {8, -2, 9, 0, 13}, con k = 0 → menor
        { {8, -2, 9, 0, 13}, 5, 0, -2 },

        // 7. {8, -2, 9, 0, 13}, con k = 1 → segundo menor
        { {8, -2, 9, 0, 13}, 5, 1, 0 },

        // 8. {8, -2, 9, 0, 13}, con k = 2
        { {8, -2, 9, 0, 13}, 5, 2, 8 },

        // 9. {8, -2, 9, 0, 13}, con k = 3
        { {8, -2, 9, 0, 13}, 5, 3, 9 },

        // 10. {8, -2, 9, 0, 13}, con k = 4 → mayor
        { {8, -2, 9, 0, 13}, 5, 4, 13 },

    };
    int result;

    printf("TESTING k_esimo\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        result = k_esimo(tests[i].a, tests[i].length, tests[i].k);
        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }
    }

    return 0;
}
