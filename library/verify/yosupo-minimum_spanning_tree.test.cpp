#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include "template"
#include "kruskal"
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<ll> g(n, false, true);
    g.read(m, 0);
    graph<ll> g2 = kruskal(g);
    cout << g2.sumcost << nl;
    rep(i, n-1) {
        cout << g2.getedge(i).id << sp;
    }
    cout << nl;
}