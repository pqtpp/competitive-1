---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \ id = _edges.size() / (2 - directed);\n        data[from].push_back(edge<T>(from,\
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
    \ k) {\n        return data[k];\n    }\n};\n#line 4 \"graph/dijkstrarestore.hpp\"\
    \nusing namespace std;\n// \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3092\u7528\
    \u3044\u3066\u4E8C\u70B9\u9593\u6700\u77ED\u7D4C\u8DEF\u306E\u901A\u308B\u9802\
    \u70B9\u3092\u8FD4\u3059 \u305F\u3060\u3057\u3001\u8CA0\u9589\u8DEF\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u3053\u3068 O(m log n)\ntemplate<class T = int, bool\
    \ directed = false, bool weighted = true>\nvector<int> dijkstrarestore(graph<T,\
    \ directed, weighted>& g, int from = 0, int to = -1) {\n    if (to == -1) to =\
    \ g.size() - 1;\n    vector<int> prev(g.size(), -1);\n    vector<T> dist(g.size(),\
    \ numeric_limits<T>::max()); dist[from] = T{};\n    vector<bool> visited(g.size());\n\
    \    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>\
    \ q;\n    q.push({T{}, from});\n    while (!q.empty()) {\n        auto [t, x]\
    \ = q.top(); q.pop();\n        if (visited[x]) continue;\n        visited[x] =\
    \ true;\n        for (auto& _e : g[x]) {\n            int y = _e.to;\n       \
    \     if (dist[x] + _e.cost < dist[y]) {\n                dist[y] = dist[x] +\
    \ _e.cost;\n                q.push({dist[y], y});\n                prev[y] = x;\n\
    \            }\n        }\n    }\n    vector<int> path;\n    for (int i=to; i!=-1;\
    \ i=prev[i]) path.push_back(i);\n    reverse(path.begin(), path.end());\n    return\
    \ path;\n}\n"
  code: "#pragma once\n#include \"graphtemplate\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n// \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3092\u7528\u3044\
    \u3066\u4E8C\u70B9\u9593\u6700\u77ED\u7D4C\u8DEF\u306E\u901A\u308B\u9802\u70B9\
    \u3092\u8FD4\u3059 \u305F\u3060\u3057\u3001\u8CA0\u9589\u8DEF\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u3053\u3068 O(m log n)\ntemplate<class T = int, bool directed\
    \ = false, bool weighted = true>\nvector<int> dijkstrarestore(graph<T, directed,\
    \ weighted>& g, int from = 0, int to = -1) {\n    if (to == -1) to = g.size()\
    \ - 1;\n    vector<int> prev(g.size(), -1);\n    vector<T> dist(g.size(), numeric_limits<T>::max());\
    \ dist[from] = T{};\n    vector<bool> visited(g.size());\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> q;\n    q.push({T{}, from});\n\
    \    while (!q.empty()) {\n        auto [t, x] = q.top(); q.pop();\n        if\
    \ (visited[x]) continue;\n        visited[x] = true;\n        for (auto& _e :\
    \ g[x]) {\n            int y = _e.to;\n            if (dist[x] + _e.cost < dist[y])\
    \ {\n                dist[y] = dist[x] + _e.cost;\n                q.push({dist[y],\
    \ y});\n                prev[y] = x;\n            }\n        }\n    }\n    vector<int>\
    \ path;\n    for (int i=to; i!=-1; i=prev[i]) path.push_back(i);\n    reverse(path.begin(),\
    \ path.end());\n    return path;\n}"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/dijkstrarestore.hpp
  requiredBy: []
  timestamp: '2025-05-01 02:48:04+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-shortest_path.test.cpp
documentation_of: graph/dijkstrarestore.hpp
layout: document
redirect_from:
- /library/graph/dijkstrarestore.hpp
- /library/graph/dijkstrarestore.hpp.html
title: graph/dijkstrarestore.hpp
---
