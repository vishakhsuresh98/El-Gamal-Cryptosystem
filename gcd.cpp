#include "gcd.h"

/**
 * Compute greatest common divisor of 2 numbers
 *
 * @param a the first input, as an int
 * @param b the second input, as an int 
 * @returns gcd of a and b
 */
int gcd(long long a, long long b)
{
    if (b == 0) 
      return a; 
    return gcd(b, a % b);
}