#include "template"
#include "modint"
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vpi e(m);
    rep(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        e[i] = {x, (y+n-1)%n};
    }
    vec<mint> dp(n); dp[0] += 1;
    rep(i, k) {
        vpi q;
        rep(j, m) {
            auto [x, y] = e[j];
            q.pb({((y-i)%n+n)%n, dp[((x-i)%n+n)%n].val});
        }
        rep(j, m) {
            auto [x, y] = q[j];
            dp[x] += y;
        }
    }
    mint ans = 0;
    rep(i, n) ans += dp[i];
    cout << ans << nl;
}