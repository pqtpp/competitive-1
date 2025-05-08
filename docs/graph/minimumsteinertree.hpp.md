---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/yosupo-minimum_steiner_tree.cpp
    title: verify/yosupo-minimum_steiner_tree.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graphtemplate.hpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n// \u8FBA\u306E\u69CB\u9020\u4F53 edge(from, to, cost, id)\n\
    template<class T = int>\nstruct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n};\n// \u9802\u70B9\u306E\u69CB\u9020\u4F53 vector<edge<T>>\ntemplate<class\
    \ T = int>\nusing edges = vector<edge<T>>;\n// \u30B0\u30E9\u30D5\u306E\u69CB\u9020\
    \u4F53 graph<T, directed, weighted> \ntemplate <class T = int, bool directed =\
    \ false, bool weighted = false>\nstruct graph {\n    bool isdirected, isweighted;\n\
    \    edges<T> _edges;\n    vector<edges<T>> data;\n    T sumcost;\n    graph()\
    \ = default;\n    // \u9802\u70B9\u6570 n \u306E\u30B0\u30E9\u30D5\u3092\u4F5C\
    \u6210\u3059\u308B\n    graph(int n) : isdirected(directed), isweighted(weighted),\
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
    \ k) {\n        return data[k];\n    }\n};\n#line 4 \"graph/minimumsteinertree.hpp\"\
    \nusing namespace std;\ntemplate <class T, bool directed = false, bool weighted\
    \ = true>\nvector<int> minimumsteinertree(graph<T, directed, weighted> &g, vector<int>\
    \ &v) {\n    vector<vector<T>> dp(1<<v.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    vector<vector<int>> id(g.size(), vector<int>(g.size(), -1));\n    vector<vector<pair<int,\
    \ int>>> par(1<<v.size(), vector<pair<int, int>>(g.size(), {-1, -1}));\n    for\
    \ (auto& _e : g._edges) {\n        if (_e.cost < d[_e.from][_e.to]) {\n      \
    \      d[_e.from][_e.to] = _e.cost;\n            d[_e.to][_e.from] = _e.cost;\n\
    \            id[_e.from][_e.to] = _e.id;\n            id[_e.to][_e.from] = _e.id;\n\
    \        }\n    }\n    for (int i=0; i<g.size(); i++) {\n        d[i][i] = 0;\n\
    \    }\n    for (int i=0; i<v.size(); i++) {\n        dp[1<<i][v[i]] = 0;\n  \
    \  }\n    for (int i=0; i<(1<<v.size()); i++) {\n        for (int j=i; 0<j; j=(j-1)&i)\
    \ {\n            for (int k=0; k<g.size(); k++) {\n                if (dp[j][k]\
    \ == numeric_limits<T>::max() || dp[i^j][k] == numeric_limits<T>::max()) continue;\n\
    \                if (dp[j][k] + dp[i^j][k] < dp[i][k]) {\n                   \
    \ dp[i][k] = dp[j][k] + dp[i^j][k];\n                    par[i][k] = {0, j};\n\
    \                }\n            }\n        }\n        priority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> q;\n        for (int j=0; j<g.size();\
    \ j++) {\n            if (dp[i][j] != numeric_limits<T>::max()) q.push({dp[i][j],\
    \ j});\n        }\n        while (!q.empty()) {\n            auto [x, y] = q.top();\
    \ q.pop();\n            if (dp[i][y] < x) continue;\n            for (auto& _e\
    \ : g[y]) {\n                if (x + _e.cost < dp[i][_e.to]) {\n             \
    \       dp[i][_e.to] = x + _e.cost;\n                    q.push({x + _e.cost,\
    \ _e.to});\n                    par[i][_e.to] = {1, _e.from};\n              \
    \  }\n            }\n        }\n    }\n    vector<int> res;\n    int c = -1;\n\
    \    T ans = numeric_limits<T>::max();\n    for (int i=0; i<g.size(); i++) {\n\
    \        if (dp.back()[i] < ans) {\n            ans = dp.back()[i];\n        \
    \    c = i;\n        }\n    }\n    if (c == -1) return res;\n    stack<pair<int,\
    \ int>> s;\n    s.push({(1<<v.size())-1, c});\n    while (!s.empty()) {\n    \
    \    auto [x, y] = s.top(); s.pop();\n        auto [X, Y] = par[x][y];\n     \
    \   if (X == -1) continue;\n        else if (X == 0) {\n            s.push({Y,\
    \ c});\n            s.push({x^Y, c});\n        } else if (X == 1) {\n        \
    \    s.push({x, Y});\n            res.push_back(id[y][Y]);\n        }\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\n#include \"graphtemplate\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T, bool directed = false, bool weighted = true>\n\
    vector<int> minimumsteinertree(graph<T, directed, weighted> &g, vector<int> &v)\
    \ {\n    vector<vector<T>> dp(1<<v.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    vector<vector<int>> id(g.size(), vector<int>(g.size(), -1));\n    vector<vector<pair<int,\
    \ int>>> par(1<<v.size(), vector<pair<int, int>>(g.size(), {-1, -1}));\n    for\
    \ (auto& _e : g._edges) {\n        if (_e.cost < d[_e.from][_e.to]) {\n      \
    \      d[_e.from][_e.to] = _e.cost;\n            d[_e.to][_e.from] = _e.cost;\n\
    \            id[_e.from][_e.to] = _e.id;\n            id[_e.to][_e.from] = _e.id;\n\
    \        }\n    }\n    for (int i=0; i<g.size(); i++) {\n        d[i][i] = 0;\n\
    \    }\n    for (int i=0; i<v.size(); i++) {\n        dp[1<<i][v[i]] = 0;\n  \
    \  }\n    for (int i=0; i<(1<<v.size()); i++) {\n        for (int j=i; 0<j; j=(j-1)&i)\
    \ {\n            for (int k=0; k<g.size(); k++) {\n                if (dp[j][k]\
    \ == numeric_limits<T>::max() || dp[i^j][k] == numeric_limits<T>::max()) continue;\n\
    \                if (dp[j][k] + dp[i^j][k] < dp[i][k]) {\n                   \
    \ dp[i][k] = dp[j][k] + dp[i^j][k];\n                    par[i][k] = {0, j};\n\
    \                }\n            }\n        }\n        priority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> q;\n        for (int j=0; j<g.size();\
    \ j++) {\n            if (dp[i][j] != numeric_limits<T>::max()) q.push({dp[i][j],\
    \ j});\n        }\n        while (!q.empty()) {\n            auto [x, y] = q.top();\
    \ q.pop();\n            if (dp[i][y] < x) continue;\n            for (auto& _e\
    \ : g[y]) {\n                if (x + _e.cost < dp[i][_e.to]) {\n             \
    \       dp[i][_e.to] = x + _e.cost;\n                    q.push({x + _e.cost,\
    \ _e.to});\n                    par[i][_e.to] = {1, _e.from};\n              \
    \  }\n            }\n        }\n    }\n    vector<int> res;\n    int c = -1;\n\
    \    T ans = numeric_limits<T>::max();\n    for (int i=0; i<g.size(); i++) {\n\
    \        if (dp.back()[i] < ans) {\n            ans = dp.back()[i];\n        \
    \    c = i;\n        }\n    }\n    if (c == -1) return res;\n    stack<pair<int,\
    \ int>> s;\n    s.push({(1<<v.size())-1, c});\n    while (!s.empty()) {\n    \
    \    auto [x, y] = s.top(); s.pop();\n        auto [X, Y] = par[x][y];\n     \
    \   if (X == -1) continue;\n        else if (X == 0) {\n            s.push({Y,\
    \ c});\n            s.push({x^Y, c});\n        } else if (X == 1) {\n        \
    \    s.push({x, Y});\n            res.push_back(id[y][Y]);\n        }\n    }\n\
    \    return res;\n}"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/minimumsteinertree.hpp
  requiredBy:
  - verify/yosupo-minimum_steiner_tree.cpp
  timestamp: '2025-05-08 04:55:27+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimumsteinertree.hpp
layout: document
redirect_from:
- /library/graph/minimumsteinertree.hpp
- /library/graph/minimumsteinertree.hpp.html
title: graph/minimumsteinertree.hpp
---
