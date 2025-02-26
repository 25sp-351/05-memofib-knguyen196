#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>


long_func_ptr fibonacci_provider;
long_func_ptr _original_provider;

#define MAX_MEMOIZED 91
#define ARRAY_SIZE (MAX_MEMOIZED+1)
#define NO_VALUE_YET -1

long long _memoization_data[ARRAY_SIZE];

// Recursive Fibonacci function
long long fibonacci( int of_num ) {
    printf( __FILE__ ":%2d   fibonacci(%d) called\n",__LINE__,
        of_num );

    if ( of_num == 0 ) return 0;
    if ( of_num == 1 ) return 1;

    return (*fibonacci_provider)(of_num-1) + (*fibonacci_provider)(of_num-2);
}

// Memoized Fibonacci function
long long cache_func(int of_num) {
    printf(__FILE__ ":%2d   cache_func(%d) called\n",__LINE__,
        of_num);

    if ( of_num > MAX_MEMOIZED )
        return (*_original_provider)(of_num);

    if ( _memoization_data[of_num] == NO_VALUE_YET )
    _memoization_data[of_num] = (*_original_provider)(of_num);

    return _memoization_data[of_num];
}

// Initialize the cache and sets up pointers for memoization
long_func_ptr init_cache(long_func_ptr real_provider) {
    for (int ix=0; ix<ARRAY_SIZE; ix++)
    _memoization_data[ix] = NO_VALUE_YET;

    _original_provider = real_provider;
    return cache_func;
}
