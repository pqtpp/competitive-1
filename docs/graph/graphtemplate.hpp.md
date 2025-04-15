---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  _extendedVerifiedWith:
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
    \ int>\nusing edges = vector<edge<T>>;\ntemplate<class T = int>\nstruct directedgraph\
    \ {\n    vector<edges<T>> data;\n    edges<T> _edges;\n    bool _weighted;\n \
    \   int count;\n    T sumcost;\n    directedgraph(int n, bool weighted=false)\
    \ : data(n), _weighted(weighted), sumcost(T{}) {}\n    void add_edge(int from,\
    \ int to, T cost = 1, int id=-1) {\n        if (id == -1) id = count;\n      \
    \  data[from].push_back(edge(from, to, cost, id));\n        _edges.push_back(edge(from,\
    \ to, cost, id));\n        count++;\n        sumcost += cost;\n    }\n    void\
    \ add_edge(edge<T> eg) {\n        add_edge(eg.from, eg.to, eg.cost, eg.id);\n\
    \    }\n    void read(int m, int indexed = 1) {\n        for (int i=0; i<m; i++)\
    \ {\n            int from, to;\n            T cost=1;\n            cin >> from\
    \ >> to;\n            if (_weighted) cin >> cost;\n            add_edge(from -\
    \ indexed, to - indexed, cost);\n        }\n    }\n    int size() {\n        return\
    \ data.size();\n    }\n    edges<T> operator[](int k) {\n        return data[k];\n\
    \    }\n};\ntemplate<class T = int>\nstruct undirectedgraph {\n    vector<edges<T>>\
    \ data;\n    edges<T> _edges;\n    bool _weighted;\n    int count;\n    T sumcost;\n\
    \    undirectedgraph(int n, bool weighted=false) : data(n), _weighted(weighted),\
    \ sumcost(T{}) {}\n    void add_edge(int from, int to, T cost = 1, int id=-1)\
    \ {\n        if (id == -1) id = count;\n        data[from].push_back(edge(from,\
    \ to, cost, id));\n        _edges.push_back(edge(from, to, cost, id));\n     \
    \   data[from].push_back(edge(to, from, cost, id));\n        count++;\n      \
    \  sumcost += cost;\n    }\n    void add_edge(edge<T> eg) {\n        add_edge(eg.from,\
    \ eg.to, eg.cost, eg.id);\n    }\n    void read(int m, int indexed = 1) {\n  \
    \      for (int i=0; i<m; i++) {\n            int from, to, cost=1;\n        \
    \    cin >> from >> to;\n            if (_weighted) cin >> cost;\n           \
    \ add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n    int size()\
    \ {\n        return data.size();\n    }\n    edges<T> operator[](int k) {\n  \
    \      return data[k];\n    }\n};\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\ntemplate<class\
    \ T = int>\nstruct edge {\n    int from, to;\n    T cost;\n    int id;\n    edge(int\
    \ _from, int _to, T _cost = 1, int _id = -1) : from(_from), to(_to), cost(_cost),\
    \ id(_id) {}\n};\ntemplate<class T = int>\nusing edges = vector<edge<T>>;\ntemplate<class\
    \ T = int>\nstruct directedgraph {\n    vector<edges<T>> data;\n    edges<T> _edges;\n\
    \    bool _weighted;\n    int count;\n    T sumcost;\n    directedgraph(int n,\
    \ bool weighted=false) : data(n), _weighted(weighted), sumcost(T{}) {}\n    void\
    \ add_edge(int from, int to, T cost = 1, int id=-1) {\n        if (id == -1) id\
    \ = count;\n        data[from].push_back(edge(from, to, cost, id));\n        _edges.push_back(edge(from,\
    \ to, cost, id));\n        count++;\n        sumcost += cost;\n    }\n    void\
    \ add_edge(edge<T> eg) {\n        add_edge(eg.from, eg.to, eg.cost, eg.id);\n\
    \    }\n    void read(int m, int indexed = 1) {\n        for (int i=0; i<m; i++)\
    \ {\n            int from, to;\n            T cost=1;\n            cin >> from\
    \ >> to;\n            if (_weighted) cin >> cost;\n            add_edge(from -\
    \ indexed, to - indexed, cost);\n        }\n    }\n    int size() {\n        return\
    \ data.size();\n    }\n    edges<T> operator[](int k) {\n        return data[k];\n\
    \    }\n};\ntemplate<class T = int>\nstruct undirectedgraph {\n    vector<edges<T>>\
    \ data;\n    edges<T> _edges;\n    bool _weighted;\n    int count;\n    T sumcost;\n\
    \    undirectedgraph(int n, bool weighted=false) : data(n), _weighted(weighted),\
    \ sumcost(T{}) {}\n    void add_edge(int from, int to, T cost = 1, int id=-1)\
    \ {\n        if (id == -1) id = count;\n        data[from].push_back(edge(from,\
    \ to, cost, id));\n        _edges.push_back(edge(from, to, cost, id));\n     \
    \   data[from].push_back(edge(to, from, cost, id));\n        count++;\n      \
    \  sumcost += cost;\n    }\n    void add_edge(edge<T> eg) {\n        add_edge(eg.from,\
    \ eg.to, eg.cost, eg.id);\n    }\n    void read(int m, int indexed = 1) {\n  \
    \      for (int i=0; i<m; i++) {\n            int from, to, cost=1;\n        \
    \    cin >> from >> to;\n            if (_weighted) cin >> cost;\n           \
    \ add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n    int size()\
    \ {\n        return data.size();\n    }\n    edges<T> operator[](int k) {\n  \
    \      return data[k];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graphtemplate.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2025-04-15 05:08:18+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu-GRL_2_A.test.cpp
documentation_of: graph/graphtemplate.hpp
layout: document
redirect_from:
- /library/graph/graphtemplate.hpp
- /library/graph/graphtemplate.hpp.html
title: graph/graphtemplate.hpp
---
