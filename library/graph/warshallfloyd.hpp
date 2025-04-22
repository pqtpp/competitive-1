#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
// グラフの全点間最短経路を求める O(V^3)
template <class T>
vector<vector<T>> warshallfloyd(vector<vector<T>>& g) {
    vector<vector<T>> d = g;
    for (int k=0; k<g.size(); k++) {
        for (int i=0; i<g.size(); i++) {
            for (int j=0; j<g.size(); j++) {
                if (d[i][k] < numeric_limits<T>::max()/2 && d[k][j] < numeric_limits<T>::max()/2) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    return d;
}
// グラフの全点間最短経路を求める O(V^3)
template<class T = int, bool directed = false, bool weighted = true>
vector<vector<T>> warshallfloyd(graph<T, directed, weighted>& g) {
    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));
    for (int i=0; i<g.size(); i++) {
        d[i][i] = T{};
        for (auto& _e : g[i]) {
            d[i][_e.to] = _e.cost;
        }
    }
    return warshallfloyd(d);
}