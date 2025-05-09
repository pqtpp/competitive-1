#pragma once
#include "NTT"
#include <bits/stdc++.h>
using namespace std;
vector<int> convolution(vector<int>& a, vector<int>& b) {
    int n=1;
    while (n < a.size() + b.size() - 1) n <<= 1;
    vector<mint> A(n), B(n);
    for (int i=0; i<a.size(); i++) {
        A[i] = mint(a[i]);
    }
    for (int i=0; i<b.size(); i++) {
        B[i] = mint(b[i]);
    }
    ntt(A, false);
    ntt(B, false);
    for (int i=0; i<n; i++) {
        A[i] *= B[i];
    }
    ntt(A, true);
    vector<int> re(a.size()+b.size()-1);
    for (int i=0; i<a.size()+b.size()-1; i++) {
        re[i] = A[i].val;
    }
    return re;
}