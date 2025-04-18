---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graphtemplate.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate<class T = int>\nstruct edge {\n    int from, to;\n\
    \    T cost;\n    int id;\n};\ntemplate<class T = int>\nusing edges = vector<edge<T>>;\n\
    template <class T = int, bool directed = false, bool weighted = false>\nstruct\
    \ graph {\n    bool isdirected, isweighted;\n    edges<T> _edges;\n    vector<edges<T>>\
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
    \  }\n    edges<T> operator[](int k) {\n        return data[k];\n    }\n};\n#line\
    \ 4 \"graph/dijkstrarestore.hpp\"\nusing namespace std;\ntemplate<class T = int,\
    \ bool directed = false, bool weighted = true>\nvector<int> dijkstrarestore(graph<T,\
    \ directed, weighted>& g, int from = 0, int to = -1) {\n    if (to == -1) to =\
    \ g.size() - 1;\n    vector<int> prev(g.size(), -1);\n    vector<T> dist(g.size(),\
    \ numeric_limits<T>::max()); dist[from] = T{};\n    priority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> q;\n    q.push({T{}, from});\n\
    \    while (!q.empty()) {\n        auto [t, x] = q.top(); q.pop();\n        if\
    \ (dist[x] < t) continue;\n        for (auto& _e : g[x]) {\n            int y\
    \ = _e.to;\n            if (dist[x] + _e.cost < dist[y]) {\n                dist[y]\
    \ = dist[x] + _e.cost;\n                q.push({dist[y], y});\n              \
    \  prev[y] = x;\n            }\n        }\n    }\n    vector<int> path;\n    for\
    \ (int i=to; i!=-1; i=prev[i]) path.push_back(i);\n    reverse(path.begin(), path.end());\n\
    \    return path;\n}\n"
  code: "#pragma once\n#include \"graphtemplate\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate<class T = int, bool directed = false, bool weighted\
    \ = true>\nvector<int> dijkstrarestore(graph<T, directed, weighted>& g, int from\
    \ = 0, int to = -1) {\n    if (to == -1) to = g.size() - 1;\n    vector<int> prev(g.size(),\
    \ -1);\n    vector<T> dist(g.size(), numeric_limits<T>::max()); dist[from] = T{};\n\
    \    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>\
    \ q;\n    q.push({T{}, from});\n    while (!q.empty()) {\n        auto [t, x]\
    \ = q.top(); q.pop();\n        if (dist[x] < t) continue;\n        for (auto&\
    \ _e : g[x]) {\n            int y = _e.to;\n            if (dist[x] + _e.cost\
    \ < dist[y]) {\n                dist[y] = dist[x] + _e.cost;\n               \
    \ q.push({dist[y], y});\n                prev[y] = x;\n            }\n       \
    \ }\n    }\n    vector<int> path;\n    for (int i=to; i!=-1; i=prev[i]) path.push_back(i);\n\
    \    reverse(path.begin(), path.end());\n    return path;\n}"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/dijkstrarestore.hpp
  requiredBy: []
  timestamp: '2025-04-18 06:49:55+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstrarestore.hpp
layout: document
redirect_from:
- /library/graph/dijkstrarestore.hpp
- /library/graph/dijkstrarestore.hpp.html
title: graph/dijkstrarestore.hpp
---
