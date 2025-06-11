#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, x; cin >> n >> x;
    vec<ld> a; cin >> a;
    rep(i, n) a[i] /= 100;
    vec<vec<ld>> dp(n+1, vec<ld>(n+1));
    dp[0][0] = 1.;
    rep(i, n) rep(j, n) {
        dp[i+1][j] += dp[i][j] * (1 - a[i]);
        dp[i+1][j+1] += dp[i][j] * a[i];
    }
    vec<ld> dp2(n+x);
    per(i, x) {
        ld y = 1;
        rep1(j, n) {
            y += dp2[i+j] * dp.back()[j];
        }
        y /= 1 - dp.back()[0];
    }
    cout << dp2[0] << nl;
}