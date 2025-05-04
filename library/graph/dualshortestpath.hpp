#pragma once
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
// 最短経路問題の双対（牛ゲー）を解く
template<class T>
struct dualshortestpath {
    graph<T, true, true> g;
    dualshortestpath(int n) : g(n) {}
    // 辺を追加する
    void add_edge(int from, int to, T cost = 1, int id = -1) {
        g.add_edge(from, to, cost, id);
    }
    // 辺を追加する
    void add_edge(edge<T> _e) {
        g.add_edge(_e);
    }
    // 
};