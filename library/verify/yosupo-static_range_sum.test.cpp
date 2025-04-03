#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "template"
#include "segtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;
    auto op = [](ll a, ll b) { return a + b; };
    segtree<ll, op> seg(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << seg.prod(l, r) << nl;
    }
}