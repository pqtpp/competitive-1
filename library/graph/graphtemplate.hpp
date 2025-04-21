#pragma once
#include<bits/stdc++.h>
using namespace std;
template<class T = int>
struct edge {
    int from, to;
    T cost;
    int id;
};
template<class T = int>
using edges = vector<edge<T>>;
template <class T = int, bool directed = false, bool weighted = false>
struct graph {
    bool isdirected, isweighted;
    edges<T> _edges;
    vector<edges<T>> data;
    T sumcost;
    graph(int n) : isdirected(directed), isweighted(weighted), data(n), sumcost(T{}) {}
    void add_edge(int from, int to, T cost = 1, int id = -1) {
        if (id == -1) id = _edges.size();
        data[from].push_back(edge<T>(from, to, cost, id));
        _edges.push_back(edge<T>(from, to, cost, id));
        if (!isdirected) {
            data[to].push_back(edge<T>(to, from, cost, id));
        }
        sumcost += cost;
    }
    void add_edge(edge<T> _e) {
        add_edge(_e.from, _e.to, _e.cost, _e.id);
    }
    void read(int m, int indexed = 1) {
        for (int i=0; i<m; i++) {
            int from, to;
            T cost = 1;
            cin >> from >> to;
            if (isweighted) cin >> cost;
            add_edge(from - indexed, to - indexed, cost);
        }
    }
    int size() {
        return data.size();
    }
    edges<T> operator[](int k) {
        return data[k];
    }
    template <class F>
    void dfs(int v, F f) {
        vector<bool> visited(size()); visited[v] = true;
        stack<int> s; s.push(v);
        if (!f(v, -1)) return;
        while (!s.empty()) {
            int v = s.top(); s.pop();
            for (auto _e : data[v]) {
                if (!visited[e.to]) {
                    visited[e.to] = true;
                    if (f(_e.to, _e.from)) {
                        s.push(e.to);
                    }
                }
            }
        }
    }
};