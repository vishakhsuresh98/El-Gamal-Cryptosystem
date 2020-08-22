#include "large_pow_modulo.h"

long long large_pow_modulo(long long a, long long b, long long c)
{
    /**
     * if a^b = p*q, then (a^b)%c = ((p%c)*(q%c))%c
     */
    if(b == 1) {
        return a % c;
    }
    else if(b % 2 == 0) {
        // split into 2 equal halves
        long long result = large_pow_modulo(a, b / 2, c);
        return (result * result) % c; 
    }
    else {
        long long result1 = a % c;;
        long long result2 = large_pow_modulo(a, b - 1, c);
        return (result1 * result2) % c;
    }
}