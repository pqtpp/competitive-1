#pragma once
#include "FFT"
#include <bits/stdc++.h>
using namespace std;
vector<double> convolution(const vector<double>& f, const vector<double>& g) {
    int n = 1;
    while (n < f.size() + g.size()) n <<= 1;
    vector<complex<double>> fa(f.begin(), f.end()), fb(g.begin(), g.end());
    fa.resize(n);
    fb.resize(n);
    fa = FFT(fa);
    fb = FFT(fb);
    for (int i=0; i<n; i++) fa[i] *= fb[i];
    fa = FFT(fa, true);
    vector<double> result(n);
    for (int i=0; i<n; i++) result[i] = fa[i].real()/n;
    return result;
}