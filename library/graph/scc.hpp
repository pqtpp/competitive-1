#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
// グラフを強連結成分分解し、トポロジカル順に並べたものを返す O(V + E)
template<class T = int, bool directed = true, bool weighted = false>
vector<vector<int>> scc(graph<T, directed, weighted>& g) {
    int n = g.size();
    vector<int> low(n), num(n, -1), stack;
    vector<bool> onStack(n);
    vector<vector<int>> re;
    auto dfs = [&](auto& self, int x) -> void {
        low[x] = num[x] = stack.size();
        stack.push_back(x);
        onStack[x] = true;
        for (auto& _e : g[x]) {
            int y = _e.to;
            if (num[y] == -1) {
                self(self, y);
                low[x] = min(low[x], low[y]);
            } else if (onStack[y]) {
                low[x] = min(low[x], num[y]);
            }
        }
        if (low[x] == num[x]) {
            vector<int> component;
            while (true) {
                int y = stack.back(); stack.pop_back(); onStack[y] = false;
                component.push_back(y);
                if (y == x) break;
            }
            re.push_back(component);
        }
    };
    for (int i=0; i<n; i++) if (num[i] == -1) dfs(dfs, i);
    reverse(re.begin(), re.end());
    return re;
}