#pragma once
#include "graphtemplate"
#include "UnionFind"
#include<bits/stdc++.h>
using namespace std;
template<class T=int>
undirectedgraph<T> kruskal(undirectedgraph<T>& g) {
    undirectedgraph<T> re(g.size(), g._weighted);
    edges<T> _edges = g._edges;
    sort(all(_edges), [](edge<T> e1, edge<T> e2) { return e1.cost < e2.cost;} );
    UnionFind uf(g.size());
    for (auto& es : _edges) {
        if (uf.merge(es.from, es.to)) {
            re.add_edge(es);
        }
    }
    return re;
}