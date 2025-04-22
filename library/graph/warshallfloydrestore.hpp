#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> warshallfloydrestore_d;
vector<vector<int>> warshallfloydrestore_p;
// ワーシャルフロイド法で求めた最短経路の復元 O(n^3)
template<class T = int, bool directed = false, bool weighted = true>
vector<int> warshallfloydrestorebuild(graph<T, directed, weighted>& g, int from, int to) {
    warshallfloydrestore_d = vector<vector<int>>(g.size(), vector<int>(g.size(), numeric_limits<int>::max()));
    warshallfloydrestore_p = vector<vector<int>>(g.size(), vector<int>(g.size(), -1));
    for (int i=0; i<g.size(); i++) {
        warshallfloydrestore_d[i][i] = 0;
        for (auto& _e : g[i]) {
            warshallfloydrestore_d[i][_e.to] = _e.cost;
            warshallfloydrestore_p[i][_e.to] = i;
        }
    }
    for (int k=0; k<g.size(); k++) {
        for (int i=0; i<g.size(); i++) {
            for (int j=0; j<g.size(); j++) {
                if (warshallfloydrestore_d[i][k] < numeric_limits<int>::max()/2 && warshallfloydrestore_d[k][j] < numeric_limits<int>::max()/2) {
                    if (warshallfloydrestore_d[i][j] > warshallfloydrestore_d[i][k] + warshallfloydrestore_d[k][j]) {
                        warshallfloydrestore_d[i][j] = warshallfloydrestore_d[i][k] + warshallfloydrestore_d[k][j];
                        warshallfloydrestore_p[i][j] = k;
                    }
                }
            }
        }
    }
    return warshallfloydrestore_d[from][to];
}
// ワーシャルフロイド法で求めた最短経路の復元 O(n)
vector<int> warshallfloydrestore(int from, int to) {
    vector<int> path;
    if (warshallfloydrestore_d[from][to] == numeric_limits<int>::max()) return path;
    for (int i=to; i!=-1; i=warshallfloydrestore_p[from][i]) path.push_back(i);
    reverse(path.begin(), path.end());
    return path;
}