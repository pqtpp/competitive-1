---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-static_range_inversions_query.test.cpp
    title: verify/yosupo-static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/Mo.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nstruct Mo {\n    int n;\n    vector<pair<int, int>> queries;\n    explicit\
    \ Mo(int n) : n(n) {}\n    void add(int l, int r) {\n        queries.push_back({l,\
    \ r});\n    }\n    long long hilbert_order(int x, int y, int p=20, int rotate\
    \ = 0) {\n        long long d = 0;\n        for (int s = 1 << (p - 1); s; s >>=\
    \ 1) {\n            int rx = (x & s) > 0;\n            int ry = (y & s) > 0;\n\
    \            int r = (rx << 1) | ry;\n            r = (r + rotate) & 3;\n    \
    \        d = (d << 2) | r;\n            static const int rotate_delta[4] = {3,\
    \ 0, 0, 1};\n            rotate = (rotate + rotate_delta[r]) & 3;\n        }\n\
    \        return d;\n    }\n    template< typename AL, typename AR, typename EL,\
    \ typename ER, typename O >\n    void build(const AL &add_left, const AR &add_right,\
    \ const EL &erase_left, const ER &erase_right, const O &out) {\n        int q\
    \ = (int) queries.size();\n        vector< int > ord(q);\n        iota(begin(ord),\
    \ end(ord), 0);\n        vector< long long > hs(q);\n        for (int i = 0; i\
    \ < q; i++) {\n            hs[i] = hilbert_order(queries[i].first, queries[i].second);\n\
    \        }\n        sort(begin(ord), end(ord), [&](int a, int b) {\n         \
    \   return hs[a] < hs[b];\n        });\n        int l = 0, r = 0;\n        for(auto\
    \ idx : ord) {\n            while(l > queries[idx].first) add_left(--l);\n   \
    \         while(r < queries[idx].second) add_right(r++);\n            while(l\
    \ < queries[idx].first) erase_left(l++);\n            while(r > queries[idx].second)\
    \ erase_right(--r);\n            out(idx);\n        }\n    }\n    template< typename\
    \ A, typename E, typename O >\n    void build(const A &add, const E &erase, const\
    \ O &out) {\n        build(add, add, erase, erase, out);\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\nstruct Mo {\n\
    \    int n;\n    vector<pair<int, int>> queries;\n    explicit Mo(int n) : n(n)\
    \ {}\n    void add(int l, int r) {\n        queries.push_back({l, r});\n    }\n\
    \    long long hilbert_order(int x, int y, int p=20, int rotate = 0) {\n     \
    \   long long d = 0;\n        for (int s = 1 << (p - 1); s; s >>= 1) {\n     \
    \       int rx = (x & s) > 0;\n            int ry = (y & s) > 0;\n           \
    \ int r = (rx << 1) | ry;\n            r = (r + rotate) & 3;\n            d =\
    \ (d << 2) | r;\n            static const int rotate_delta[4] = {3, 0, 0, 1};\n\
    \            rotate = (rotate + rotate_delta[r]) & 3;\n        }\n        return\
    \ d;\n    }\n    template< typename AL, typename AR, typename EL, typename ER,\
    \ typename O >\n    void build(const AL &add_left, const AR &add_right, const\
    \ EL &erase_left, const ER &erase_right, const O &out) {\n        int q = (int)\
    \ queries.size();\n        vector< int > ord(q);\n        iota(begin(ord), end(ord),\
    \ 0);\n        vector< long long > hs(q);\n        for (int i = 0; i < q; i++)\
    \ {\n            hs[i] = hilbert_order(queries[i].first, queries[i].second);\n\
    \        }\n        sort(begin(ord), end(ord), [&](int a, int b) {\n         \
    \   return hs[a] < hs[b];\n        });\n        int l = 0, r = 0;\n        for(auto\
    \ idx : ord) {\n            while(l > queries[idx].first) add_left(--l);\n   \
    \         while(r < queries[idx].second) add_right(r++);\n            while(l\
    \ < queries[idx].first) erase_left(l++);\n            while(r > queries[idx].second)\
    \ erase_right(--r);\n            out(idx);\n        }\n    }\n    template< typename\
    \ A, typename E, typename O >\n    void build(const A &add, const E &erase, const\
    \ O &out) {\n        build(add, add, erase, erase, out);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/Mo.hpp
  requiredBy: []
  timestamp: '2025-04-18 08:05:01+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-static_range_inversions_query.test.cpp
documentation_of: util/Mo.hpp
layout: document
redirect_from:
- /library/util/Mo.hpp
- /library/util/Mo.hpp.html
title: util/Mo.hpp
---
