#pragma once
#include <bits/stdc++.h>
using namespace std;
unsigned long long rollinghash_mod = (1ULL<<61) - 1;
inline unsigned long long mod_mul(unsigned long long a, unsigned long long b) {
    __uint128_t t = ( __uint128_t ) a * b;
    unsigned long long lo = (unsigned long long)t & rollinghash_mod;
    unsigned long long hi = (unsigned long long)(t >> 61);
    unsigned long long res = lo + hi;
    if (res >= rollinghash_mod) res -= rollinghash_mod;
    return res;
}
unsigned long long splitmix64(unsigned long long& x) {
    unsigned long long z = (x += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}
struct rollinghash {
    int n;
    unsigned long long base;
    vector<unsigned long long> power, data;
    rollinghash(const string& s) : n(s.size()), power(n+1), data(n+1) {
        unsigned long long seed = chrono::high_resolution_clock::now().time_since_epoch().count();
        base = splitmix64(seed) % (rollinghash_mod-1) + 1;
        power[0] = data[0] = 0;
        power[0] = 1;
        for(int i = 0; i < n; i++){
            power[i+1] = mod_mul(power[i], base);
            data[i+1] = mod_mul(data[i], base) + (unsigned char)s[i];
            if(data[i+1] >= rollinghash_mod) data[i+1] -= rollinghash_mod;
        }
    }
    // [l, r) のハッシュを求める O(1)
    unsigned long long hash(int l, int r) {
        unsigned long long res = data[r] + rollinghash_mod*4 - mod_mul(data[l], power[r-l]);
        res = (res >> 61) + (res & rollinghash_mod);
        if (res >= rollinghash_mod) res -= rollinghash_mod;
        return res;
    }
};