#include "decrypt.h"
#include "key_struct.h"
#include "large_pow_modulo.h"

int decrypt(long long ciphertext, struct key_struct& key)
{
    int plaintext;
    key.h = large_pow_modulo(key.p, key.a, key.q);
    plaintext = ciphertext / key.h;
    return plaintext;
}