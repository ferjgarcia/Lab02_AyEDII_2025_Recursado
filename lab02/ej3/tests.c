#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 8

int main() {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        //1
        { {8}, 1, 0 },
        //2
        { {1,8}, 2, 1 },
        //3 fail
        { {8,1}, 2, 0 },
        //4
        { {1,8,2}, 3, 1 },
        //5 fail
        { {1,3,8}, 3, 2 },
        //6 fail
        { {10,8,2}, 3, 0 },
        //7
        { {1,2,8,7}, 4, 2 },
        //8
        { {1,2,9,8,0}, 5, 2 },
    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
