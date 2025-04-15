#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
template <class T>
vector<T> dijkstra(directedgraph<T>& g, int from=0) {
    vector<T> dist(g.size(), numeric_limits<T>::max()); dist[from] = T{};
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    q.push({T{}, from});
    while (!q.empty()) {
        auto [t, x] = q.top(); q.pop();
        for (auto& es : g[x]) {
            int y = es.to;
            if (dist[x] + es.cost < dist[y]) {
                dist[y] = dist[x] + es.cost;
                q.push({dist[y], y});
            }
        }
    }
    return dist;
}
template <class T>
vector<T> dijkstra(undirectedgraph<T>& g, int from=0) {
    vector<T> dist(g.size(), numeric_limits<T>::max()); dist[from] = T{};
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
    q.push({T{}, from});
    while (!q.empty()) {
        auto [t, x] = q.top(); q.pop();
        for (auto& es : g[x]) {
            int y = es.to;
            if (dist[x] + es.cost < dist[y]) {
                dist[y] = dist[x] + es.cost;
                q.push({dist[y], y});
            }
        }
    }
    return dist;
}
template <class T>
T dijkstra(directedgraph<T>& g, int from, int to) {
    return dijktra(g, from)[to];
}
template <class T>
T dijkstra(undirectedgraph<T>& g, int from, int to) {
    return dijktra(g, from)[to];
}