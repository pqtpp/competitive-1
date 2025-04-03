#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja"
#include "template"
#include "prim"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int> g(n, false, true);
    g.read(m, 1);
    cout << prim(g).sumcost << nl;
}