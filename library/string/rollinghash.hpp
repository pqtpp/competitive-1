#pragma once
#include <bits/stdc++.h>
using namespace std;
struct rollinghash {
    string data;
    vector<long long> rhash, power;
    long long rn;
    rollinghash(string& s) : data(s), rhash(s.size() + 1), power(s.size() + 1) {
        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<long long> dist(1LL << 30, ((1LL << 61) - 2));
        rn = dist(rng) | 1;
        rhash[0] = 0;
        power[0] = 1;
        for (int i=0; i<s.size(); i++) {
            rhash[i + 1] = modul(mul(rhash[i], rn) + s[i]);
            power[i + 1] = modul(mul(power[i], rn));
        }
    }
    long long prod(int l, int r) {
        return modul(rhash[r] - mul(rhash[l], power[r - l]) + (1LL << 61) - 1);
    }
    long long modul(long long x) {
        long long re = (x & ((1LL << 61) - 1)) + (x >> 61);
        if (((1LL << 61) - 1) <= re) re -= (1LL << 61) - 1;
        return re;
    }
    long long mul(long long a, long long b) {
        __int128_t t = (__int128_t)a * b;
        return modul((t & ((1LL << 61) - 1)) + (t >> 61));
    }
};
