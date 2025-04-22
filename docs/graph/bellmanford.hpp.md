---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu-GRL_1_B.test.cpp
    title: verify/aizu-GRL_1_B.test.cpp
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
    \  return data[k];\n    }\n};\n#line 4 \"graph/bellmanford.hpp\"\nusing namespace\
    \ std;\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\u3067\u5358\u4E00\
    \u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B \u8CA0\u9589\u8DEF\
    \u304C\u3042\u308B\u5834\u5408\u306F re[from] < 0 O(nm)\ntemplate <typename T,\
    \ bool directed = true, bool weighted = true>\nvector<T> bellmanford(graph<T,\
    \ directed, weighted>& g, int from = 0) {\n    vector<T> d(g.size(), numeric_limits<T>::max());\n\
    \    d[from] = 0;\n    for (int i=0; i<g.size(); i++) {\n        bool update =\
    \ false;\n        for (int j=0; j<g.size(); j++) {\n            for (auto& _e\
    \ : g[j]) {\n                if (d[j] != numeric_limits<T>::max() && d[j] + _e.cost\
    \ < d[_e.to]) {\n                    d[_e.to] = d[j] + _e.cost;\n            \
    \        update = true;\n                }\n            }\n        }\n       \
    \ if (!update) break;\n    }\n    for (int i=0; i<g.size(); i++) {\n        for\
    \ (auto& _e : g[i]) {\n            if (d[i] != numeric_limits<T>::max() && d[i]\
    \ + _e.cost < d[_e.to]) {\n                d[from] = -1;\n            }\n    \
    \    }\n    }\n    return d;\n}\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\
    \u30C9\u6CD5\u3067\u4E8C\u70B9\u9593\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\
    \u308B \u8CA0\u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\u306F re < 0\ntemplate\
    \ <typename T, bool directed = true, bool weighted = true>\nT bellmanford(graph<T,\
    \ directed, weighted>& g, int from, int to) {\n    if (to == -1) to = g.size()-1;\n\
    \    vector<T> d = bellmanford(g, from);\n    if (d[from] < 0) return -1;\n  \
    \  return d[to];\n}\n"
  code: "#pragma once\n#include \"graphtemplate\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\u3067\
    \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B \u8CA0\
    \u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\u306F re[from] < 0 O(nm)\ntemplate\
    \ <typename T, bool directed = true, bool weighted = true>\nvector<T> bellmanford(graph<T,\
    \ directed, weighted>& g, int from = 0) {\n    vector<T> d(g.size(), numeric_limits<T>::max());\n\
    \    d[from] = 0;\n    for (int i=0; i<g.size(); i++) {\n        bool update =\
    \ false;\n        for (int j=0; j<g.size(); j++) {\n            for (auto& _e\
    \ : g[j]) {\n                if (d[j] != numeric_limits<T>::max() && d[j] + _e.cost\
    \ < d[_e.to]) {\n                    d[_e.to] = d[j] + _e.cost;\n            \
    \        update = true;\n                }\n            }\n        }\n       \
    \ if (!update) break;\n    }\n    for (int i=0; i<g.size(); i++) {\n        for\
    \ (auto& _e : g[i]) {\n            if (d[i] != numeric_limits<T>::max() && d[i]\
    \ + _e.cost < d[_e.to]) {\n                d[from] = -1;\n            }\n    \
    \    }\n    }\n    return d;\n}\n// \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\
    \u30C9\u6CD5\u3067\u4E8C\u70B9\u9593\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\
    \u308B \u8CA0\u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\u306F re < 0\ntemplate\
    \ <typename T, bool directed = true, bool weighted = true>\nT bellmanford(graph<T,\
    \ directed, weighted>& g, int from, int to) {\n    if (to == -1) to = g.size()-1;\n\
    \    vector<T> d = bellmanford(g, from);\n    if (d[from] < 0) return -1;\n  \
    \  return d[to];\n}"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/bellmanford.hpp
  requiredBy: []
  timestamp: '2025-04-22 08:33:36+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu-GRL_1_B.test.cpp
documentation_of: graph/bellmanford.hpp
layout: document
redirect_from:
- /library/graph/bellmanford.hpp
- /library/graph/bellmanford.hpp.html
title: graph/bellmanford.hpp
---
