#pragma once
#include<bits/stdc++.h>
using namespace std;
struct Mo {
    int n;
    vector<pair<int, int>> queries;
    explicit Mo(int n) : n(n) {}
    void add(int l, int r) {
        queries.push_back({l, r});
    }
    long long hilbert_order(int x, int y, int p=20, int rotate = 0) {
        long long d = 0;
        for (int s = 1 << (p - 1); s; s >>= 1) {
            int rx = (x & s) > 0;
            int ry = (y & s) > 0;
            int r = (rx << 1) | ry;
            r = (r + rotate) & 3;
            d = (d << 2) | r;
            static const int rotate_delta[4] = {3, 0, 0, 1};
            rotate = (rotate + rotate_delta[r]) & 3;
        }
        return d;
    }
    template< typename AL, typename AR, typename EL, typename ER, typename O >
    void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
        int q = (int) queries.size();
        vector< int > ord(q);
        iota(begin(ord), end(ord), 0);
        vector< long long > hs(q);
        for (int i = 0; i < q; i++) {
            hs[i] = hilbert_order(queries[i].first, queries[i].second);
        }
        sort(begin(ord), end(ord), [&](int a, int b) {
            return hs[a] < hs[b];
        });
        int l = 0, r = 0;
        for(auto idx : ord) {
            while(l > queries[idx].first) add_left(--l);
            while(r < queries[idx].second) add_right(r++);
            while(l < queries[idx].first) erase_left(l++);
            while(r > queries[idx].second) erase_right(--r);
            out(idx);
        }
    }
    template< typename A, typename E, typename O >
    void build(const A &add, const E &erase, const O &out) {
        build(add, add, erase, erase, out);
    }
};
