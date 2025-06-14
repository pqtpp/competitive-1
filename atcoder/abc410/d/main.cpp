#include "template"
#include "dijkstra"


int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<int, true, true> g(n);
    g.read(m);
    vvi dp(n, vi(1024));
    dp[0][0] = 1;
    queue<pi> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [v, mask] = q.front(); q.pop();
        for (auto& e : g[v]) {
            int to = e.to, cost = e.cost;
            int new_mask = mask ^ cost;
            if (dp[to][new_mask]) continue;
            dp[to][new_mask] = 1;
            q.push({to, new_mask});
        }
    }
    rep(i, 1024) {
        if (dp[n-1][i]) {
            cout << i << nl;
            return;
        }
    }
    cout << -1 << nl;
}