#define PROBLEM "https://judge.yosupo.jp/problem/minimum_steiner_tree"
#include "template"
#include "minimumsteinertree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<ll, false, true> g(n);
    g.read(m, 0);
    int k; cin >> k;
    vi v(k); cin >> v;
    cout << minimumsteinertree(g, v) << nl;
}