#pragma once
#include<bits/stdc++.h>
using namespace std;
// 辺の構造体 edge(from, to, cost, id)
template<class T = int>
struct edge {
    int from, to;
    T cost;
    int id;
};
// 頂点の構造体 vector<edge<T>>
template<class T = int>
using edges = vector<edge<T>>;
// グラフの構造体 graph<T, directed, weighted> 
template <class T = int, bool directed = false, bool weighted = false>
struct graph {
    bool isdirected, isweighted;
    edges<T> _edges;
    vector<edges<T>> data;
    T sumcost;
    graph(int n) : isdirected(directed), isweighted(weighted), data(n), sumcost(T{}) {}
    // from から to へ辺を追加する
    void add_edge(int from, int to, T cost = 1, int id = -1) {
        if (id == -1) id = _edges.size();
        data[from].push_back(edge<T>(from, to, cost, id));
        _edges.push_back(edge<T>(from, to, cost, id));
        if (!isdirected) {
            data[to].push_back(edge<T>(to, from, cost, id));
        }
        sumcost += cost;
    }
    // 辺を追加する
    void add_edge(edge<T> _e) {
        add_edge(_e.from, _e.to, _e.cost, _e.id);
    }
    // 標準入力から辺を読み込む
    void read(int m, int indexed = 1) {
        for (int i=0; i<m; i++) {
            int from, to;
            T cost = 1;
            cin >> from >> to;
            if (isweighted) cin >> cost;
            add_edge(from - indexed, to - indexed, cost);
        }
    }
    // 頂点数を返す
    int size() {
        return data.size();
    }
    // 頂点を返す
    edges<T> operator[](int k) {
        return data[k];
    }
};