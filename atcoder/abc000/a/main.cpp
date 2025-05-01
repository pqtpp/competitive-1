#include "template"
#include "graphtemplate"
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
        pqg<pair<ll, pll>> q; q.push({0, {i, -1}});
        vll d(n, INF); d[i] = 0;
        while (!q.empty()) {
            auto [x, t] = q.top(); q.pop(); auto [y, z] = t;
            if (d[y] < x) continue;
            used.insert(z);
            range(e, g[y]) {
                if (d[e.from]+e.cost <= d[e.to]) {
                    q.push({d[e.to], {e.to, e.id}});
                }
            }
        }
    }
    cout << m - used.size() + 1 << nl;
}