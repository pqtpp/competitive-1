#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
template <class T, bool directed = false, bool weighted = true>
vector<int> minimumsteinertree(graph<T, directed, weighted> &g, vector<int> &v) {
    vector<vector<T>> dp(1<<v.size(), vector<T>(g.size(), numeric_limits<T>::max()));
    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));
    vector<vector<int>> id(g.size(), vector<int>(g.size(), -1));
    vector<vector<pair<int, int>>> par(1<<v.size(), vector<pair<int, int>>(g.size(), {-1, -1}));
    for (auto& _e : g._edges) {
        d[_e.from][_e.to] = _e.cost;
        id[_e.from][_e.to] = _e.id;
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
                if (dp[i][k] == dp[j][k] + dp[i^j][k]) {
                    dp[i][k] = dp[j][k] + dp[i^j][k];
                    par[i][k] = {0, j};
                }
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
                    par[i][_e.to] = {1, y};
                }
            }
        }
    }
    vector<int> res;
    auto restore = [&](auto&& self, int S, int u) -> void {
        auto [x, from] = par[S][u];
        if (x == 0) {
            int S1 = from;
            int S2 = S ^ S1;
            self(self, S1, u);
            self(self, S2, u);
        } else if (x == 1) {
            if (id[from][u] != -1) res.push_back(id[from][u]);
            self(self, S, from);
        }
    };
    T ans = numeric_limits<T>::max();
    int c = -1;
    for (int i=0; i<g.size(); i++) {
        if (dp[(1<<v.size())-1][i] < ans) {
            ans = dp[(1<<v.size())-1][i];
            c = i;
        }
    }
    restore(restore, (1<<v.size())-1, c);
    return res;
}