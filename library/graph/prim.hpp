#pragma once
#include "graphtemplate"
#include<bits/stdc++.h>
using namespace std;
template<class T>
graph<T> prim(graph<T>& g) {
    graph<T> re(g.size(), false, true);
    vector<T> _d(g.size(), numeric_limits<T>::max()); _d[0] = T{};
    vector<bool> _visited(g.size()); _visited[0] = 1;
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> _pq;
    _pq.push({T{}, -1});
    while (!_pq.empty()) {
        auto [_x, _id] = _pq.top(); _pq.pop();
        int _to;
        if (_id != -1) {
            _to = g.getedge(_id).to;
            if (_visited[_to]) continue;
            _visited[_to] = 1;
            if (_d[_to] < _x) continue;
            else re.add_edge(g.getedge(_id/2));
        } else {
            _to = 0;
        }
        range(i, g[_to]) {
            T _y = _x + i.cost;
            if (_y < _d[i.to]) {
                _d[i.to] = _y;
                _pq.push({_y, i.id});
            }
        }
    }
    return re;
}