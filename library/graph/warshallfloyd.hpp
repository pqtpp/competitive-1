#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
template <class T>
vector<vector<T>> warshallfloyd(vector<vector<T>>& g) {
    int n = g.size();
    vector<vector<T>> d = g;
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (d[i][k] < numeric_limits<T>::max()/2 && d[k][j] < numeric_limits<T>::max()/2) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    return d;
}
template<class T = int, bool directed = false, bool weighted = true>
vector<vector<T>> warshallfloyd(graph<T, directed, weighted>& g) {
    int n = g.size();
    vector<vector<T>> d(n, vector<T>(n, numeric_limits<T>::max()));
    for (int i=0; i<n; i++) d[i][i] = T{};
    for (int i=0; i<n; i++) {
        for (auto& _e : g[i]) {
            d[i][_e.to] = _e.cost;
        }
    }
    return warshallfloyd(d);
}