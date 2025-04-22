---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-scc.test.cpp
    title: verify/yosupo-scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 4 \"graph/scc.hpp\"\nusing namespace std;\ntemplate<class T = int, bool directed\
    \ = true, bool weighted = false>\nvector<vector<int>> scc(graph<T, directed, weighted>&\
    \ g) {\n    int n = g.size();\n    vector<int> low(n), num(n, -1), stack;\n  \
    \  vector<bool> onStack(n);\n    vector<vector<int>> re;\n    auto dfs = [&](auto&\
    \ self, int x) -> void {\n        low[x] = num[x] = stack.size();\n        stack.push_back(x);\n\
    \        onStack[x] = true;\n        for (auto& _e : g[x]) {\n            int\
    \ y = _e.to;\n            if (num[y] == -1) {\n                self(self, y);\n\
    \                low[x] = min(low[x], low[y]);\n            } else if (onStack[y])\
    \ {\n                low[x] = min(low[x], num[y]);\n            }\n        }\n\
    \        if (low[x] == num[x]) {\n            vector<int> component;\n       \
    \     while (true) {\n                int y = stack.back(); stack.pop_back();\
    \ onStack[y] = false;\n                component.push_back(y);\n             \
    \   if (y == x) break;\n            }\n            re.push_back(component);\n\
    \        }\n    };\n    for (int i=0; i<n; i++) if (num[i] == -1) dfs(dfs, i);\n\
    \    reverse(re.begin(), re.end());\n    return re;\n}\n"
  code: "#pragma once\n#include \"graphtemplate\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate<class T = int, bool directed = true, bool weighted\
    \ = false>\nvector<vector<int>> scc(graph<T, directed, weighted>& g) {\n    int\
    \ n = g.size();\n    vector<int> low(n), num(n, -1), stack;\n    vector<bool>\
    \ onStack(n);\n    vector<vector<int>> re;\n    auto dfs = [&](auto& self, int\
    \ x) -> void {\n        low[x] = num[x] = stack.size();\n        stack.push_back(x);\n\
    \        onStack[x] = true;\n        for (auto& _e : g[x]) {\n            int\
    \ y = _e.to;\n            if (num[y] == -1) {\n                self(self, y);\n\
    \                low[x] = min(low[x], low[y]);\n            } else if (onStack[y])\
    \ {\n                low[x] = min(low[x], num[y]);\n            }\n        }\n\
    \        if (low[x] == num[x]) {\n            vector<int> component;\n       \
    \     while (true) {\n                int y = stack.back(); stack.pop_back();\
    \ onStack[y] = false;\n                component.push_back(y);\n             \
    \   if (y == x) break;\n            }\n            re.push_back(component);\n\
    \        }\n    };\n    for (int i=0; i<n; i++) if (num[i] == -1) dfs(dfs, i);\n\
    \    reverse(re.begin(), re.end());\n    return re;\n}"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2025-04-22 03:33:46+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-scc.test.cpp
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
