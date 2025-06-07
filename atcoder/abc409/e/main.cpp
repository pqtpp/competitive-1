#include "template"
#include "graphtemplate"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    graph<ll, false, true> g(n);
    vll x(n); cin >> x;
    g.read(n-1, 1);
    ll ans = 0;
    auto dfs = [&](auto&& self, int v, int p) -> ll {
        ll sum = x[v];
        for (auto& e : g[v]) {
            if (e.to == p) continue;
            ll t = self(self, e.to, v);
            ans += abs(t) * e.cost;
            sum += t;
        }
        return sum;
    };
    dfs(dfs, 0, -1);
    cout << ans << nl;
}