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
    \ {\n        if (id == -1) id = _edges.size() / (2 - directed);\n        data[from].push_back(edge<T>(from,\
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
    \ k) {\n        return data[k];\n    }\n};\n#line 4 \"graph/minimunsteinertree.hpp\"\
    \nusing namespace std;\ntemplate <class T, bool directed = false, bool weighted\
    \ = false>\nT minimumsteinertree(graph<T, directed, weighted> &g, vector<int>\
    \ &v) {\n    vector<vector<T>> dp(1<<v.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    for (auto& _e : g._edges) {\n        d[_e.from][_e.to] = _e.cost;\n    }\n\
    \    for (int i=0; i<g.size(); i++) {\n        d[i][i] = 0;\n    }\n    for (int\
    \ i=0; i<v.size(); i++) {\n        dp[1<<i][i] = 0;\n    }\n    for (int i=0;\
    \ i<(1<<v.size()); i++) {\n        for (int j=i; 0<j; j=(j-1)&i) {\n         \
    \   for (int k=0; k<g.size(); k++) {\n                if (dp[i][k] == numeric_limits<T>::max())\
    \ continue;\n                dp[i][k] = min(dp[i][k], dp[j][k] + dp[i^j][k]);\n\
    \            }\n        }\n        priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> q;\n        for (int j=0; j<g.size(); j++) {\n\
    \            q.push({dp[i][j], j});\n        }\n        while (!q.empty()) {\n\
    \            auto [x, y] = q.top(); q.pop();\n            if (dp[i][y] < x) continue;\n\
    \            for (auto& _e : g._edges) {\n                if (x + _e.cost < dp[i][_e.to])\
    \ {\n                    dp[i][_e.to] = x + _e.cost;\n                    q.push({x\
    \ + _e.cost, _e.to});\n                }\n            }\n        }\n    }\n  \
    \  T ans = numeric_limits<T>::max();\n    for (int i=0; i<g.size(); i++) {\n \
    \       ans = min(ans, dp.back()[i]);\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include \"graphtemplate\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntemplate <class T, bool directed = false, bool weighted = false>\n\
    T minimumsteinertree(graph<T, directed, weighted> &g, vector<int> &v) {\n    vector<vector<T>>\
    \ dp(1<<v.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n    vector<vector<T>>\
    \ d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n    for (auto&\
    \ _e : g._edges) {\n        d[_e.from][_e.to] = _e.cost;\n    }\n    for (int\
    \ i=0; i<g.size(); i++) {\n        d[i][i] = 0;\n    }\n    for (int i=0; i<v.size();\
    \ i++) {\n        dp[1<<i][i] = 0;\n    }\n    for (int i=0; i<(1<<v.size());\
    \ i++) {\n        for (int j=i; 0<j; j=(j-1)&i) {\n            for (int k=0; k<g.size();\
    \ k++) {\n                if (dp[i][k] == numeric_limits<T>::max()) continue;\n\
    \                dp[i][k] = min(dp[i][k], dp[j][k] + dp[i^j][k]);\n          \
    \  }\n        }\n        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> q;\n        for (int j=0; j<g.size(); j++) {\n            q.push({dp[i][j],\
    \ j});\n        }\n        while (!q.empty()) {\n            auto [x, y] = q.top();\
    \ q.pop();\n            if (dp[i][y] < x) continue;\n            for (auto& _e\
    \ : g._edges) {\n                if (x + _e.cost < dp[i][_e.to]) {\n         \
    \           dp[i][_e.to] = x + _e.cost;\n                    q.push({x + _e.cost,\
    \ _e.to});\n                }\n            }\n        }\n    }\n    T ans = numeric_limits<T>::max();\n\
    \    for (int i=0; i<g.size(); i++) {\n        ans = min(ans, dp.back()[i]);\n\
    \    }\n    return ans;\n}"
  dependsOn:
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: graph/minimunsteinertree.hpp
  requiredBy: []
  timestamp: '2025-05-06 08:14:53+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/minimunsteinertree.hpp
layout: document
redirect_from:
- /library/graph/minimunsteinertree.hpp
- /library/graph/minimunsteinertree.hpp.html
title: graph/minimunsteinertree.hpp
---
