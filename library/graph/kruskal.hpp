#pragma once
#include "graphtemplate"
#include "UnionFind"
#include<bits/stdc++.h>
using namespace std;
template<class T=int>
graph<T> kruskal(graph<T>& g) {
    edges<T> _edges = g._edges;
    graph<T> re(g.size(), false, true);
    sort(_edges.begin(), _edges.end(), [](edge<T>& a, edge<T>& b) { return a.cost < b.cost; });
    UnionFind uf(g.size());
    for (auto& _e : _edges) {
        if (uf.merge(_e.from, _e.to)) {
            re.add_edge(_e);
        }
    }
    return re;
}