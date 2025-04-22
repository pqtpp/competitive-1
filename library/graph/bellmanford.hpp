#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
// ベルマンフォード法で単一始点最短経路を求める 負閉路がある場合は d[from] < 0
template <typename T, bool directed = true, bool weighted = true>
vector<T> bellmanford(graph<T, directed, weighted>& g, int from = 0) {
    ;
}