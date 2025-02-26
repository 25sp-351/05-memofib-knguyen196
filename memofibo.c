#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

// BEGIN MAIN

int main(int argc, char *argv[]) {
    int test_val;

    if (argc < 2
            || 1 != sscanf(argv[1],"%d",&test_val)
            || test_val < 0)
        return 1;

    // PROGRAM INITIALIZATION
    fibonacci_provider = init_cache(fibonacci);

    
    // PROGRAM FUNCTIONALITY

    // how to use it
    for (int ix=0; ix <= test_val; ix++) {
        printf(__FILE__ ":%2d   Fibonacci of %d is %lld\n",__LINE__,
            ix,
            (*fibonacci_provider)(ix)
        );
    }

    return 0;
}