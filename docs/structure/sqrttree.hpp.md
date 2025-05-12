---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum.test.cpp
    title: verify/yosupo-point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/sqrttree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class S, auto op, auto e>\nstruct sqrttree {\n \
    \   struct block {\n        int l, r;\n        vector<S> data;\n        S sum;\n\
    \        block() = default;\n        block(vector<S>& base, int l_, int r_) :\
    \ l(l_), r(r_), data(base.begin() + l_, base.begin() + r_) {\n            rebuild();\n\
    \        }\n        void rebuild() {\n            sum = e();\n            for\
    \ (auto& x : data) sum = op(sum, x);\n        }\n        void set(int i, S x)\
    \ {\n            assert(l <= i && i < r);\n            data[i - l] = x;\n    \
    \        rebuild();\n        }\n        S get(int i) {\n            assert(l <=\
    \ i && i < r);\n            return data[i - l];\n        }\n        S prod(int\
    \ ql, int qr) {\n            if (qr <= l || r <= ql) return e();\n           \
    \ if (ql <= l && r <= qr) return sum;\n            S res = e();\n            for\
    \ (int i = max(l, ql); i < min(r, qr); ++i)\n                res = op(res, data[i\
    \ - l]);\n            return res;\n        }\n    };\n    int n, bsize;\n    vector<block>\
    \ blocks;\n    sqrttree() = default;\n    sqrttree(vector<S>& base) {\n      \
    \  n = base.size();\n        bsize = sqrt(n) + 1;\n        for (int i = 0; i <\
    \ n; i += bsize) {\n            blocks.emplace_back(base, i, min(n, i + bsize));\n\
    \        }\n    }\n    void set(int i, S x) {\n        assert(0 <= i && i < n);\n\
    \        for (auto& b : blocks)\n            if (b.l <= i && i < b.r) return b.set(i,\
    \ x);\n    }\n    S get(int i) {\n        assert(0 <= i && i < n);\n        for\
    \ (auto& b : blocks)\n            if (b.l <= i && i < b.r) return b.get(i);\n\
    \        assert(false);\n    }\n    S operator[](int i) {\n        return get(i);\n\
    \    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        S res = e();\n        for (auto& b : blocks)\n            res = op(res,\
    \ b.prod(l, r));\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class S, auto op, auto e>\nstruct sqrttree {\n    struct block {\n        int\
    \ l, r;\n        vector<S> data;\n        S sum;\n        block() = default;\n\
    \        block(vector<S>& base, int l_, int r_) : l(l_), r(r_), data(base.begin()\
    \ + l_, base.begin() + r_) {\n            rebuild();\n        }\n        void\
    \ rebuild() {\n            sum = e();\n            for (auto& x : data) sum =\
    \ op(sum, x);\n        }\n        void set(int i, S x) {\n            assert(l\
    \ <= i && i < r);\n            data[i - l] = x;\n            rebuild();\n    \
    \    }\n        S get(int i) {\n            assert(l <= i && i < r);\n       \
    \     return data[i - l];\n        }\n        S prod(int ql, int qr) {\n     \
    \       if (qr <= l || r <= ql) return e();\n            if (ql <= l && r <= qr)\
    \ return sum;\n            S res = e();\n            for (int i = max(l, ql);\
    \ i < min(r, qr); ++i)\n                res = op(res, data[i - l]);\n        \
    \    return res;\n        }\n    };\n    int n, bsize;\n    vector<block> blocks;\n\
    \    sqrttree() = default;\n    sqrttree(vector<S>& base) {\n        n = base.size();\n\
    \        bsize = sqrt(n) + 1;\n        for (int i = 0; i < n; i += bsize) {\n\
    \            blocks.emplace_back(base, i, min(n, i + bsize));\n        }\n   \
    \ }\n    void set(int i, S x) {\n        assert(0 <= i && i < n);\n        for\
    \ (auto& b : blocks)\n            if (b.l <= i && i < b.r) return b.set(i, x);\n\
    \    }\n    S get(int i) {\n        assert(0 <= i && i < n);\n        for (auto&\
    \ b : blocks)\n            if (b.l <= i && i < b.r) return b.get(i);\n       \
    \ assert(false);\n    }\n    S operator[](int i) {\n        return get(i);\n \
    \   }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        S res = e();\n        for (auto& b : blocks)\n            res = op(res,\
    \ b.prod(l, r));\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/sqrttree.hpp
  requiredBy: []
  timestamp: '2025-05-12 07:24:17+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-point_add_range_sum.test.cpp
documentation_of: structure/sqrttree.hpp
layout: document
redirect_from:
- /library/structure/sqrttree.hpp
- /library/structure/sqrttree.hpp.html
title: structure/sqrttree.hpp
---
