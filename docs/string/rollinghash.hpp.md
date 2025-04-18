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
  bundledCode: "#line 2 \"string/rollinghash.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nstruct rollinghash {\n    string data;\n    vector<long long>\
    \ rhash, power;\n    long long r;\n    rollinghash(string& s) : data(s), rhash(s.size()\
    \ + 1), power(s.size() + 1) {\n        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<long long> dist(1LL << 30, ((1LL << 61) - 2));\n\
    \        r = dist(rng) | 1;\n        rhash[0] = 0;\n        power[0] = 1;\n  \
    \      for (int i=0; i<s.size(); i++) {\n            rhash[i + 1] = mod(mul(rhash[i],\
    \ r) + s[i]);\n            power[i + 1] = mod(mul(power[i], r));\n        }\n\
    \    }\n    long long prod(int l, int r) {\n        return mod(rhash[r] - mul(rhash[l],\
    \ power[r - l]) + (1LL << 61) - 1);\n    }\n    long long mod(long long x) {\n\
    \        long long re = (x & ((1LL << 61) - 1)) + (x >> 61);\n        if (((1LL\
    \ << 61) - 1) <= re) re -= (1LL << 61) - 1;\n        return re;\n    }\n    long\
    \ long mul(long long a, long long b) {\n        __int128_t t = (__int128_t)a *\
    \ b;\n        return mod((t & ((1LL << 61) - 1)) + (t >> 61));\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nstruct rollinghash\
    \ {\n    string data;\n    vector<long long> rhash, power;\n    long long r;\n\
    \    rollinghash(string& s) : data(s), rhash(s.size() + 1), power(s.size() + 1)\
    \ {\n        static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<long long> dist(1LL << 30, ((1LL << 61) - 2));\n\
    \        r = dist(rng) | 1;\n        rhash[0] = 0;\n        power[0] = 1;\n  \
    \      for (int i=0; i<s.size(); i++) {\n            rhash[i + 1] = mod(mul(rhash[i],\
    \ r) + s[i]);\n            power[i + 1] = mod(mul(power[i], r));\n        }\n\
    \    }\n    long long prod(int l, int r) {\n        return mod(rhash[r] - mul(rhash[l],\
    \ power[r - l]) + (1LL << 61) - 1);\n    }\n    long long mod(long long x) {\n\
    \        long long re = (x & ((1LL << 61) - 1)) + (x >> 61);\n        if (((1LL\
    \ << 61) - 1) <= re) re -= (1LL << 61) - 1;\n        return re;\n    }\n    long\
    \ long mul(long long a, long long b) {\n        __int128_t t = (__int128_t)a *\
    \ b;\n        return mod((t & ((1LL << 61) - 1)) + (t >> 61));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2025-04-18 13:15:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: string/rollinghash.hpp
---
