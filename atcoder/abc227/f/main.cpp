#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w, k; cin >> h >> w >> k;
    vvll a(h, vll(w)); cin >> a;
    ll ans = INF;
    rep(I, h) rep(J, w) {
        ll x = a[I][J];
        vvvll dp(h, vvll(w, vll(k+1, INF)));
        if (x <= a[0][0]) dp[0][0][1] = a[0][0];
        else dp[0][0][0] = 0;
        rep(i, h) rep(j, w) rep(t, k+1) {
            ll y = a[i][j];
            if (x <= y && 0 < t) {
                if (0 < i) chmin(dp[i][j][t], dp[i-1][j][t-1]+a[i][j]);
                if (0 < j) chmin(dp[i][j][t], dp[i][j-1][t-1]+a[i][j]);
            }
            if (y <= x) {
                if (0 < i) chmin(dp[i][j][t], dp[i-1][j][t]);
                if (0 < j) chmin(dp[i][j][t], dp[i][j-1][t]);
            }
        }
        chmin(ans, dp[h-1][w-1][k]);
    }
    cout << ans << nl;
}