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
    \ namespace std;\n\n// S: \u5024\u578B, F: \u4F5C\u7528\u7D20\u578B\n// op: \u30E2\
    \u30CE\u30A4\u30C9\u6F14\u7B97 (S x S -> S)\n// e: \u5358\u4F4D\u5143 (S)\n//\
    \ mapping: \u4F5C\u7528 (F x S x int -> S)\n// composition: \u4F5C\u7528\u7D20\
    \u5408\u6210 (F x F -> F)\n// id: \u6052\u7B49\u5199\u50CF (F)\n\ntemplate <class\
    \ S,\n          S (*op)(S, S),\n          S (*e)(),\n          class F,\n    \
    \      S (*mapping)(F, S, int),\n          F (*composition)(F, F),\n         \
    \ F (*id)()>\nstruct SqrtTree {\n    struct Block {\n        int l, r;\n     \
    \   vector<S> data;\n        S sum;\n        F lazy;\n        bool pending;\n\n\
    \        Block() = default;\n\n        Block(const vector<S>& base, int l_, int\
    \ r_)\n            : l(l_), r(r_), data(base.begin() + l_, base.begin() + r_),\n\
    \              sum(e()), lazy(id()), pending(false) {\n            rebuild();\n\
    \        }\n\n        void apply(F f) {\n            lazy = composition(f, lazy);\n\
    \            pending = true;\n        }\n\n        void push() {\n           \
    \ if (!pending) return;\n            for (int i = 0; i < r - l; ++i)\n       \
    \         data[i] = mapping(lazy, data[i], 1);\n            lazy = id();\n   \
    \         pending = false;\n            rebuild();\n        }\n\n        void\
    \ rebuild() {\n            sum = e();\n            for (auto& x : data) sum =\
    \ op(sum, x);\n        }\n\n        void update(int ql, int qr, F f) {\n     \
    \       if (qr <= l || r <= ql) return;\n            if (ql <= l && r <= qr) {\n\
    \                apply(f);\n                return;\n            }\n         \
    \   push();\n            for (int i = max(l, ql); i < min(r, qr); ++i)\n     \
    \           data[i - l] = mapping(f, data[i - l], 1);\n            rebuild();\n\
    \        }\n\n        S query(int ql, int qr) {\n            if (qr <= l || r\
    \ <= ql) return e();\n            if (ql <= l && r <= qr) return pending ? mapping(lazy,\
    \ sum, r - l) : sum;\n            push();\n            S res = e();\n        \
    \    for (int i = max(l, ql); i < min(r, qr); ++i)\n                res = op(res,\
    \ data[i - l]);\n            return res;\n        }\n    };\n\n    int n, bsize;\n\
    \    vector<Block> blocks;\n\n    SqrtTree() = default;\n\n    SqrtTree(const\
    \ vector<S>& base) {\n        n = base.size();\n        bsize = sqrt(n) + 1;\n\
    \        for (int i = 0; i < n; i += bsize)\n            blocks.emplace_back(base,\
    \ i, min(n, i + bsize));\n    }\n\n    void update(int l, int r, F f) {\n    \
    \    for (auto& b : blocks)\n            b.update(l, r, f);\n    }\n\n    S query(int\
    \ l, int r) {\n        S res = e();\n        for (auto& b : blocks)\n        \
    \    res = op(res, b.query(l, r));\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// S: \u5024\
    \u578B, F: \u4F5C\u7528\u7D20\u578B\n// op: \u30E2\u30CE\u30A4\u30C9\u6F14\u7B97\
    \ (S x S -> S)\n// e: \u5358\u4F4D\u5143 (S)\n// mapping: \u4F5C\u7528 (F x S\
    \ x int -> S)\n// composition: \u4F5C\u7528\u7D20\u5408\u6210 (F x F -> F)\n//\
    \ id: \u6052\u7B49\u5199\u50CF (F)\n\ntemplate <class S,\n          S (*op)(S,\
    \ S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F, S, int),\n\
    \          F (*composition)(F, F),\n          F (*id)()>\nstruct SqrtTree {\n\
    \    struct Block {\n        int l, r;\n        vector<S> data;\n        S sum;\n\
    \        F lazy;\n        bool pending;\n\n        Block() = default;\n\n    \
    \    Block(const vector<S>& base, int l_, int r_)\n            : l(l_), r(r_),\
    \ data(base.begin() + l_, base.begin() + r_),\n              sum(e()), lazy(id()),\
    \ pending(false) {\n            rebuild();\n        }\n\n        void apply(F\
    \ f) {\n            lazy = composition(f, lazy);\n            pending = true;\n\
    \        }\n\n        void push() {\n            if (!pending) return;\n     \
    \       for (int i = 0; i < r - l; ++i)\n                data[i] = mapping(lazy,\
    \ data[i], 1);\n            lazy = id();\n            pending = false;\n     \
    \       rebuild();\n        }\n\n        void rebuild() {\n            sum = e();\n\
    \            for (auto& x : data) sum = op(sum, x);\n        }\n\n        void\
    \ update(int ql, int qr, F f) {\n            if (qr <= l || r <= ql) return;\n\
    \            if (ql <= l && r <= qr) {\n                apply(f);\n          \
    \      return;\n            }\n            push();\n            for (int i = max(l,\
    \ ql); i < min(r, qr); ++i)\n                data[i - l] = mapping(f, data[i -\
    \ l], 1);\n            rebuild();\n        }\n\n        S query(int ql, int qr)\
    \ {\n            if (qr <= l || r <= ql) return e();\n            if (ql <= l\
    \ && r <= qr) return pending ? mapping(lazy, sum, r - l) : sum;\n            push();\n\
    \            S res = e();\n            for (int i = max(l, ql); i < min(r, qr);\
    \ ++i)\n                res = op(res, data[i - l]);\n            return res;\n\
    \        }\n    };\n\n    int n, bsize;\n    vector<Block> blocks;\n\n    SqrtTree()\
    \ = default;\n\n    SqrtTree(const vector<S>& base) {\n        n = base.size();\n\
    \        bsize = sqrt(n) + 1;\n        for (int i = 0; i < n; i += bsize)\n  \
    \          blocks.emplace_back(base, i, min(n, i + bsize));\n    }\n\n    void\
    \ update(int l, int r, F f) {\n        for (auto& b : blocks)\n            b.update(l,\
    \ r, f);\n    }\n\n    S query(int l, int r) {\n        S res = e();\n       \
    \ for (auto& b : blocks)\n            res = op(res, b.query(l, r));\n        return\
    \ res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/sqrttree.hpp
  requiredBy: []
  timestamp: '2025-05-11 18:58:47+00:00'
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
