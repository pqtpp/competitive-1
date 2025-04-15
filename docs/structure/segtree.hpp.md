---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu-DSL_2_A.test.cpp
    title: verify/aizu-DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-static_range_sum.test.cpp
    title: verify/yosupo-static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/segtree.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n// op(op(a, b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\
    \u3064\u5FC5\u8981\u304C\u3042\u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto\
    \ op>\nstruct segtree {\n    int _n, size;\n    S _e;\n    vector<S> data;\n \
    \   // \u5927\u304D\u3055n, \u5358\u4F4D\u5143e(\u7701\u7565\u3059\u308B\u3068\
    S{} \u306B\u306A\u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    segtree(int\
    \ n, S e = S{}) : _n(n), _e(e) { build(vector<S>(n, _e)); }\n    // \u5927\u304D\
    \u3055v.size(), \u5358\u4F4D\u5143e(\u7701\u7565\u3059\u308B\u3068S{} \u306B\u306A\
    \u308B) \u306E\u30BB\u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    segtree(vector<S>&\
    \ v, S e = S{}) : _n(v.size()), _e(e) { build(v); }\n    void build(vector<S>\
    \ v) {\n        size = __bit_ceil((unsigned int)_n);\n        data.assign(2 *\
    \ size, _e);\n        for (int i=0; i<_n; i++) data[size+i] = v[i];\n        for\
    \ (int i=size-1; 0<i; i--) update(i);\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092x \u306B\u3059\u308B O(log n)\n    void set(int p, S x) {\n      \
    \  assert(0 <= p && p < _n);\n        p += size;\n        data[p] = x;\n     \
    \   for (p>>=1; 0<p; p>>=1) update(p);\n    }\n    // p \u756A\u76EE\u306E\u8981\
    \u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        return data[size+p];\n    }\n    // p \u756A\u76EE\
    \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n    S operator[](int p)\
    \ {\n        return get(p);\n    }\n    // [l, r) \u306E\u533A\u9593\u30AF\u30A8\
    \u30EA\u306B\u7B54\u3048\u308B O(log n)\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        S ll = _e, rr = _e;\n        l += size;\n\
    \        r += size;\n        while (l < r) {\n            if (l & 1) ll = op(ll,\
    \ data[l++]);\n            if (r & 1) rr = op(data[--r], rr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return op(ll, rr);\n    }\n   \
    \ // [0, _n) \u306E\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(1)\n    S all_prod()\
    \ {\n        return data[1];\n    }\n    // [0, _n) \u306E\u533A\u9593\u306E\u5024\
    \u3092\u53D6\u5F97\u3059\u308B O(n)\n    vector<S> values() {\n        vector<S>\
    \ re(_n);\n        for (int i=0; i<_n; i++) re[i] = data[size+i];\n        return\
    \ re;\n    }\n    void update(int p) {\n        data[p] = op(data[2*p], data[2*p+1]);\n\
    \    }\n    // f(op([l, r)))=true \u3068\u306A\u308B\u6700\u5927\u306Er \u3092\
    \u8FD4\u3059 O(log n)\n    template<auto f>\n    int max_right(int l) {\n    \
    \    assert(f(_e));\n        assert(0 <= l && l <= _n);\n        if (l == _n)\
    \ return l;\n        l += size;\n        S s = _e;\n        do {\n           \
    \ while (l % 2 == 0) l >>= 1;\n            if (!f(op(s, data[l]))) {\n       \
    \         while (l < size) {\n                    l = 2 * l;\n               \
    \     if (f(op(s, data[l]))) s = op(s, data[l++]);\n                }\n      \
    \          return l - size;\n            }\n            s = op(s, data[l]);\n\
    \            l++;\n        } while (l != (l & -l));\n        return _n;\n    }\n\
    \    // f(op([l, r)))=true \u3068\u306A\u308B\u6700\u5C0F\u306El \u3092\u8FD4\u3059\
    \ O(log n)\n    template<auto f>\n    int min_left(int r) {\n        assert(f(_e));\n\
    \        assert(0 <= r && r <= _n);\n        if (r == 0) return r;\n        r\
    \ += size;\n        S s = _e;\n        do {\n            r--;\n            while\
    \ (r % 2 == 1) r >>= 1;\n            if (!f(op(data[r], s))) {\n             \
    \   while (r < size) {\n                    r = 2 * r + 1;\n                 \
    \   if (f(op(data[r], s))) s = op(data[r--], s);\n                }\n        \
    \        return (r + 1) - size;\n            }\n            s = op(data[r], s);\n\
    \        } while(r != (r & -r));\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n// op(op(a,\
    \ b), c) = op(a, op(b, c)) \u304C\u6210\u308A\u7ACB\u3064\u5FC5\u8981\u304C\u3042\
    \u308B(\u7D50\u5408\u5F8B)\ntemplate<class S, auto op>\nstruct segtree {\n   \
    \ int _n, size;\n    S _e;\n    vector<S> data;\n    // \u5927\u304D\u3055n, \u5358\
    \u4F4D\u5143e(\u7701\u7565\u3059\u308B\u3068S{} \u306B\u306A\u308B) \u306E\u30BB\
    \u30B0\u6728\u3092\u69CB\u7BC9 O(n)\n    segtree(int n, S e = S{}) : _n(n), _e(e)\
    \ { build(vector<S>(n, _e)); }\n    // \u5927\u304D\u3055v.size(), \u5358\u4F4D\
    \u5143e(\u7701\u7565\u3059\u308B\u3068S{} \u306B\u306A\u308B) \u306E\u30BB\u30B0\
    \u6728\u3092\u69CB\u7BC9 O(n)\n    segtree(vector<S>& v, S e = S{}) : _n(v.size()),\
    \ _e(e) { build(v); }\n    void build(vector<S> v) {\n        size = __bit_ceil((unsigned\
    \ int)_n);\n        data.assign(2 * size, _e);\n        for (int i=0; i<_n; i++)\
    \ data[size+i] = v[i];\n        for (int i=size-1; 0<i; i--) update(i);\n    }\n\
    \    // p \u756A\u76EE\u306E\u8981\u7D20\u3092x \u306B\u3059\u308B O(log n)\n\
    \    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n\
    \        data[p] = x;\n        for (p>>=1; 0<p; p>>=1) update(p);\n    }\n   \
    \ // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B O(1)\n   \
    \ S get(int p) {\n        assert(0 <= p && p < _n);\n        return data[size+p];\n\
    \    }\n    // p \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\
    \ O(1)\n    S operator[](int p) {\n        return get(p);\n    }\n    // [l, r)\
    \ \u306E\u533A\u9593\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B O(log n)\n    S\
    \ prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n       \
    \ S ll = _e, rr = _e;\n        l += size;\n        r += size;\n        while (l\
    \ < r) {\n            if (l & 1) ll = op(ll, data[l++]);\n            if (r &\
    \ 1) rr = op(data[--r], rr);\n            l >>= 1;\n            r >>= 1;\n   \
    \     }\n        return op(ll, rr);\n    }\n    // [0, _n) \u306E\u30AF\u30A8\u30EA\
    \u306B\u7B54\u3048\u308B O(1)\n    S all_prod() {\n        return data[1];\n \
    \   }\n    // [0, _n) \u306E\u533A\u9593\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \ O(n)\n    vector<S> values() {\n        vector<S> re(_n);\n        for (int\
    \ i=0; i<_n; i++) re[i] = data[size+i];\n        return re;\n    }\n    void update(int\
    \ p) {\n        data[p] = op(data[2*p], data[2*p+1]);\n    }\n    // f(op([l,\
    \ r)))=true \u3068\u306A\u308B\u6700\u5927\u306Er \u3092\u8FD4\u3059 O(log n)\n\
    \    template<auto f>\n    int max_right(int l) {\n        assert(f(_e));\n  \
    \      assert(0 <= l && l <= _n);\n        if (l == _n) return l;\n        l +=\
    \ size;\n        S s = _e;\n        do {\n            while (l % 2 == 0) l >>=\
    \ 1;\n            if (!f(op(s, data[l]))) {\n                while (l < size)\
    \ {\n                    l = 2 * l;\n                    if (f(op(s, data[l])))\
    \ s = op(s, data[l++]);\n                }\n                return l - size;\n\
    \            }\n            s = op(s, data[l]);\n            l++;\n        } while\
    \ (l != (l & -l));\n        return _n;\n    }\n    // f(op([l, r)))=true \u3068\
    \u306A\u308B\u6700\u5C0F\u306El \u3092\u8FD4\u3059 O(log n)\n    template<auto\
    \ f>\n    int min_left(int r) {\n        assert(f(_e));\n        assert(0 <= r\
    \ && r <= _n);\n        if (r == 0) return r;\n        r += size;\n        S s\
    \ = _e;\n        do {\n            r--;\n            while (r % 2 == 1) r >>=\
    \ 1;\n            if (!f(op(data[r], s))) {\n                while (r < size)\
    \ {\n                    r = 2 * r + 1;\n                    if (f(op(data[r],\
    \ s))) s = op(data[r--], s);\n                }\n                return (r + 1)\
    \ - size;\n            }\n            s = op(data[r], s);\n        } while(r !=\
    \ (r & -r));\n        return 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/segtree.hpp
  requiredBy: []
  timestamp: '2025-04-03 17:12:39+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-static_range_sum.test.cpp
  - verify/aizu-DSL_2_A.test.cpp
documentation_of: structure/segtree.hpp
layout: document
redirect_from:
- /library/structure/segtree.hpp
- /library/structure/segtree.hpp.html
title: structure/segtree.hpp
---
