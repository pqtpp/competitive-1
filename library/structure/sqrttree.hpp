#pragma once
#include <bits/stdc++.h>
using namespace std;

// S: 値型, F: 作用素型
// op: モノイド演算 (S x S -> S)
// e: 単位元 (S)
// mapping: 作用 (F x S x int -> S)
// composition: 作用素合成 (F x F -> F)
// id: 恒等写像 (F)

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S, int),
          F (*composition)(F, F),
          F (*id)()>
struct SqrtTree {
    struct Block {
        int l, r;
        vector<S> data;
        S sum;
        F lazy;
        bool pending;

        Block() = default;

        Block(const vector<S>& base, int l_, int r_)
            : l(l_), r(r_), data(base.begin() + l_, base.begin() + r_),
              sum(e()), lazy(id()), pending(false) {
            rebuild();
        }

        void apply(F f) {
            lazy = composition(f, lazy);
            pending = true;
        }

        void push() {
            if (!pending) return;
            for (int i = 0; i < r - l; ++i)
                data[i] = mapping(lazy, data[i], 1);
            lazy = id();
            pending = false;
            rebuild();
        }

        void rebuild() {
            sum = e();
            for (auto& x : data) sum = op(sum, x);
        }

        void update(int ql, int qr, F f) {
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

        S query(int ql, int qr) {
            if (qr <= l || r <= ql) return e();
            if (ql <= l && r <= qr) return pending ? mapping(lazy, sum, r - l) : sum;
            push();
            S res = e();
            for (int i = max(l, ql); i < min(r, qr); ++i)
                res = op(res, data[i - l]);
            return res;
        }
    };

    int n, bsize;
    vector<Block> blocks;

    SqrtTree() = default;

    SqrtTree(const vector<S>& base) {
        n = base.size();
        bsize = sqrt(n) + 1;
        for (int i = 0; i < n; i += bsize)
            blocks.emplace_back(base, i, min(n, i + bsize));
    }

    void update(int l, int r, F f) {
        for (auto& b : blocks)
            b.update(l, r, f);
    }

    S query(int l, int r) {
        S res = e();
        for (auto& b : blocks)
            res = op(res, b.query(l, r));
        return res;
    }
};
