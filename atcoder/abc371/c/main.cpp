#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vvi g(n, vi(n)), h(n, vi(n));
    int mg; cin >> mg;
    rep(i, mg) {
        int x, y; cin >> x >> y; x--; y--;
        g[x][y] = g[y][x] = 1;
    }
    int mh; cin >> mh;
    rep(i, mh) {
        int x, y; cin >> x >> y; x--; y--;
        h[x][y] = h[y][x] = 1;
    }
    ll ans = INF;
    vvll c(n, vll(n));
    rep(i, n-1) rep(j, n-i-1) {
        ll x; cin >> x;
        c[i][i+j+1] = c[i+j+1][i] = x;
    }
    vi p(n); iota(all(p), 0);
    do {
        ll cnt = 0;
        rep(i, n) rep(j, n) {
            if (j <= i) continue;
            int i2 = p[i], j2 = p[j];
            cnt += (g[i][j] xor h[i2][j2]) * c[i2][j2];
        }
        chmin(ans, cnt);
    } while (nextp(p));
    cout << ans << nl;
}