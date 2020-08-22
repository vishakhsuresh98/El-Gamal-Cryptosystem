#include <math.h>

#include "encrypt.h"
#include "key_struct.h"
#include "generate_key.h"
#include "large_pow_modulo.h"

long long encrypt(int plaintext, struct key_struct& key)
{
    // private key for sender
    key.k = generate_key(key); 
    key.s = large_pow_modulo(key.h, key.k, key.q); 
    key.p = large_pow_modulo(key.g, key.k, key.q);
    long long ciphertext = key.s * plaintext;
    return ciphertext;
}