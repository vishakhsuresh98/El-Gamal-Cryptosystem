#include <time.h>
#include <string>
#include <math.h>

#include "key_struct.h"
#include "generate_key.h"
#include "encrypt.h"
#include "decrypt.h"
#include "large_pow_modulo.h"

// Driver program to test the above functions 
int main() 
{  
    srand(time(NULL));
    ifstream in_ptr;
    ofstream out_ptr;

    cout << "ElGamal" << endl;
    cout << "-------\n\n" << endl;

    // encryption process
    cout << "Encryption process :\n" << endl;
    string input;
    in_ptr.open("plaintext.txt"); 
    getline(in_ptr, input);
    int plaintext = stoi(input);
    cout << "Plaintext - " << plaintext << endl;

    struct key_struct key;

    // bob generates private key
    key.lower_lim = (long long)pow(10, 12);
    key.upper_lim = (long long)pow(10, 18);
    key.q = rand() % (key.upper_lim - key.lower_lim) + key.lower_lim;
    key.g = rand() % (key.q - 2) + 2; 
    key.a = generate_key(key);
    key.h = large_pow_modulo(key.g, key.a, key.q);

    long long ciphertext = encrypt(plaintext, key); 
    cout << "Ciphertext - " << ciphertext << endl; 
    cout << "\n\n";
    in_ptr.close();

    // decryption process
    cout << "Decryption process :\n" << endl;
    cout << "Ciphertext - " << ciphertext << endl; 
    plaintext = decrypt(ciphertext, key); 
    cout << "Plaintext - " << plaintext << endl; 
    cout << "\n";
    in_ptr.close();

    return 0; 
} 
