---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu-DSL_2_B.test.cpp
    title: verify/aizu-DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-DSL_2_E.test.cpp
    title: verify/aizu-DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum.test.cpp
    title: verify/yosupo-point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/BIT.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\ntemplate<class T>\nstruct BIT {\n    int _n;\n    vector<T> data;\n  \
    \  // BIT \u30920-indexed \u3067\u69CB\u7BC9\u3059\u308B O(n)\n    BIT(int n)\
    \ : _n(n), data(_n) {}\n    // p \u756A\u76EE\u306E\u5024\u306Bx \u3092\u52A0\u7B97\
    \u3059\u308B O(log n)\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p-1] += x;\n\
    \            p += p & -p;\n        }\n    }\n    // p \u756A\u76EE\u306E\u5024\
    \u3092x \u306B\u3059\u308B O(log n)\n    void set(int p, T x) {\n        add(p,\
    \ x - get(p));\n    }\n    // [0, r) \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\
    \ O(log n)\n    T sum(int r) {\n        assert(0 <= r &&  r <= _n);\n        T\
    \ re = T{};\n        while (0 < r) {\n            re += data[r-1];\n         \
    \   r -= r & -r;\n        }\n        return re;\n    }\n    // [l, r) \u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B O(log n)\n    T sum(int l, int r) {\n        assert(l\
    \ <= r);\n        return sum(r) - sum(l);\n    }\n    // p \u756A\u76EE\u306E\u5024\
    \u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T get(int p) {\n        return sum(p+1)\
    \ - sum(p);\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \ O(log n)\n    T operator[](int p) {\n        return get(p);\n    }\n    // \u5168\
    \u4F53\u306E\u7DCF\u548C\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T all_sum()\
    \ {\n        return sum(_n);\n    }\n    // [l, r) \u306Bx \u3092\u52A0\u7B97\u3059\
    \u308B \u4E00\u70B9\u53D6\u5F97\u306Fsum(p) \u3067\u884C\u3046 \u533A\u9593\u548C\
    \u30AF\u30A8\u30EA\u304C\u3067\u304D\u306A\u304F\u306A\u308B\u306E\u3067\u6CE8\
    \u610F O(log n)\n    void imos(int l, int r, T x) {\n        add(l, x);\n    \
    \    if (r < _n) add(r, T{}-x);\n    }\n    // x <= sum(p) \u3068\u306A\u308B\u6700\
    \u5C0F\u306Ep \u3092\u6C42\u3081\u308B O(log n)\n    int lower_bound(T x) {\n\
    \        if (x <= 0) return 0;\n        int re = 0, t = 1;\n        while (t <\
    \ _n) t <<= 1;\n        while (t) {\n            if (re + t < _n && data[re+t]\
    \ < x) {\n                x -= data[re+t];\n                re += t;\n       \
    \         t >>= 1;\n            }\n        }\n        return re;\n    }\n    //\
    \ x < sum(p) \u3068\u306A\u308B\u6700\u5C0F\u306Ep \u3092\u6C42\u3081\u308B O(log\
    \ n)\n    int upper_bound(T x) {\n        if (x < 0) return 0;\n        int re\
    \ = 0, t = 1;\n        while (t < _n) t <<= 1;\n        while (t) {\n        \
    \    if (re + t < _n && data[re+t] <= x) {\n                x -= data[re+t];\n\
    \                re += t;\n                t >>= 1;\n            }\n        }\n\
    \        return re;\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\ntemplate<class\
    \ T>\nstruct BIT {\n    int _n;\n    vector<T> data;\n    // BIT \u30920-indexed\
    \ \u3067\u69CB\u7BC9\u3059\u308B O(n)\n    BIT(int n) : _n(n), data(_n) {}\n \
    \   // p \u756A\u76EE\u306E\u5024\u306Bx \u3092\u52A0\u7B97\u3059\u308B O(log\
    \ n)\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n\
    \        while (p <= _n) {\n            data[p-1] += x;\n            p += p &\
    \ -p;\n        }\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092x \u306B\u3059\
    \u308B O(log n)\n    void set(int p, T x) {\n        add(p, x - get(p));\n   \
    \ }\n    // [0, r) \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B O(log n)\n    T\
    \ sum(int r) {\n        assert(0 <= r &&  r <= _n);\n        T re = T{};\n   \
    \     while (0 < r) {\n            re += data[r-1];\n            r -= r & -r;\n\
    \        }\n        return re;\n    }\n    // [l, r) \u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B O(log n)\n    T sum(int l, int r) {\n        assert(l <= r);\n  \
    \      return sum(r) - sum(l);\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092\
    \u53D6\u5F97\u3059\u308B O(log n)\n    T get(int p) {\n        return sum(p+1)\
    \ - sum(p);\n    }\n    // p \u756A\u76EE\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \ O(log n)\n    T operator[](int p) {\n        return get(p);\n    }\n    // \u5168\
    \u4F53\u306E\u7DCF\u548C\u3092\u53D6\u5F97\u3059\u308B O(log n)\n    T all_sum()\
    \ {\n        return sum(_n);\n    }\n    // [l, r) \u306Bx \u3092\u52A0\u7B97\u3059\
    \u308B \u4E00\u70B9\u53D6\u5F97\u306Fsum(p) \u3067\u884C\u3046 \u533A\u9593\u548C\
    \u30AF\u30A8\u30EA\u304C\u3067\u304D\u306A\u304F\u306A\u308B\u306E\u3067\u6CE8\
    \u610F O(log n)\n    void imos(int l, int r, T x) {\n        add(l, x);\n    \
    \    if (r < _n) add(r, T{}-x);\n    }\n    // x <= sum(p) \u3068\u306A\u308B\u6700\
    \u5C0F\u306Ep \u3092\u6C42\u3081\u308B O(log n)\n    int lower_bound(T x) {\n\
    \        if (x <= 0) return 0;\n        int re = 0, t = 1;\n        while (t <\
    \ _n) t <<= 1;\n        while (t) {\n            if (re + t < _n && data[re+t]\
    \ < x) {\n                x -= data[re+t];\n                re += t;\n       \
    \         t >>= 1;\n            }\n        }\n        return re;\n    }\n    //\
    \ x < sum(p) \u3068\u306A\u308B\u6700\u5C0F\u306Ep \u3092\u6C42\u3081\u308B O(log\
    \ n)\n    int upper_bound(T x) {\n        if (x < 0) return 0;\n        int re\
    \ = 0, t = 1;\n        while (t < _n) t <<= 1;\n        while (t) {\n        \
    \    if (re + t < _n && data[re+t] <= x) {\n                x -= data[re+t];\n\
    \                re += t;\n                t >>= 1;\n            }\n        }\n\
    \        return re;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/BIT.hpp
  requiredBy: []
  timestamp: '2025-04-03 17:12:39+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu-DSL_2_E.test.cpp
  - verify/yosupo-point_add_range_sum.test.cpp
  - verify/aizu-DSL_2_B.test.cpp
documentation_of: structure/BIT.hpp
layout: document
redirect_from:
- /library/structure/BIT.hpp
- /library/structure/BIT.hpp.html
title: structure/BIT.hpp
---
