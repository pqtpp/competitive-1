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
    \ namespace std;\nunsigned long long rollinghash_mod = (1ULL<<61) - 1;\ninline\
    \ unsigned long long mod_mul(unsigned long long a, unsigned long long b) {\n \
    \   __uint128_t t = ( __uint128_t ) a * b;\n    unsigned long long lo = (unsigned\
    \ long long)t & rollinghash_mod;\n    unsigned long long hi = (unsigned long long)(t\
    \ >> 61);\n    unsigned long long res = lo + hi;\n    if (res >= rollinghash_mod)\
    \ res -= rollinghash_mod;\n    return res;\n}\nunsigned long long splitmix64(unsigned\
    \ long long& x) {\n    unsigned long long z = (x += 0x9e3779b97f4a7c15ULL);\n\
    \    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;\n    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;\n\
    \    return z ^ (z >> 31);\n}\nstruct rollinghash {\n    int n;\n    unsigned\
    \ long long base;\n    vector<unsigned long long> power, hash;\n    rollinghash(const\
    \ string& s) : n(s.size()), power(n+1), hash(n+1) {\n        unsigned long long\
    \ seed = chrono::high_resolution_clock::now().time_since_epoch().count();\n  \
    \      base = splitmix64(seed) % (rollinghash_mod-1) + 1;\n        power[0] =\
    \ hash[0] = 0;\n        power[0] = 1;\n        for(int i = 0; i < n; i++){\n \
    \           power[i+1] = mod_mul(power[i], base);\n            hash[i+1] = mod_mul(hash[i],\
    \ base) + (unsigned char)s[i];\n            if(hash[i+1] >= rollinghash_mod) hash[i+1]\
    \ -= rollinghash_mod;\n        }\n    }\n    // [l, r) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u3092\u6C42\u3081\u308B O(1)\n    unsigned long long hash(int l, int r)\
    \ {\n        unsigned long long res = hash[r] + rollinghash_mod*4 - mod_mul(hash[l],\
    \ power[r-l]);\n        res = (res >> 61) + (res & rollinghash_mod);\n       \
    \ if (res >= rollinghash_mod) res -= rollinghash_mod;\n        return res;\n \
    \   }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\nunsigned long\
    \ long rollinghash_mod = (1ULL<<61) - 1;\ninline unsigned long long mod_mul(unsigned\
    \ long long a, unsigned long long b) {\n    __uint128_t t = ( __uint128_t ) a\
    \ * b;\n    unsigned long long lo = (unsigned long long)t & rollinghash_mod;\n\
    \    unsigned long long hi = (unsigned long long)(t >> 61);\n    unsigned long\
    \ long res = lo + hi;\n    if (res >= rollinghash_mod) res -= rollinghash_mod;\n\
    \    return res;\n}\nunsigned long long splitmix64(unsigned long long& x) {\n\
    \    unsigned long long z = (x += 0x9e3779b97f4a7c15ULL);\n    z = (z ^ (z >>\
    \ 30)) * 0xbf58476d1ce4e5b9ULL;\n    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;\n\
    \    return z ^ (z >> 31);\n}\nstruct rollinghash {\n    int n;\n    unsigned\
    \ long long base;\n    vector<unsigned long long> power, hash;\n    rollinghash(const\
    \ string& s) : n(s.size()), power(n+1), hash(n+1) {\n        unsigned long long\
    \ seed = chrono::high_resolution_clock::now().time_since_epoch().count();\n  \
    \      base = splitmix64(seed) % (rollinghash_mod-1) + 1;\n        power[0] =\
    \ hash[0] = 0;\n        power[0] = 1;\n        for(int i = 0; i < n; i++){\n \
    \           power[i+1] = mod_mul(power[i], base);\n            hash[i+1] = mod_mul(hash[i],\
    \ base) + (unsigned char)s[i];\n            if(hash[i+1] >= rollinghash_mod) hash[i+1]\
    \ -= rollinghash_mod;\n        }\n    }\n    // [l, r) \u306E\u30CF\u30C3\u30B7\
    \u30E5\u3092\u6C42\u3081\u308B O(1)\n    unsigned long long hash(int l, int r)\
    \ {\n        unsigned long long res = hash[r] + rollinghash_mod*4 - mod_mul(hash[l],\
    \ power[r-l]);\n        res = (res >> 61) + (res & rollinghash_mod);\n       \
    \ if (res >= rollinghash_mod) res -= rollinghash_mod;\n        return res;\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2025-05-02 05:27:31+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: string/rollinghash.hpp
---
