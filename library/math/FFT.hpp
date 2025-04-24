#pragma once
#include <bits/stdc++.h>
using namespace std;
vector<complex<double>> FFT(vector<complex<double>> a){
    if(a.size() == 1) return a;
    vector<complex<double>> even(a.size()/2), odd(a.size()/2);
    for(int i=0; i<a.size()/2; i++){
        even[i] = a[i*2];
        odd[i] = a[i*2+1];
    }
    even = FFT(even);
    odd = FFT(odd);
    for(int i=0; i<a.size()/2; i++){
        odd[i] *= polar(1.0, 2 * M_PI * i / a.size());
        a[i] = even[i] + odd[i];
        a[a.size()/2+i] = even[i] - odd[i];
    }
    return a;
}