---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum_2.test.cpp
    title: verify/yosupo-point_add_range_sum_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/dynamicsegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n// op(op(a, b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\
    \u3064\u5FC5\u8981\u304C\u3042\u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto\
    \ op>\nstruct dynamicsegtree {\n    long long _n, size;\n    S _e;\n    unordered_map<long\
    \ long, S> data;\n    // \u5927\u304D\u3055n, \u5358\u4F4D\u5143e(\u7701\u7565\
    \u3059\u308B\u3068S{} \u306B\u306A\u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\
    \u7BC9 O(log n)\n    dynamicsegtree(long long n, S e = S{}) : _n(n), _e(e) {\n\
    \        size = 1;\n        while (size < _n) size <<= 1;\n    }\n    // p \u756A\
    \u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n    void set(long\
    \ long p, S x) {\n        p += size;\n        data[p] = x;\n        for (p>>=1;\
    \ 0<p; p>>=1) update(p);\n    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\
    \u53D6\u5F97\u3059\u308B O(1)\n    S get(long long p) {\n        return data[size+p];\n\
    \    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\
    \ O(1)\n    S operator[](long long p) {\n        return data[size+p];\n    }\n\
    \    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(log\
    \ n)\n    S prod(long long l, long long r) {\n        S ll = _e, rr = _e;\n  \
    \      l += size;\n        r += size;\n        while (l < r) {\n            if\
    \ (l & 1) {\n                if (data.count(l)) {\n                    ll = op(ll,\
    \ data[l++]);\n                }\n            }\n            if (r & 1) {\n  \
    \              if (data.count(r-1)) {\n                    rr = op(data[--r],\
    \ rr);\n                }\n            }\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return op(ll, rr);\n    }\n    // [0, _n) \u306E\u30AF\
    \u30A8\u30EA\u306B\u7B54\u3048\u308B O(1)\n    S all_prod() {\n        return\
    \ data[1];\n    }\n    void update(long long p) {\n        S l = _e, r = _e;\n\
    \        if (data.count(2*p)) l = data[2*p];\n        if (data.count(2*p+1)) r\
    \ = data[2*p+1];\n        data[p] = op(l, r);\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n// op(op(a,\
    \ b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\u3064\u5FC5\u8981\u304C\u3042\
    \u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto op>\nstruct dynamicsegtree\
    \ {\n    long long _n, size;\n    S _e;\n    unordered_map<long long, S> data;\n\
    \    // \u5927\u304D\u3055n, \u5358\u4F4D\u5143e(\u7701\u7565\u3059\u308B\u3068\
    S{} \u306B\u306A\u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(log n)\n\
    \    dynamicsegtree(long long n, S e = S{}) : _n(n), _e(e) {\n        size = 1;\n\
    \        while (size < _n) size <<= 1;\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092x \u306B\u3059\u308B O(log n)\n    void set(long long p, S x) {\n\
    \        p += size;\n        data[p] = x;\n        for (p>>=1; 0<p; p>>=1) update(p);\n\
    \    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\
    \ O(1)\n    S get(long long p) {\n        return data[size+p];\n    }\n    //\
    \ p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n    S operator[](long\
    \ long p) {\n        return data[size+p];\n    }\n    // [l, r) \u306E\u533A\u9593\
    \u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(log n)\n    S prod(long long l, long\
    \ long r) {\n        S ll = _e, rr = _e;\n        l += size;\n        r += size;\n\
    \        while (l < r) {\n            if (l & 1) {\n                if (data.count(l))\
    \ {\n                    ll = op(ll, data[l++]);\n                }\n        \
    \    }\n            if (r & 1) {\n                if (data.count(r-1)) {\n   \
    \                 rr = op(data[--r], rr);\n                }\n            }\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n        return op(ll,\
    \ rr);\n    }\n    // [0, _n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\
    \ O(1)\n    S all_prod() {\n        return data[1];\n    }\n    void update(long\
    \ long p) {\n        S l = _e, r = _e;\n        if (data.count(2*p)) l = data[2*p];\n\
    \        if (data.count(2*p+1)) r = data[2*p+1];\n        data[p] = op(l, r);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/dynamicsegtree.hpp
  requiredBy: []
  timestamp: '2025-04-28 08:13:09+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-point_add_range_sum_2.test.cpp
documentation_of: structure/dynamicsegtree.hpp
layout: document
redirect_from:
- /library/structure/dynamicsegtree.hpp
- /library/structure/dynamicsegtree.hpp.html
title: structure/dynamicsegtree.hpp
---
