#pragma once
#include <bits/stdc++.h>
using namespace std;
template <class S, auto op, auto e, class F, auto mapping>
struct sqrttree {
    struct block {
        int l, r;
        vector<S> data;
        S sum;
        block() = default;
        block(vector<S>& base, int l_, int r_) : l(l_), r(r_), data(base.begin() + l_, base.begin() + r_) {
            rebuild();
        }
        void rebuild() {
            sum = e();
            for (auto& x : data) sum = op(sum, x);
        }
        void apply(int i, F f) {
            data[i - l] = mapping(f, data[i - l]);
            sum = e();
            for (auto& x : data) sum = op(sum, x);
        }
        S prod(int ql, int qr) {
            if (qr <= l || r <= ql) return e();
            if (ql <= l && r <= qr) return sum;
            S res = e();
            for (int i = max(l, ql); i < min(r, qr); ++i) {
                res = op(res, data[i - l]);
            }
            return res;
        }
    };
    int n, bsize;
    vector<block> blocks;
    sqrttree() = default;
    sqrttree(vector<S>& base) {
        n = base.size();
        bsize = sqrt(n) + 1;
        for (int i = 0; i < n; i += bsize) {
            blocks.push_back(block{base, i, min(n, i + bsize)});
        }
    }
    void apply(int i, F f) {
        assert(0 <= i && i < n);
        for (auto& b : blocks) {
            if (b.l <= i && i < b.r) {
                b.apply(i, f);
                return;
            }
        }
    }
    S operator[](int i) {
        assert(0 <= i && i < n);
        for (auto& b : blocks) {
            if (b.l <= i && i < b.r) {
                return b.data[i - b.l];
            }
        }
        assert(false);
    }
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        S res = e();
        for (auto& b : blocks) {
            res = op(res, b.prod(l, r));
        }
        return res;
    }
};
