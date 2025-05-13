---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/NTT.hpp
    title: math/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: math/convolution.hpp
    title: math/convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod.test.cpp
    title: verify/yosupo-convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite.test.cpp
    title: verify/yosupo-point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite_large_array.test.cpp
    title: verify/yosupo-point_set_range_composite_large_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_point_get.test.cpp
    title: verify/yosupo-range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_range_sum.test.cpp
    title: verify/yosupo-range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nlong long modint_MOD = 998244353;\n// mod \u306E\u5024\u3092\u5909\u66F4\
    \u3059\u308B(\u30C7\u30D5\u30A9\u30EB\u30C8\u306F998244353)\nvoid setmod(long\
    \ long x) { modint_MOD = x; }\nstruct mint {\n    long long val;\n    mint(long\
    \ long x=0) {\n        val=(x%modint_MOD+modint_MOD)%modint_MOD;\n    }\n    mint&\
    \ operator+=(const mint& a) { val = (val + a.val) % modint_MOD; return *this;\
    \ }\n    mint& operator-=(const mint& a) { val = (val - a.val + modint_MOD) %\
    \ modint_MOD; return *this; }\n    mint& operator*=(const mint& a) { val = val\
    \ * a.val % modint_MOD ; return *this; }\n    mint& operator/=(const mint& a)\
    \ { return *this *= a.inv(); }\n    mint operator+(const mint& a) const { return\
    \ mint(*this) += a; }\n    mint operator-(const mint& a) const { return mint(*this)\
    \ -= a; }\n    mint operator*(const mint& a) const { return mint(*this) *= a;\
    \ }\n    mint operator/(const mint& a) const { return mint(*this) /= a; }\n  \
    \  bool operator==(const mint& a) const { return val == a.val; }\n    bool operator!=(const\
    \ mint& a) const { return val != a.val; }\n    mint& operator+=(int a) { return\
    \ *this += mint(a); }\n    mint& operator-=(int a) { return *this -= mint(a);\
    \ }\n    mint& operator*=(int a) { return *this *= mint(a); }\n    mint& operator/=(int\
    \ a) { return *this /= mint(a); }\n    mint operator+(int a) const { return mint(*this)\
    \ += a; }\n    mint operator-(int a) const { return mint(*this) -= a; }\n    mint\
    \ operator*(int a) const { return mint(*this) *= a; }\n    mint operator/(int\
    \ a) const { return mint(*this) /= a; }\n    bool operator==(int a) const { return\
    \ val == mint(a).val; }\n    bool operator!=(int a) const { return val != mint(a).val;\
    \ }\n    friend mint operator+(int a,const mint& b) { return mint(a) + b; }\n\
    \    friend mint operator-(int a,const mint& b) { return mint(a) - b; }\n    friend\
    \ mint operator*(int a,const mint& b) { return mint(a) * b; }\n    friend mint\
    \ operator/(int a,const mint& b) { return mint(a) / b; }\n    friend bool operator==(int\
    \ a, const mint& b) { return mint(a) == b; }\n    friend bool operator!=(int a,\
    \ const mint& b) { return mint(a) != b; }\n    mint& operator++() { return *this\
    \ += 1; }\n    mint operator++(int) { mint r = *this; *this += 1; return r; }\n\
    \    mint& operator--() { return *this -= 1; }\n    mint operator--(int) { mint\
    \ r = *this; *this -= 1; return r; }\n    // modpow \u3092\u8A08\u7B97\u3059\u308B\
    \u3002\u8A08\u7B97\u91CFO(log mod)\n    mint pow(long long n) const {\n      \
    \  if (n != 0) n = ((n-2) % (modint_MOD-1) + modint_MOD) % (modint_MOD-1) + 1;\n\
    \        mint r = 1, a = *this;\n        while (n) {\n            if (n & 1) r\
    \ *= a;\n            a *= a;\n            n >>= 1;\n        }\n        return\
    \ r;\n    }\n    mint inv() const { return pow(-1); }\n    friend ostream& operator<<(ostream&s,\
    \ const mint& a) { return s << a.val; }\n    friend istream& operator>>(istream&s,\
    \ mint& a) { long long x; s >> x; a = mint(x); return s; }\n};\nvector<mint>fac,\
    \ ifac;\n// n \u307E\u3067\u306E\u968E\u4E57\u3092\u524D\u8A08\u7B97\u3059\u308B\
    \u3002O(n)\nvoid buildfac(int n) {\n    fac.resize(n + 1);\n    ifac.resize(n\
    \ + 1);\n    fac[0] = 1;\n    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n\
    \    ifac[n] = mint(1) / fac[n];\n    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i]\
    \ * i;\n}\n// nCk \u3092\u6C42\u3081\u308B\u3002buildfac\u306E\u547C\u3073\u51FA\
    \u3057\u304C\u5FC5\u9808\u3002O(1)\nmint comb(int n,int k) { return (0 <= k &&\
    \ k <= n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }\n// nPk \u3092\u6C42\u3081\u308B\
    \u3002buildfac\u306E\u547C\u3073\u51FA\u3057\u304C\u5FC5\u9808\u3002O(1)\nmint\
    \ perm(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] : 0; }\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\nlong long modint_MOD\
    \ = 998244353;\n// mod \u306E\u5024\u3092\u5909\u66F4\u3059\u308B(\u30C7\u30D5\
    \u30A9\u30EB\u30C8\u306F998244353)\nvoid setmod(long long x) { modint_MOD = x;\
    \ }\nstruct mint {\n    long long val;\n    mint(long long x=0) {\n        val=(x%modint_MOD+modint_MOD)%modint_MOD;\n\
    \    }\n    mint& operator+=(const mint& a) { val = (val + a.val) % modint_MOD;\
    \ return *this; }\n    mint& operator-=(const mint& a) { val = (val - a.val +\
    \ modint_MOD) % modint_MOD; return *this; }\n    mint& operator*=(const mint&\
    \ a) { val = val * a.val % modint_MOD ; return *this; }\n    mint& operator/=(const\
    \ mint& a) { return *this *= a.inv(); }\n    mint operator+(const mint& a) const\
    \ { return mint(*this) += a; }\n    mint operator-(const mint& a) const { return\
    \ mint(*this) -= a; }\n    mint operator*(const mint& a) const { return mint(*this)\
    \ *= a; }\n    mint operator/(const mint& a) const { return mint(*this) /= a;\
    \ }\n    bool operator==(const mint& a) const { return val == a.val; }\n    bool\
    \ operator!=(const mint& a) const { return val != a.val; }\n    mint& operator+=(int\
    \ a) { return *this += mint(a); }\n    mint& operator-=(int a) { return *this\
    \ -= mint(a); }\n    mint& operator*=(int a) { return *this *= mint(a); }\n  \
    \  mint& operator/=(int a) { return *this /= mint(a); }\n    mint operator+(int\
    \ a) const { return mint(*this) += a; }\n    mint operator-(int a) const { return\
    \ mint(*this) -= a; }\n    mint operator*(int a) const { return mint(*this) *=\
    \ a; }\n    mint operator/(int a) const { return mint(*this) /= a; }\n    bool\
    \ operator==(int a) const { return val == mint(a).val; }\n    bool operator!=(int\
    \ a) const { return val != mint(a).val; }\n    friend mint operator+(int a,const\
    \ mint& b) { return mint(a) + b; }\n    friend mint operator-(int a,const mint&\
    \ b) { return mint(a) - b; }\n    friend mint operator*(int a,const mint& b) {\
    \ return mint(a) * b; }\n    friend mint operator/(int a,const mint& b) { return\
    \ mint(a) / b; }\n    friend bool operator==(int a, const mint& b) { return mint(a)\
    \ == b; }\n    friend bool operator!=(int a, const mint& b) { return mint(a) !=\
    \ b; }\n    mint& operator++() { return *this += 1; }\n    mint operator++(int)\
    \ { mint r = *this; *this += 1; return r; }\n    mint& operator--() { return *this\
    \ -= 1; }\n    mint operator--(int) { mint r = *this; *this -= 1; return r; }\n\
    \    // modpow \u3092\u8A08\u7B97\u3059\u308B\u3002\u8A08\u7B97\u91CFO(log mod)\n\
    \    mint pow(long long n) const {\n        if (n != 0) n = ((n-2) % (modint_MOD-1)\
    \ + modint_MOD) % (modint_MOD-1) + 1;\n        mint r = 1, a = *this;\n      \
    \  while (n) {\n            if (n & 1) r *= a;\n            a *= a;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const { return\
    \ pow(-1); }\n    friend ostream& operator<<(ostream&s, const mint& a) { return\
    \ s << a.val; }\n    friend istream& operator>>(istream&s, mint& a) { long long\
    \ x; s >> x; a = mint(x); return s; }\n};\nvector<mint>fac, ifac;\n// n \u307E\
    \u3067\u306E\u968E\u4E57\u3092\u524D\u8A08\u7B97\u3059\u308B\u3002O(n)\nvoid buildfac(int\
    \ n) {\n    fac.resize(n + 1);\n    ifac.resize(n + 1);\n    fac[0] = 1;\n   \
    \ for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n    ifac[n] = mint(1) / fac[n];\n\
    \    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i] * i;\n}\n// nCk \u3092\u6C42\u3081\
    \u308B\u3002buildfac\u306E\u547C\u3073\u51FA\u3057\u304C\u5FC5\u9808\u3002O(1)\n\
    mint comb(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[k] * ifac[n-k]\
    \ : 0; }\n// nPk \u3092\u6C42\u3081\u308B\u3002buildfac\u306E\u547C\u3073\u51FA\
    \u3057\u304C\u5FC5\u9808\u3002O(1)\nmint perm(int n,int k) { return (0 <= k &&\
    \ k <= n ) ? fac[n] * ifac[n-k] : 0; }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy:
  - math/NTT.hpp
  - math/convolution.hpp
  timestamp: '2025-05-09 07:41:10+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-point_set_range_composite_large_array.test.cpp
  - verify/yosupo-range_affine_range_sum.test.cpp
  - verify/yosupo-point_set_range_composite.test.cpp
  - verify/yosupo-range_affine_point_get.test.cpp
  - verify/yosupo-convolution_mod.test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
