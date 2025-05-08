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
                if (dp[j][k] + dp[i^j][k] < dp[i][k]) {
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
                    par[i][_e.to] = {1, _e.id};
                }
            }
        }
    }
    vector<int> res;
    if (c == -1) return res;
    T ans = numeric_limits<T>::max();
    for (int i=0; i<g.size(); i++) {
        if (dp.back()[i] < ans) {
            ans = dp.back()[i];
            c = i;
        }
    }
    stack<pair<int, int>> s;
    s.push({(1<<v.size())-1, c});
    while (!s.empty()) {
        auto [x, y] = s.top();  s.pop();
        auto [X, Y] = par[x][y];
        if (X == -1) continue;
        if (X == 0) {
            s.push({Y, c});
            s.push({x^Y, c});
        } else {
            res.push_back(id[y][Y]);
        }
    }
    return res;
}