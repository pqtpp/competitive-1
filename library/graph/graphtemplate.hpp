#pragma once
#include<bits/stdc++.h>
using namespace std;
template<class T = int>
struct edge {
    int from, to;
    T cost;
    int id;
    edge(int _from, int _to, T _cost = 1, int _id = -1) : from(_from), to(_to), cost(_cost), id(_id) {}
};
template<class T>
using edges = vector<edge<T>>;
template<class T = int>
struct graph {
    vector<vector<edge<T>>> data;
    vector<edge<T>> _edges;
    bool _directed, _weighted;
    int count;
    T sumcost;
    graph(int n, bool directed=false, bool weighted=false) : data(n), _directed(directed), _weighted(weighted), sumcost(T{}) {}
    void add_edge(int from, int to, T cost = 1, int id=-1) {
        if (id == -1) id = count;
        data[from].push_back(edge(from, to, cost, id));
        _edges.push_back(edge(from, to, cost, id));
        if (!_directed) {
            data[to].push_back(edge(to, from, cost, id));
            _edges.push_back(edge(to, from, cost, id));
        }
        count++;
        sumcost += cost;
    }
    void add_edge(edge<T> _e) {
        add_edge(_e.from, _e.to, _e.cost, _e.id);
    }
    void read(int m, int indexed = 1) {
        for (int i=0; i<m; i++) {
            int from, to, cost=1;
            cin >> from >> to;
            if (_weighted) cin >> cost;
            add_edge(from - indexed, to - indexed, cost);
        }
    }
    int size() {
        return data.size();
    }
    vector<edge<T>> operator[](int k) {
        return data[k];
    }
};