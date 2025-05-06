#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
template <class T, bool directed = false, bool weighted = true>
T minimumsteinertree(graph<T, directed, weighted> &g, vector<int> &v) {
    vector<vector<T>> dp(1<<v.size(), vector<T>(g.size(), numeric_limits<T>::max()));
    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));
    for (auto& _e : g._edges) {
        d[_e.from][_e.to] = _e.cost;
    }
    for (int i=0; i<g.size(); i++) {
        d[i][i] = 0;
    }
    for (int i=0; i<v.size(); i++) {
        dp[1<<i][v[i]] = 0;
    }
    for (int i=0; i<(1<<v.size()); i++) {
        for (int j=i; 0<j; j=(j-1)&i) {
            for (int k=0; k<g.size(); k++) {
                if (dp[j][k] == numeric_limits<T>::max() || dp[i^j][k] == numeric_limits<T>::max()) continue;
                dp[i][k] = min(dp[i][k], dp[j][k] + dp[i^j][k]);
            }
        }
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
        for (int j=0; j<g.size(); j++) {
            if (dp[i][j] != numeric_limits<T>::max()) q.push({dp[i][j], j});
        }
        while (!q.empty()) {
            auto [x, y] = q.top(); q.pop();
            if (dp[i][y] < x) continue;
            for (auto& _e : g[y]) {
                if (x + _e.cost < dp[i][_e.to]) {
                    dp[i][_e.to] = x + _e.cost;
                    q.push({x + _e.cost, _e.to});
                }
            }
        }
    }
    T ans = numeric_limits<T>::max();
    for (int i=0; i<g.size(); i++) {
        ans = min(ans, dp.back()[i]);
    }
    return ans;
}