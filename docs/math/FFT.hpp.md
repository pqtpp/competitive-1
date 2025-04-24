---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/FFT.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nvector<complex<double>> FFT(vector<complex<double>> a){\n    if(a.size()\
    \ == 1) return a;\n    vector<complex<double>> even(a.size()/2), odd(a.size()/2);\n\
    \    for(int i=0; i<a.size()/2; i++){\n        even[i] = a[i*2];\n        odd[i]\
    \ = a[i*2+1];\n    }\n    even = FFT(even);\n    odd = FFT(odd);\n    for(int\
    \ i=0; i<a.size()/2; i++){\n        odd[i] *= polar(1.0, 2 * M_PI * i / a.size());\n\
    \        a[i] = even[i] + odd[i];\n        a[a.size()/2+i] = even[i] - odd[i];\n\
    \    }\n    return a;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nvector<complex<double>>\
    \ FFT(vector<complex<double>> a){\n    if(a.size() == 1) return a;\n    vector<complex<double>>\
    \ even(a.size()/2), odd(a.size()/2);\n    for(int i=0; i<a.size()/2; i++){\n \
    \       even[i] = a[i*2];\n        odd[i] = a[i*2+1];\n    }\n    even = FFT(even);\n\
    \    odd = FFT(odd);\n    for(int i=0; i<a.size()/2; i++){\n        odd[i] *=\
    \ polar(1.0, 2 * M_PI * i / a.size());\n        a[i] = even[i] + odd[i];\n   \
    \     a[a.size()/2+i] = even[i] - odd[i];\n    }\n    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/FFT.hpp
  requiredBy: []
  timestamp: '2025-04-24 07:49:16+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/FFT.hpp
layout: document
redirect_from:
- /library/math/FFT.hpp
- /library/math/FFT.hpp.html
title: math/FFT.hpp
---
