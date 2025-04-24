---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/FFT.hpp
    title: math/FFT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/FFT.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nvector<complex<double>> FFT(vector<complex<double>> a, bool invert = false)\
    \ {\n    int n = a.size();\n    if (n == 1) return a;\n    vector<complex<double>>\
    \ even(n/2), odd(n/2);\n    for (int i=0; i<n/2; i++) {\n        even[i] = a[i*2];\n\
    \        odd[i] = a[i*2+1];\n    }\n    even = FFT(even, invert);\n    odd = FFT(odd,\
    \ invert);\n    double angle = 2 * M_PI / n * (invert ? -1 : 1);\n    complex<double>\
    \ w(1), wn = polar(1.0, angle);\n    for (int i=0; i<n/2; i++) {\n        complex<double>\
    \ t = w * odd[i];\n        a[i] = even[i] + t;\n        a[i+n/2] = even[i] - t;\n\
    \        w *= wn;\n    }\n    return a;\n}\n#line 4 \"math/convolution.hpp\"\n\
    using namespace std;\nvector<double> convolution(const vector<double>& f, const\
    \ vector<double>& g) {\n    int n = 1;\n    while (n < f.size() + g.size()) n\
    \ <<= 1;\n    vector<complex<double>> fa(f.begin(), f.end()), fb(g.begin(), g.end());\n\
    \    fa.resize(n);\n    fb.resize(n);\n    fa = FFT(fa);\n    fb = FFT(fb);\n\
    \    for (int i=0; i<n; i++) fa[i] *= fb[i];\n    fa = FFT(fa, true);\n    vector<double>\
    \ result(n);\n    for (int i=0; i<n; i++) result[i] = fa[i].real()/n;\n    return\
    \ result;\n}\n"
  code: "#pragma once\n#include \"FFT\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nvector<double> convolution(const vector<double>& f, const vector<double>&\
    \ g) {\n    int n = 1;\n    while (n < f.size() + g.size()) n <<= 1;\n    vector<complex<double>>\
    \ fa(f.begin(), f.end()), fb(g.begin(), g.end());\n    fa.resize(n);\n    fb.resize(n);\n\
    \    fa = FFT(fa);\n    fb = FFT(fb);\n    for (int i=0; i<n; i++) fa[i] *= fb[i];\n\
    \    fa = FFT(fa, true);\n    vector<double> result(n);\n    for (int i=0; i<n;\
    \ i++) result[i] = fa[i].real()/n;\n    return result;\n}"
  dependsOn:
  - math/FFT.hpp
  isVerificationFile: false
  path: math/convolution.hpp
  requiredBy: []
  timestamp: '2025-04-24 08:17:52+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution.hpp
layout: document
redirect_from:
- /library/math/convolution.hpp
- /library/math/convolution.hpp.html
title: math/convolution.hpp
---
