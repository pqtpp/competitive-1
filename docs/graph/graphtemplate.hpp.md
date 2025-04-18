---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_1_A.test.cpp
    title: verify/aizu-GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_2_A.test.cpp
    title: verify/aizu-GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graphtemplate.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate<class T = int>\nstruct edge {\n    int from, to;\n\
    \    T cost;\n    int id;\n    edge(int _from, int _to, T _cost = 1, int _id =\
    \ -1) : from(_from), to(_to), cost(_cost), id(_id) {}\n};\ntemplate<class T =\
    \ int>\nusing edges = vector<edge<T>>;\ntemplate <class T = int, bool directed\
    \ = false, bool weighted = false>\nstruct graph {\n    bool isdirected, isweighted;\n\
    \    edges<T> _edges;\n    vector<edges<T>> data;\n    T sumcost;\n    graph(int\
    \ n) : isdirected(directed), isweighted(weighted), data(n), sumcost(T{}) {}\n\
    \    void add_edge(int from, int to, T cost = 1, int id = -1) {\n        if (id\
    \ == -1) id = _edges.size();\n        data[from].push_back(edge<T>(from, to, cost,\
    \ id));\n        _edges.push_back(edge<T>(from, to, cost, id));\n        if (!isdirected)\
    \ {\n            data[to].push_back(edge<T>(to, from, cost, id));\n        }\n\
    \        sumcost += cost;\n    }\n    void add_edge(edge<T> _e) {\n        add_edge(_e.from,\
    \ _e.to, _e.cost, _e.id);\n    }\n    void read(int m, int indexed = 1) {\n  \
    \      for (int i=0; i<m; i++) {\n            int from, to;\n            T cost\
    \ = 1;\n            cin >> from >> to;\n            if (isweighted) cin >> cost;\n\
    \            add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n\
    \    int size() {\n        return data.size();\n    }\n    edges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\ntemplate<class\
    \ T = int>\nstruct edge {\n    int from, to;\n    T cost;\n    int id;\n    edge(int\
    \ _from, int _to, T _cost = 1, int _id = -1) : from(_from), to(_to), cost(_cost),\
    \ id(_id) {}\n};\ntemplate<class T = int>\nusing edges = vector<edge<T>>;\ntemplate\
    \ <class T = int, bool directed = false, bool weighted = false>\nstruct graph\
    \ {\n    bool isdirected, isweighted;\n    edges<T> _edges;\n    vector<edges<T>>\
    \ data;\n    T sumcost;\n    graph(int n) : isdirected(directed), isweighted(weighted),\
    \ data(n), sumcost(T{}) {}\n    void add_edge(int from, int to, T cost = 1, int\
    \ id = -1) {\n        if (id == -1) id = _edges.size();\n        data[from].push_back(edge<T>(from,\
    \ to, cost, id));\n        _edges.push_back(edge<T>(from, to, cost, id));\n  \
    \      if (!isdirected) {\n            data[to].push_back(edge<T>(to, from, cost,\
    \ id));\n        }\n        sumcost += cost;\n    }\n    void add_edge(edge<T>\
    \ _e) {\n        add_edge(_e.from, _e.to, _e.cost, _e.id);\n    }\n    void read(int\
    \ m, int indexed = 1) {\n        for (int i=0; i<m; i++) {\n            int from,\
    \ to;\n            T cost = 1;\n            cin >> from >> to;\n            if\
    \ (isweighted) cin >> cost;\n            add_edge(from - indexed, to - indexed,\
    \ cost);\n        }\n    }\n    int size() {\n        return data.size();\n  \
    \  }\n    edges<T> operator[](int k) {\n        return data[k];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graphtemplate.hpp
  requiredBy:
  - graph/kruskal.hpp
  - graph/dijkstra.hpp
  timestamp: '2025-04-18 03:43:20+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu-GRL_2_A.test.cpp
  - verify/aizu-GRL_1_A.test.cpp
documentation_of: graph/graphtemplate.hpp
layout: document
redirect_from:
- /library/graph/graphtemplate.hpp
- /library/graph/graphtemplate.hpp.html
title: graph/graphtemplate.hpp
---
