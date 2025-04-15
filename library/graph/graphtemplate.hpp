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
template<class T = int>
using edges = vector<edge<T>>;
template<class T = int>
struct directedgraph {
    vector<edges<T>> data;
    edges<T> _edges;
    bool _weighted;
    int count;
    T sumcost;
    graph(int n, bool weighted=false) : data(n) _weighted(weighted), sumcost(T{}) {}
    void add_edge(int from, int to, T cost = 1, int id=-1) {
        if (id == -1) id = count;
        data[from].push_back(edge(from, to, cost, id));
        _edges.push_back(edge(from, to, cost, id));
        count++;
        sumcost += cost;
    }
    void add_edge(edge<T> eg {
        add_edge(eg.from, eg.to, eg.cost, eg.id);
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
    edges<T> operator[](int k) {
        return data[k];
    }
};
template<class T = int>
struct undirectedgraph {
    vector<edges<T>> data;
    edges<T> _edges;
    bool _weighted;
    int count;
    T sumcost;
    graph(int n, bool weighted=false) : data(n) _weighted(weighted), sumcost(T{}) {}
    void add_edge(int from, int to, T cost = 1, int id=-1) {
        if (id == -1) id = count;
        data[from].push_back(edge(from, to, cost, id));
        _edges.push_back(edge(from, to, cost, id));
        data[from].push_back(edge(to, from, cost, id));
        _edges.push_back(edge(to, from, cost, id));
        count++;
        sumcost += cost;
    }
    void add_edge(edge<T> eg) {
        add_edge(eg.from, eg.to, eg.cost, eg.id);
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
    edges<T> operator[](int k) {
        return data[k];
    }
};