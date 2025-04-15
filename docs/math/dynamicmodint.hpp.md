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
  bundledCode: "#line 2 \"math/dynamicmodint.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\nvector<long long> dynamicmodint_MOD;\n// mod \u306E\u5024\u3092\
    \u8FFD\u52A0\u3059\u308B\nvoid addmod(long long x) { dynamicmodint_MOD.push_back(x);\
    \ }\nstruct dmint {\n    vector<long long> val;\n    dmint(long long x=0) : val(dynamicmodint_MOD.size())\
    \ {\n        assert(0 < dynamicmodint_MOD.size());\n        for (size_t i = 0;\
    \ i < dynamicmodint_MOD.size(); ++i) val[i] = (x % dynamicmodint_MOD[i] + dynamicmodint_MOD[i])\
    \ % dynamicmodint_MOD[i];\n    }\n    dmint& operator+=(const dmint& a) { for\
    \ (int i=0; i<dynamicmodint_MOD.size(); i++) val[i] = (val[i] + a.val[i]) % dynamicmodint_MOD[i];\
    \ return *this; }\n    dmint& operator-=(const dmint& a) { for (int i=0; i<dynamicmodint_MOD.size();\
    \ i++) val[i] = (val[i] - a.val[i] + dynamicmodint_MOD[i]) % dynamicmodint_MOD[i];\
    \ return *this; }\n    dmint& operator*=(const dmint& a) { for (int i=0; i<dynamicmodint_MOD.size();\
    \ i++) val[i] = (val[i] * a.val[i]) % dynamicmodint_MOD[i]; return *this; }\n\
    \    dmint& operator/=(const dmint& a) { return *this *= a.inv(); }\n    dmint\
    \ operator+(const dmint& a) const { return dmint(*this) += a; }\n    dmint operator-(const\
    \ dmint& a) const { return dmint(*this) -= a; }\n    dmint operator*(const dmint&\
    \ a) const { return dmint(*this) *= a; }\n    dmint operator/(const dmint& a)\
    \ const { return dmint(*this) /= a; }\n    bool operator==(const dmint& a) const\
    \ { return val == a.val; }\n    bool operator!=(const dmint& a) const { return\
    \ val != a.val; }    \n    dmint& operator+=(int a) { return *this += dmint(a);\
    \ }\n    dmint& operator-=(int a) { return *this -= dmint(a); }\n    dmint& operator*=(int\
    \ a) { return *this *= dmint(a); }\n    dmint& operator/=(int a) { return *this\
    \ /= dmint(a); }\n    dmint operator+(int a) const { return dmint(*this) += a;\
    \ }\n    dmint operator-(int a) const { return dmint(*this) -= a; }\n    dmint\
    \ operator*(int a) const { return dmint(*this) *= a; }\n    dmint operator/(int\
    \ a) const { return dmint(*this) /= a; }\n    friend dmint operator+(int a,const\
    \ dmint& b) { return dmint(a) + b; }\n    friend dmint operator-(int a,const dmint&\
    \ b) { return dmint(a) - b; }\n    friend dmint operator*(int a,const dmint& b)\
    \ { return dmint(a) * b; }\n    friend dmint operator/(int a,const dmint& b) {\
    \ return dmint(a) / b; }\n    dmint& operator++() { return *this += 1; }\n   \
    \ dmint operator++(int) { dmint r = *this; *this += 1; return r; }\n    dmint&\
    \ operator--() { return *this -= 1; }\n    dmint operator--(int) { dmint r = *this;\
    \ *this -= 1; return r; }\n    // modpow \u3092\u8A08\u7B97\u3059\u308B\u3002\u8A08\
    \u7B97\u91CFO(log mod)\n    dmint pow(long long n) const {\n        dmint re =\
    \ dmint(0);\n        for (int i=0; i < dynamicmodint_MOD.size(); i++) {\n    \
    \        long long m = dynamicmodint_MOD[i];\n            long long nn = n;\n\
    \            if (nn != 0) nn = ((nn - 2) % (m - 1) + m) % (m - 1) + 1;\n     \
    \       long long r = 1, a = val[i];\n            while (nn) {\n             \
    \   if (nn & 1) r = r * a % m;\n                a = a * a % m;\n             \
    \   nn >>= 1;\n            }\n            re.val[i] = r;        \n        }\n\
    \        return re;\n    }\n    dmint inv() const { return pow(-1); }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\nvector<long\
    \ long> dynamicmodint_MOD;\n// mod \u306E\u5024\u3092\u8FFD\u52A0\u3059\u308B\n\
    void addmod(long long x) { dynamicmodint_MOD.push_back(x); }\nstruct dmint {\n\
    \    vector<long long> val;\n    dmint(long long x=0) : val(dynamicmodint_MOD.size())\
    \ {\n        assert(0 < dynamicmodint_MOD.size());\n        for (size_t i = 0;\
    \ i < dynamicmodint_MOD.size(); ++i) val[i] = (x % dynamicmodint_MOD[i] + dynamicmodint_MOD[i])\
    \ % dynamicmodint_MOD[i];\n    }\n    dmint& operator+=(const dmint& a) { for\
    \ (int i=0; i<dynamicmodint_MOD.size(); i++) val[i] = (val[i] + a.val[i]) % dynamicmodint_MOD[i];\
    \ return *this; }\n    dmint& operator-=(const dmint& a) { for (int i=0; i<dynamicmodint_MOD.size();\
    \ i++) val[i] = (val[i] - a.val[i] + dynamicmodint_MOD[i]) % dynamicmodint_MOD[i];\
    \ return *this; }\n    dmint& operator*=(const dmint& a) { for (int i=0; i<dynamicmodint_MOD.size();\
    \ i++) val[i] = (val[i] * a.val[i]) % dynamicmodint_MOD[i]; return *this; }\n\
    \    dmint& operator/=(const dmint& a) { return *this *= a.inv(); }\n    dmint\
    \ operator+(const dmint& a) const { return dmint(*this) += a; }\n    dmint operator-(const\
    \ dmint& a) const { return dmint(*this) -= a; }\n    dmint operator*(const dmint&\
    \ a) const { return dmint(*this) *= a; }\n    dmint operator/(const dmint& a)\
    \ const { return dmint(*this) /= a; }\n    bool operator==(const dmint& a) const\
    \ { return val == a.val; }\n    bool operator!=(const dmint& a) const { return\
    \ val != a.val; }    \n    dmint& operator+=(int a) { return *this += dmint(a);\
    \ }\n    dmint& operator-=(int a) { return *this -= dmint(a); }\n    dmint& operator*=(int\
    \ a) { return *this *= dmint(a); }\n    dmint& operator/=(int a) { return *this\
    \ /= dmint(a); }\n    dmint operator+(int a) const { return dmint(*this) += a;\
    \ }\n    dmint operator-(int a) const { return dmint(*this) -= a; }\n    dmint\
    \ operator*(int a) const { return dmint(*this) *= a; }\n    dmint operator/(int\
    \ a) const { return dmint(*this) /= a; }\n    friend dmint operator+(int a,const\
    \ dmint& b) { return dmint(a) + b; }\n    friend dmint operator-(int a,const dmint&\
    \ b) { return dmint(a) - b; }\n    friend dmint operator*(int a,const dmint& b)\
    \ { return dmint(a) * b; }\n    friend dmint operator/(int a,const dmint& b) {\
    \ return dmint(a) / b; }\n    dmint& operator++() { return *this += 1; }\n   \
    \ dmint operator++(int) { dmint r = *this; *this += 1; return r; }\n    dmint&\
    \ operator--() { return *this -= 1; }\n    dmint operator--(int) { dmint r = *this;\
    \ *this -= 1; return r; }\n    // modpow \u3092\u8A08\u7B97\u3059\u308B\u3002\u8A08\
    \u7B97\u91CFO(log mod)\n    dmint pow(long long n) const {\n        dmint re =\
    \ dmint(0);\n        for (int i=0; i < dynamicmodint_MOD.size(); i++) {\n    \
    \        long long m = dynamicmodint_MOD[i];\n            long long nn = n;\n\
    \            if (nn != 0) nn = ((nn - 2) % (m - 1) + m) % (m - 1) + 1;\n     \
    \       long long r = 1, a = val[i];\n            while (nn) {\n             \
    \   if (nn & 1) r = r * a % m;\n                a = a * a % m;\n             \
    \   nn >>= 1;\n            }\n            re.val[i] = r;        \n        }\n\
    \        return re;\n    }\n    dmint inv() const { return pow(-1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/dynamicmodint.hpp
  requiredBy: []
  timestamp: '2025-04-03 17:12:39+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamicmodint.hpp
layout: document
redirect_from:
- /library/math/dynamicmodint.hpp
- /library/math/dynamicmodint.hpp.html
title: math/dynamicmodint.hpp
---
