#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
// ベルマンフォード法で単一始点最短経路を求める 負閉路がある場合は d[from] < 0
template <typename T, bool directed = true, bool weighted = true>
vector<T> bellmanford(graph<T, directed, weighted>& g, int from = 0) {
    vector<T> d(g.size(), numeric_limits<T>::max());
    d[from] = 0;
    for (int i=0; i<g.size(); i++) {
        bool update = false;
        for (int j=0; j<g.size(); j++) {
            for (auto& e : g[j]) {
                if (d[j] != numeric_limits<T>::max() && d[e.to] > d[j] + e.cost) {
                    d[e.to] = d[j] + e.cost;
                    update = true;
                }
            }
        }
        if (!update) break;
    }
}