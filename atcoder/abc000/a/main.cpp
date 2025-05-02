#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<ll, false, true> g(n);
    g.read(m, 1);
    set<int> used;
    rep(i, n) {
        pqg<pll> q; q.push({0, i});
        vll d(n, INF); d[i] = 0;
        while (!q.empty()) {
            auto [x, y] = q.top(); q.pop();
            if (d[y] < x) continue;
            range(e, g[y]) {
                    if (chmin(d[e.to], d[e.from]+e.cost)) {
                    used.insert(e.id);
                    q.push({d[e.to], e.to});
                }
            }
        }
    }
    cout << m - used.size() << nl;
}