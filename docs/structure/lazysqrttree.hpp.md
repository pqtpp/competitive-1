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
  bundledCode: "#line 2 \"structure/lazysqrttree.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\ntemplate <class S, auto op, auto e, class F, auto mapping,\
    \ auto composition, auto id>\nstruct lazysqrttree {\n    struct block {\n    \
    \    int l, r;\n        vector<S> data;\n        S sum;\n        F lazy;\n   \
    \     bool flag;\n        block() = default;\n        block(vector<S>& base, int\
    \ l_, int r_) : l(l_), r(r_), data(base.begin() + l_, base.begin() + r_), sum(e()),\
    \ lazy(id()), flag(false) {\n            rebuild();\n        }\n        void apply(F\
    \ f) {\n            lazy = composition(f, lazy);\n            flag = true;\n \
    \       }\n        void push() {\n            if (!flag) return;\n           \
    \ for (int i=0; i<r-l; i++) data[i] = mapping(lazy, data[i], 1);\n           \
    \ lazy = id();\n            flag = false;\n            rebuild();\n        }\n\
    \        void rebuild() {\n            sum = e();\n            for (auto& x :\
    \ data) sum = op(sum, x);\n        }\n        void apply(int ql, int qr, F f)\
    \ {\n            if (qr <= l || r <= ql) return;\n            if (ql <= l && r\
    \ <= qr) {\n                apply(f);\n                return;\n            }\n\
    \            push();\n            for (int i = max(l, ql); i < min(r, qr); ++i)\n\
    \                data[i - l] = mapping(f, data[i - l], 1);\n            rebuild();\n\
    \        }\n        S prod(int ql, int qr) {\n            if (qr<=l || r<=ql)\
    \ return e();\n            if (ql<=l && r<=qr) return (flag ? mapping(lazy, sum,\
    \ r - l) : sum);\n            push();\n            S res = e();\n            for\
    \ (int i=max(l, ql); i<min(r, qr); i++) res = op(res, data[i - l]);\n        \
    \    return res;\n        }\n    };\n    int n, bsize;\n    vector<block> blocks;\n\
    \    lazysqrttree() = default;\n    lazysqrttree(vector<S>& base) {\n        n\
    \ = base.size();\n        bsize = sqrt(n) + 1;\n        for (int i=0; i<n; i+=bsize)\
    \ {\n            blocks.push_back(block{base, i, min(n, i + bsize)});\n      \
    \  }\n    }\n    void apply(int l, int r, F f) {\n        for (auto& b : blocks)\
    \ b.apply(l, r, f);\n    }\n    S prod(int l, int r) {\n        S res = e();\n\
    \        for (auto& b : blocks)\n            res = op(res, b.prod(l, r));\n  \
    \      return res;\n    }\n    void set(int i, S x) {\n        assert(0 <= i &&\
    \ i < n);\n        for (auto& b : blocks) {\n            if (b.l <= i && i < b.r)\
    \ {\n                b.push();\n                b.data[i - b.l] = x;\n       \
    \         b.rebuild();\n                return;\n            }\n        }\n  \
    \  }\n    S get(int i) {\n        assert(0 <= i && i < n);\n        for (auto&\
    \ b : blocks) {\n            if (b.l <= i && i < b.r) {\n                if (b.flag)\
    \ b.push();\n                return b.data[i - b.l];\n            }\n        }\n\
    \        assert(false);\n    }\n    S operator[](int i) {\n        return get(i);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\ntemplate <class\
    \ S, auto op, auto e, class F, auto mapping, auto composition, auto id>\nstruct\
    \ lazysqrttree {\n    struct block {\n        int l, r;\n        vector<S> data;\n\
    \        S sum;\n        F lazy;\n        bool flag;\n        block() = default;\n\
    \        block(vector<S>& base, int l_, int r_) : l(l_), r(r_), data(base.begin()\
    \ + l_, base.begin() + r_), sum(e()), lazy(id()), flag(false) {\n            rebuild();\n\
    \        }\n        void apply(F f) {\n            lazy = composition(f, lazy);\n\
    \            flag = true;\n        }\n        void push() {\n            if (!flag)\
    \ return;\n            for (int i=0; i<r-l; i++) data[i] = mapping(lazy, data[i],\
    \ 1);\n            lazy = id();\n            flag = false;\n            rebuild();\n\
    \        }\n        void rebuild() {\n            sum = e();\n            for\
    \ (auto& x : data) sum = op(sum, x);\n        }\n        void apply(int ql, int\
    \ qr, F f) {\n            if (qr <= l || r <= ql) return;\n            if (ql\
    \ <= l && r <= qr) {\n                apply(f);\n                return;\n   \
    \         }\n            push();\n            for (int i = max(l, ql); i < min(r,\
    \ qr); ++i)\n                data[i - l] = mapping(f, data[i - l], 1);\n     \
    \       rebuild();\n        }\n        S prod(int ql, int qr) {\n            if\
    \ (qr<=l || r<=ql) return e();\n            if (ql<=l && r<=qr) return (flag ?\
    \ mapping(lazy, sum, r - l) : sum);\n            push();\n            S res =\
    \ e();\n            for (int i=max(l, ql); i<min(r, qr); i++) res = op(res, data[i\
    \ - l]);\n            return res;\n        }\n    };\n    int n, bsize;\n    vector<block>\
    \ blocks;\n    lazysqrttree() = default;\n    lazysqrttree(vector<S>& base) {\n\
    \        n = base.size();\n        bsize = sqrt(n) + 1;\n        for (int i=0;\
    \ i<n; i+=bsize) {\n            blocks.push_back(block{base, i, min(n, i + bsize)});\n\
    \        }\n    }\n    void apply(int l, int r, F f) {\n        for (auto& b :\
    \ blocks) b.apply(l, r, f);\n    }\n    S prod(int l, int r) {\n        S res\
    \ = e();\n        for (auto& b : blocks)\n            res = op(res, b.prod(l,\
    \ r));\n        return res;\n    }\n    void set(int i, S x) {\n        assert(0\
    \ <= i && i < n);\n        for (auto& b : blocks) {\n            if (b.l <= i\
    \ && i < b.r) {\n                b.push();\n                b.data[i - b.l] =\
    \ x;\n                b.rebuild();\n                return;\n            }\n \
    \       }\n    }\n    S get(int i) {\n        assert(0 <= i && i < n);\n     \
    \   for (auto& b : blocks) {\n            if (b.l <= i && i < b.r) {\n       \
    \         if (b.flag) b.push();\n                return b.data[i - b.l];\n   \
    \         }\n        }\n        assert(false);\n    }\n    S operator[](int i)\
    \ {\n        return get(i);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/lazysqrttree.hpp
  requiredBy: []
  timestamp: '2025-05-12 07:23:50+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/lazysqrttree.hpp
layout: document
redirect_from:
- /library/structure/lazysqrttree.hpp
- /library/structure/lazysqrttree.hpp.html
title: structure/lazysqrttree.hpp
---
