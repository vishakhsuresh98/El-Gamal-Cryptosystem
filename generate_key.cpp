#include <time.h>
#include <math.h>

#include "generate_key.h"
#include "key_struct.h"
#include "gcd.h"

/**
 * Generate a random kay of length equal to that of the plaintext
 * 
 * @param plaintext the plaintext, as a string in hexadecimal number system
 * @returns random key, as a string in hexadecimal number system
 */
long long generate_key(struct key_struct key)
{
	srand(time(NULL));

    long long a = rand() % (key.q - key.lower_lim) + key.lower_lim;
    while(gcd(a, key.q) != 1) {
        a = rand() % (key.q - key.lower_lim) + key.lower_lim;
    }
    return a;
}