#pragma 
#include "graphtemplate"
#include <bits/stdc++.h>
using namespace std;
template <class T=long long, bool directed=false, bool weighted=false>
struct treedp {
    graph<T, directed, weighted> g;
    treedp(graph<T, directed, weighted> _g) : {
        swap(g, _g);
    }

};