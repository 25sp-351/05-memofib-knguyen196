#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <stdio.h>

typedef long long ( *long_func_ptr ) (int param );

long long fibonacci( int of_num );
long long cache_func( int of_num );
long_func_ptr init_cache( long_func_ptr real_provider );

extern long_func_ptr fibonacci_provider;

#endif
// FIBONACCI_H