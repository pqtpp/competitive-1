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
    \ namespace std;\ntemplate <class S, auto op, auto e, class F, auto mapping>\n\
    struct sqrttree {\n    struct block {\n        int l, r;\n        vector<S> data;\n\
    \        S sum;\n        block() = default;\n        block(vector<S>& base, int\
    \ l_, int r_) : l(l_), r(r_), data(base.begin() + l_, base.begin() + r_) {\n \
    \           rebuild();\n        }\n        void rebuild() {\n            sum =\
    \ e();\n            for (auto& x : data) sum = op(sum, x);\n        }\n      \
    \  void apply(int i, F f) {\n            data[i - l] = mapping(f, data[i - l]);\n\
    \            sum = e();\n            for (auto& x : data) sum = op(sum, x);\n\
    \        }\n        S prod(int ql, int qr) {\n            if (qr <= l || r <=\
    \ ql) return e();\n            if (ql <= l && r <= qr) return sum;\n         \
    \   S res = e();\n            for (int i = max(l, ql); i < min(r, qr); ++i) {\n\
    \                res = op(res, data[i - l]);\n            }\n            return\
    \ res;\n        }\n    };\n    int n, bsize;\n    vector<block> blocks;\n    sqrttree()\
    \ = default;\n    sqrttree(int n) : sqrttree(vector<S>(n, e())) {}\n    sqrttree(vector<S>\
    \ base) {\n        n = base.size();\n        bsize = sqrt(n) + 1;\n        for\
    \ (int i = 0; i < n; i += bsize) {\n            blocks.push_back(block{base, i,\
    \ min(n, i + bsize)});\n        }\n    }\n    void apply(int i, F f) {\n     \
    \   assert(0 <= i && i < n);\n        for (auto& b : blocks) {\n            if\
    \ (b.l <= i && i < b.r) {\n                b.apply(i, f);\n                return;\n\
    \            }\n        }\n    }\n    S operator[](int i) {\n        assert(0\
    \ <= i && i < n);\n        for (auto& b : blocks) {\n            if (b.l <= i\
    \ && i < b.r) {\n                return b.data[i - b.l];\n            }\n    \
    \    }\n        assert(false);\n    }\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        S res = e();\n        for (auto& b : blocks)\
    \ {\n            res = op(res, b.prod(l, r));\n        }\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class\
    \ S, auto op, auto e, class F, auto mapping>\nstruct sqrttree {\n    struct block\
    \ {\n        int l, r;\n        vector<S> data;\n        S sum;\n        block()\
    \ = default;\n        block(vector<S>& base, int l_, int r_) : l(l_), r(r_), data(base.begin()\
    \ + l_, base.begin() + r_) {\n            rebuild();\n        }\n        void\
    \ rebuild() {\n            sum = e();\n            for (auto& x : data) sum =\
    \ op(sum, x);\n        }\n        void apply(int i, F f) {\n            data[i\
    \ - l] = mapping(f, data[i - l]);\n            sum = e();\n            for (auto&\
    \ x : data) sum = op(sum, x);\n        }\n        S prod(int ql, int qr) {\n \
    \           if (qr <= l || r <= ql) return e();\n            if (ql <= l && r\
    \ <= qr) return sum;\n            S res = e();\n            for (int i = max(l,\
    \ ql); i < min(r, qr); ++i) {\n                res = op(res, data[i - l]);\n \
    \           }\n            return res;\n        }\n    };\n    int n, bsize;\n\
    \    vector<block> blocks;\n    sqrttree() = default;\n    sqrttree(int n) : sqrttree(vector<S>(n,\
    \ e())) {}\n    sqrttree(vector<S> base) {\n        n = base.size();\n       \
    \ bsize = sqrt(n) + 1;\n        for (int i = 0; i < n; i += bsize) {\n       \
    \     blocks.push_back(block{base, i, min(n, i + bsize)});\n        }\n    }\n\
    \    void apply(int i, F f) {\n        assert(0 <= i && i < n);\n        for (auto&\
    \ b : blocks) {\n            if (b.l <= i && i < b.r) {\n                b.apply(i,\
    \ f);\n                return;\n            }\n        }\n    }\n    S operator[](int\
    \ i) {\n        assert(0 <= i && i < n);\n        for (auto& b : blocks) {\n \
    \           if (b.l <= i && i < b.r) {\n                return b.data[i - b.l];\n\
    \            }\n        }\n        assert(false);\n    }\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= n);\n        S res = e();\n  \
    \      for (auto& b : blocks) {\n            res = op(res, b.prod(l, r));\n  \
    \      }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/sqrttree.hpp
  requiredBy: []
  timestamp: '2025-05-12 07:58:05+00:00'
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
