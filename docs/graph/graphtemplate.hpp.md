---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bellmanford.hpp
    title: graph/bellmanford.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstrarestore.hpp
    title: graph/dijkstrarestore.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: graph/warshallfloyd.hpp
    title: graph/warshallfloyd.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_1_A.test.cpp
    title: verify/aizu-GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_1_C.test.cpp
    title: verify/aizu-GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_2_A.test.cpp
    title: verify/aizu-GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-scc.test.cpp
    title: verify/yosupo-scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-shortest_path.test.cpp
    title: verify/yosupo-shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graphtemplate.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n// \u8FBA\u306E\u69CB\u9020\u4F53 edge(from, to, cost, id)\n\
    template<class T = int>\nstruct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n// \u9802\u70B9\u306E\u69CB\u9020\u4F53 vector<edge<T>>\ntemplate<class\
    \ T = int>\nusing edges = vector<edge<T>>;\n// \u30B0\u30E9\u30D5\u306E\u69CB\u9020\
    \u4F53 graph<T, directed, weighted> \ntemplate <class T = int, bool directed =\
    \ false, bool weighted = false>\nstruct graph {\n    bool isdirected, isweighted;\n\
    \    edges<T> _edges;\n    vector<edges<T>> data;\n    T sumcost;\n    graph(int\
    \ n) : isdirected(directed), isweighted(weighted), data(n), sumcost(T{}) {}\n\
    \    // from \u304B\u3089 to \u3078\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n    void\
    \ add_edge(int from, int to, T cost = 1, int id = -1) {\n        if (id == -1)\
    \ id = _edges.size();\n        data[from].push_back(edge<T>(from, to, cost, id));\n\
    \        _edges.push_back(edge<T>(from, to, cost, id));\n        if (!isdirected)\
    \ {\n            data[to].push_back(edge<T>(to, from, cost, id));\n        }\n\
    \        sumcost += cost;\n    }\n    // \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n\
    \    void add_edge(edge<T> _e) {\n        add_edge(_e.from, _e.to, _e.cost, _e.id);\n\
    \    }\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u8FBA\u3092\u8AAD\u307F\u8FBC\
    \u3080\n    void read(int m, int indexed = 1) {\n        for (int i=0; i<m; i++)\
    \ {\n            int from, to;\n            T cost = 1;\n            cin >> from\
    \ >> to;\n            if (isweighted) cin >> cost;\n            add_edge(from\
    \ - indexed, to - indexed, cost);\n        }\n    }\n    // \u9802\u70B9\u6570\
    \u3092\u8FD4\u3059\n    int size() {\n        return data.size();\n    }\n   \
    \ // \u9802\u70B9\u3092\u8FD4\u3059\n    edges<T> operator[](int k) {\n      \
    \  return data[k];\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\n// \u8FBA\u306E\
    \u69CB\u9020\u4F53 edge(from, to, cost, id)\ntemplate<class T = int>\nstruct edge\
    \ {\n    int from, to;\n    T cost;\n    int id;\n};\n// \u9802\u70B9\u306E\u69CB\
    \u9020\u4F53 vector<edge<T>>\ntemplate<class T = int>\nusing edges = vector<edge<T>>;\n\
    // \u30B0\u30E9\u30D5\u306E\u69CB\u9020\u4F53 graph<T, directed, weighted> \n\
    template <class T = int, bool directed = false, bool weighted = false>\nstruct\
    \ graph {\n    bool isdirected, isweighted;\n    edges<T> _edges;\n    vector<edges<T>>\
    \ data;\n    T sumcost;\n    graph(int n) : isdirected(directed), isweighted(weighted),\
    \ data(n), sumcost(T{}) {}\n    // from \u304B\u3089 to \u3078\u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\n    void add_edge(int from, int to, T cost = 1, int id = -1)\
    \ {\n        if (id == -1) id = _edges.size();\n        data[from].push_back(edge<T>(from,\
    \ to, cost, id));\n        _edges.push_back(edge<T>(from, to, cost, id));\n  \
    \      if (!isdirected) {\n            data[to].push_back(edge<T>(to, from, cost,\
    \ id));\n        }\n        sumcost += cost;\n    }\n    // \u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\n    void add_edge(edge<T> _e) {\n        add_edge(_e.from,\
    \ _e.to, _e.cost, _e.id);\n    }\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u8FBA\
    \u3092\u8AAD\u307F\u8FBC\u3080\n    void read(int m, int indexed = 1) {\n    \
    \    for (int i=0; i<m; i++) {\n            int from, to;\n            T cost\
    \ = 1;\n            cin >> from >> to;\n            if (isweighted) cin >> cost;\n\
    \            add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n\
    \    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\n    int size() {\n        return\
    \ data.size();\n    }\n    // \u9802\u70B9\u3092\u8FD4\u3059\n    edges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graphtemplate.hpp
  requiredBy:
  - graph/warshallfloyd.hpp
  - graph/kruskal.hpp
  - graph/scc.hpp
  - graph/bellmanford.hpp
  - graph/dijkstra.hpp
  - graph/dijkstrarestore.hpp
  timestamp: '2025-04-22 03:48:04+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-shortest_path.test.cpp
  - verify/aizu-GRL_2_A.test.cpp
  - verify/aizu-GRL_1_C.test.cpp
  - verify/aizu-GRL_1_A.test.cpp
  - verify/yosupo-scc.test.cpp
documentation_of: graph/graphtemplate.hpp
layout: document
redirect_from:
- /library/graph/graphtemplate.hpp
- /library/graph/graphtemplate.hpp.html
title: graph/graphtemplate.hpp
---
