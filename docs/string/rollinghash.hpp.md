---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/modint230.hpp
    title: math/modint230.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint230.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nlong long modint_MOD = (1LL<<61)-1;\n// mod \u306E\u5024\u3092\u5909\u66F4\
    \u3059\u308B(\u30C7\u30D5\u30A9\u30EB\u30C8\u306F2^61-1)\nvoid setmod(long long\
    \ x) { modint_MOD = x; }\nstruct mint230 {\n    long long val;\n    mint230(long\
    \ long x=0) {\n        val=(x%modint_MOD+modint_MOD)%modint_MOD;\n    }\n    mint230&\
    \ operator+=(const mint230& a) { val = (val + a.val) % modint_MOD; return *this;\
    \ }\n    mint230& operator-=(const mint230& a) { val = (val - a.val + modint_MOD)\
    \ % modint_MOD; return *this; }\n    mint230& operator*=(const mint230& a) { val\
    \ = (__int128_t)val * a.val % modint_MOD ; return *this; }\n    mint230& operator/=(const\
    \ mint230& a) { return *this *= a.inv(); }\n    mint230 operator+(const mint230&\
    \ a) const { return mint230(*this) += a; }\n    mint230 operator-(const mint230&\
    \ a) const { return mint230(*this) -= a; }\n    mint230 operator*(const mint230&\
    \ a) const { return mint230(*this) *= a; }\n    mint230 operator/(const mint230&\
    \ a) const { return mint230(*this) /= a; }\n    bool operator==(const mint230&\
    \ a) const { return val == a.val; }\n    bool operator!=(const mint230& a) const\
    \ { return val != a.val; }\n    mint230& operator+=(int a) { return *this += mint230(a);\
    \ }\n    mint230& operator-=(int a) { return *this -= mint230(a); }\n    mint230&\
    \ operator*=(int a) { return *this *= mint230(a); }\n    mint230& operator/=(int\
    \ a) { return *this /= mint230(a); }\n    mint230 operator+(int a) const { return\
    \ mint230(*this) += a; }\n    mint230 operator-(int a) const { return mint230(*this)\
    \ -= a; }\n    mint230 operator*(int a) const { return mint230(*this) *= a; }\n\
    \    mint230 operator/(int a) const { return mint230(*this) /= a; }\n    bool\
    \ operator==(int a) const { return val == mint230(a).val; }\n    bool operator!=(int\
    \ a) const { return val != mint230(a).val; }\n    friend mint230 operator+(int\
    \ a,const mint230& b) { return mint230(a) + b; }\n    friend mint230 operator-(int\
    \ a,const mint230& b) { return mint230(a) - b; }\n    friend mint230 operator*(int\
    \ a,const mint230& b) { return mint230(a) * b; }\n    friend mint230 operator/(int\
    \ a,const mint230& b) { return mint230(a) / b; }\n    friend bool operator==(int\
    \ a, const mint230& b) { return mint230(a) == b; }\n    friend bool operator!=(int\
    \ a, const mint230& b) { return mint230(a) != b; }\n    mint230& operator++()\
    \ { return *this += 1; }\n    mint230 operator++(int) { mint230 r = *this; *this\
    \ += 1; return r; }\n    mint230& operator--() { return *this -= 1; }\n    mint230\
    \ operator--(int) { mint230 r = *this; *this -= 1; return r; }\n    // modpow\
    \ \u3092\u8A08\u7B97\u3059\u308B\u3002\u8A08\u7B97\u91CFO(log mod)\n    mint230\
    \ pow(long long n) const {\n        if (n != 0) n = ((n-2) % (modint_MOD-1) +\
    \ modint_MOD) % (modint_MOD-1) + 1;\n        mint230 r = 1, a = *this;\n     \
    \   while (n) {\n            if (n & 1) r *= a;\n            a *= a;\n       \
    \     n >>= 1;\n        }\n        return r;\n    }\n    mint230 inv() const {\
    \ return pow(-1); }\n    friend ostream& operator<<(ostream&s, const mint230&\
    \ a) { return s << a.val; }\n    friend istream& operator>>(istream&s, mint230&\
    \ a) { long long x; s >> x; a = mint230(x); return s; }\n};\nvector<mint230>fac,\
    \ ifac;\n// n \u307E\u3067\u306E\u968E\u4E57\u3092\u524D\u8A08\u7B97\u3059\u308B\
    \u3002O(n)\nvoid buildfac(int n) {\n    fac.resize(n + 1);\n    ifac.resize(n\
    \ + 1);\n    fac[0] = 1;\n    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;\n\
    \    ifac[n] = mint230(1) / fac[n];\n    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i]\
    \ * i;\n}\n// nCk \u3092\u6C42\u3081\u308B\u3002buildfac\u306E\u547C\u3073\u51FA\
    \u3057\u304C\u5FC5\u9808\u3002O(1)\nmint230 comb(int n,int k) { return (0 <= k\
    \ && k <= n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }\n// nPk \u3092\u6C42\u3081\
    \u308B\u3002buildfac\u306E\u547C\u3073\u51FA\u3057\u304C\u5FC5\u9808\u3002O(1)\n\
    mint230 perm(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] :\
    \ 0; }\n#line 4 \"string/rollinghash.hpp\"\nusing namespace std;\ntemplate <typename\
    \ T = char>\nstruct RollingHash {\n    mint230 generate_base() {\n        mt19937_64\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n        uniform_int_distribution<uint64_t>\
    \ rand(1, mint230::mod() - 1);\n        return mint230(rand(mt));\n    }\n   \
    \ mint230 base, base_inv;\n    vector<mint230> bases, base_invs;\n    vector<T>\
    \ pre, suf;\n    vector<mint230> PRE{mint230(0)}, SUF{mint230(0)};\n    void expand_bases(size_t\
    \ n) {\n        if (bases.size() < n+1) {\n            int pre_sz = (int)bases.size();\n\
    \            bases.resize(n + 1);\n            for (int i=pre_sz-1; i<n; i++)\
    \ {\n                bases[i+1] = bases[i] * base;\n            }\n        }\n\
    \    }\n    void expand_base_invs(size_t n) {\n        if (base_invs.size() <\
    \ n+1) {\n            int pre_sz = (int)base_invs.size();\n            base_invs.resize(n+1);\n\
    \            for (int i=pre_sz-1; i<n; i++) {\n                base_invs[i+1]\
    \ = base_invs[i] * base_inv;\n            }\n        }\n    }\n    RollingHash(const\
    \ string& s) {\n        for (auto& c : s) push_back(c);\n    }\n    RollingHash(const\
    \ vector<T>& s) {\n        for (auto& c : s) push_back(c);\n    }\n    int size()\
    \ { return (int)pre.size() + (int)suf.size(); }\n    void push_front(T c) {\n\
    \        expand_base_invs(pre.size()+1);\n        PRE.push_back(PRE.back() + base_invs[pre.size()+1]\
    \ * mint230(c));\n        pre.push_back(c);\n    }\n    void push_back(T c) {\n\
    \        expand_bases(suf.size());\n        SUF.push_back(SUF.back() + bases[suf.size()]\
    \ * mint230(c));\n        suf.push_back(c);\n    }\n    T operator[](int k) {\n\
    \        assert(0<=k && k<size());\n        k -= pre.size();\n        return (k\
    \ < 0 ? pre[~k] : suf[k]);\n    }\n    mint230 get(int r) {\n        assert(0<=r\
    \ && r<=size());\n        r -= (int)pre.size();\n        expand_bases(pre.size());\n\
    \        if (r < 0) {\n            return bases[pre.size()] * (PRE.back() - PRE[-r]);\n\
    \        } else {\n            return bases[pre.size()] * (PRE.back() + SUF[r]);\n\
    \        }\n    }\n    mint230 get(int l, int r) {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        expand_base_invs(l);\n        return base_invs[l]\
    \ * (get(r) - get(l));\n    }\n    int lcp(const RollingHash& b) {\n        int\
    \ len = min(size(), b.size());\n        int low = 0, high = len + 1;\n       \
    \ while (high - low > 1) {\n            int mid = (low + high) / 2;\n        \
    \    if (get(mid) == b.get(mid)){\n                low = mid;\n            }\n\
    \            else {\n                high = mid;\n            }\n        }\n \
    \       return low;\n    }\n    int lcp(const RollingHash& b, int l1, int l2)\
    \ {\n        assert(l1 <= size());\n        assert(l2 <= b.size());\n        int\
    \ len = min(size() - l1, b.size() - l2);\n        int low = 0, high = len + 1;\n\
    \        while (high - low > 1) {\n            int mid = (low + high) / 2;\n \
    \           if (get(l1, l1 + mid) == b.get(l2, l2 + mid))\n            low = mid;\n\
    \        else\n            high = mid;\n        }\n        return low;\n    }\n\
    \    mint230 combine(mint230 h1, int h1_len, mint230 h2) {\n        expand_bases(h1_len);\n\
    \        return h1 + h2 * bases[h1_len];\n    }\n    void clear() {\n        pre.clear();\n\
    \        pre.shrink_to_fit();\n        suf.clear();\n        suf.shrink_to_fit();\n\
    \        PRE = {mint230(1)};\n        PRE.shrink_to_fit();\n        SUF = {mint230(1)};\n\
    \        SUF.shrink_to_fit();\n    }\n    void merge(RollingHash& b) {\n     \
    \   if (size() < b.size()) {\n            pre.swap(b.pre);\n            suf.swap(b.suf);\n\
    \            PRE.swap(b.PRE);\n            SUF.swap(b.SUF);\n            reverse(b.suf.begin(),\
    \ b.suf.end());\n            for (auto& c : b.suf) push_front(c);\n          \
    \  for (auto& c : b.pre) push_front(c);\n        } else {\n            reverse(b.pre.begin(),\
    \ b.pre.end());\n            for (auto& c : b.pre) push_back(c);\n           \
    \ for (auto& c : b.suf) push_back(c);\n        }\n        b.clear();\n    }\n\
    };\n"
  code: "#pragma once\n#include \"modint230\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate <typename T = char>\nstruct RollingHash {\n    mint230 generate_base()\
    \ {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<uint64_t> rand(1, mint230::mod() - 1);\n   \
    \     return mint230(rand(mt));\n    }\n    mint230 base, base_inv;\n    vector<mint230>\
    \ bases, base_invs;\n    vector<T> pre, suf;\n    vector<mint230> PRE{mint230(0)},\
    \ SUF{mint230(0)};\n    void expand_bases(size_t n) {\n        if (bases.size()\
    \ < n+1) {\n            int pre_sz = (int)bases.size();\n            bases.resize(n\
    \ + 1);\n            for (int i=pre_sz-1; i<n; i++) {\n                bases[i+1]\
    \ = bases[i] * base;\n            }\n        }\n    }\n    void expand_base_invs(size_t\
    \ n) {\n        if (base_invs.size() < n+1) {\n            int pre_sz = (int)base_invs.size();\n\
    \            base_invs.resize(n+1);\n            for (int i=pre_sz-1; i<n; i++)\
    \ {\n                base_invs[i+1] = base_invs[i] * base_inv;\n            }\n\
    \        }\n    }\n    RollingHash(const string& s) {\n        for (auto& c :\
    \ s) push_back(c);\n    }\n    RollingHash(const vector<T>& s) {\n        for\
    \ (auto& c : s) push_back(c);\n    }\n    int size() { return (int)pre.size()\
    \ + (int)suf.size(); }\n    void push_front(T c) {\n        expand_base_invs(pre.size()+1);\n\
    \        PRE.push_back(PRE.back() + base_invs[pre.size()+1] * mint230(c));\n \
    \       pre.push_back(c);\n    }\n    void push_back(T c) {\n        expand_bases(suf.size());\n\
    \        SUF.push_back(SUF.back() + bases[suf.size()] * mint230(c));\n       \
    \ suf.push_back(c);\n    }\n    T operator[](int k) {\n        assert(0<=k &&\
    \ k<size());\n        k -= pre.size();\n        return (k < 0 ? pre[~k] : suf[k]);\n\
    \    }\n    mint230 get(int r) {\n        assert(0<=r && r<=size());\n       \
    \ r -= (int)pre.size();\n        expand_bases(pre.size());\n        if (r < 0)\
    \ {\n            return bases[pre.size()] * (PRE.back() - PRE[-r]);\n        }\
    \ else {\n            return bases[pre.size()] * (PRE.back() + SUF[r]);\n    \
    \    }\n    }\n    mint230 get(int l, int r) {\n        assert(0 <= l and l <=\
    \ r and r <= size());\n        expand_base_invs(l);\n        return base_invs[l]\
    \ * (get(r) - get(l));\n    }\n    int lcp(const RollingHash& b) {\n        int\
    \ len = min(size(), b.size());\n        int low = 0, high = len + 1;\n       \
    \ while (high - low > 1) {\n            int mid = (low + high) / 2;\n        \
    \    if (get(mid) == b.get(mid)){\n                low = mid;\n            }\n\
    \            else {\n                high = mid;\n            }\n        }\n \
    \       return low;\n    }\n    int lcp(const RollingHash& b, int l1, int l2)\
    \ {\n        assert(l1 <= size());\n        assert(l2 <= b.size());\n        int\
    \ len = min(size() - l1, b.size() - l2);\n        int low = 0, high = len + 1;\n\
    \        while (high - low > 1) {\n            int mid = (low + high) / 2;\n \
    \           if (get(l1, l1 + mid) == b.get(l2, l2 + mid))\n            low = mid;\n\
    \        else\n            high = mid;\n        }\n        return low;\n    }\n\
    \    mint230 combine(mint230 h1, int h1_len, mint230 h2) {\n        expand_bases(h1_len);\n\
    \        return h1 + h2 * bases[h1_len];\n    }\n    void clear() {\n        pre.clear();\n\
    \        pre.shrink_to_fit();\n        suf.clear();\n        suf.shrink_to_fit();\n\
    \        PRE = {mint230(1)};\n        PRE.shrink_to_fit();\n        SUF = {mint230(1)};\n\
    \        SUF.shrink_to_fit();\n    }\n    void merge(RollingHash& b) {\n     \
    \   if (size() < b.size()) {\n            pre.swap(b.pre);\n            suf.swap(b.suf);\n\
    \            PRE.swap(b.PRE);\n            SUF.swap(b.SUF);\n            reverse(b.suf.begin(),\
    \ b.suf.end());\n            for (auto& c : b.suf) push_front(c);\n          \
    \  for (auto& c : b.pre) push_front(c);\n        } else {\n            reverse(b.pre.begin(),\
    \ b.pre.end());\n            for (auto& c : b.pre) push_back(c);\n           \
    \ for (auto& c : b.suf) push_back(c);\n        }\n        b.clear();\n    }\n\
    };"
  dependsOn:
  - math/modint230.hpp
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2025-05-09 08:57:16+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: string/rollinghash.hpp
---
