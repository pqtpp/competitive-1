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
    g.read(m);
    ll X = 1LL<<30; X--;
    per(i, 30) {
        vi visited(n);
        int Y = X & (~(1<<i));
        auto dfs = [&](auto&& self, int u) -> void{
            visited[u] = 1;
            range(e, g[u]) {
                ll v = e.to, w = e.cost;
                if(!visited[v] && ((w & (~Y)) == 0)){
                    self(self, v);
                }
            }
        };
        dfs(dfs, 0);
        if (visited.back()) X = Y;
    }
    cout << X << nl;
}