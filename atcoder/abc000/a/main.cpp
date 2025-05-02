#include "template"
#include "warshallfloyd"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    graph<ll, false, true> g(n);
    g.read(m, 1);
    vvll d = warshallfloyd(g);
    int cnt = 0;
    range(e, g._edges) {
        int ans = 0;
        int x=e.from, y=e.to, z=e.cost;
        rep(i, n) rep(j, n) {
            if (d[x][i]+z+d[j][y] == d[x][y]) {
                ans = 1;
            }
        }
        cnt += ans;
    }
    cout << m - cnt << nl;
}