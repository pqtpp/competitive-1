#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
template<class T = int, bool directed = false, bool weighted = true>
vector<T> dijkstra(graph<T, directed, weighted>& g, int from = 0) {
    vector<T> dist(g.size(), numeric_limits<T>::max()); dist[from] = T{};
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    q.push({T{}, from});
    while (!q.empty()) {
        auto [t, x] = q.top(); q.pop();
        if (dist[x] < t) continue;
        for (auto& _e : g[x]) {
            int y = _e.to;
            if (dist[x] + _e.cost < dist[y]) {
                dist[y] = dist[x] + _e.cost;
                q.push({dist[y], y});
            }
        }
    }
    return dist;
}
template<class T = int, bool directed = false, bool weighted = true>
T dijkstra(graph<T, directed, weighted>& g, int from, int to) {
    return dijkstra(g, from)[to];
}