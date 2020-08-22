#include<iostream>

using namespace std;

#ifndef _KEY_STRUCT_H
#define _KEY_STRUCT_H

struct key_struct
{
    long long upper_lim;
    long long lower_lim;
    long long q;
    long long h; // g^a
    long long g;
    long long a;
    long long s; // p^a = h^k = g^ak
    long long p; // g^k
    long long k;
}; 

#endif