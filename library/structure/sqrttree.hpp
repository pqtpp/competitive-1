#pragma once
#include <bits/stdc++.h>
using namespace std;
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
struct sqrttree {
    struct block {
        int l, r;
        vector<S> data;
        S sum;
        F lazy;
        bool flag;
        block() = default;
        block(vector<S>& base, int l_, int r_) : l(l_), r(r_), data(base.begin() + l_, base.begin() + r_), sum(e()), lazy(id()), flag(false) {
            rebuild();
        }
        void apply(F f) {
            lazy = composition(f, lazy);
            flag = true;
        }
        void push() {
            if (!flag) return;
            for (int i=0; i<r-l; i++) data[i] = mapping(lazy, data[i], 1);
            lazy = id();
            flag = false;
            rebuild();
        }
        void rebuild() {
            sum = e();
            for (auto& x : data) sum = op(sum, x);
        }
        void apply(int ql, int qr, F f) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                apply(f);
                return;
            }
            push();
            for (int i = max(l, ql); i < min(r, qr); ++i)
                data[i - l] = mapping(f, data[i - l], 1);
            rebuild();
        }
        S prod(int ql, int qr) {
            if (qr<=l || r<=ql) return e();
            if (ql<=l && r<=qr) return (flag ? mapping(lazy, sum, r - l) : sum);
            push();
            S res = e();
            for (int i=max(l, ql); i<min(r, qr); i++) res = op(res, data[i - l]);
            return res;
        }
    };
    int n, bsize;
    vector<block> blocks;
    sqrttree() = default;
    sqrttree(vector<S>& base) {
        n = base.size();
        bsize = sqrt(n) + 1;
        for (int i=0; i<n; i+=bsize) {
            blocks.push_back(block{base, i, min(n, i + bsize)});
        }
    }
    void apply(int l, int r, F f) {
        for (auto& b : blocks) b.apply(l, r, f);
    }
    S prod(int l, int r) {
        S res = e();
        for (auto& b : blocks)
            res = op(res, b.prod(l, r));
        return res;
    }
};
