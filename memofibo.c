#include <stdio.h>

// caching (memoizing) version of the Fibonacci function
typedef long long ( *long_func_ptr )( int num );

long_func_ptr original_provider;

#define NOT_PRESENT -1
#define MAX 92

long long results[MAX] = { [0 ... MAX-1] = NOT_PRESENT };


long long cache( int val ) {
    if ( val < MAX ) {
        if ( results[val] == NOT_PRESENT )
            results[val] = ( *original_provider )( val );
        return results[val];
    }
    return ( *original_provider )( val );
}

long long fibonacci( int num ) {

    if ( num == 0 ) return 0;
    if ( num == 1 ) return 1;
    return cache( num-1 ) + cache( num-2 );
}

void input( long_func_ptr fibonacci_pointer ) {
    int n;
    while (1) {
        printf("Enter an integer (0 to 91)\n");
        if ( scanf("%d", &n) == 1 && n >= 0 && n < MAX ) {
            printf( "Fibonacci(%d) = %lld\n", n, fibonacci_pointer(n) );
            return;
        }
        printf( "Invalid input. Please enter a number between 0 and 91\n" );
        while ( getchar() != '\n' );
    }
}

int main(){
//install it in main

original_provider = fibonacci;
long_func_ptr fibonacci_pointer = cache;

input( fibonacci_pointer );
return 0;   

}

