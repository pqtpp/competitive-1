#include "template"

int main() {
    IO();
    int T = 1;
    while (T--) solve();
}

void solve() {
    ll n, t, m, k; cin >> n >> t >> m >> k;
    if (t * m < k) {
        cout << 0 << nl;
        return;
    }
    vi r;
    rep1(i, m) if (m % i == 0 && (ll)i * n >= m) r.pb(i);
    vec<ld> dp(k+1), ndp;
    rep(i, k+1) dp[i] = (k<=i ? 1.0L : 0.0L);
    rep(round, t) {
        ndp.assign(k+1, 0.0L);
        rep(j, k+1) {
            ld best = 0;
            range(rr, r) {
                ld alpha = (ld)m / ((ld)rr * (ld)n);
                alpha = min(alpha, 1.0L);
                int nj = min<ll>(k, j + rr);
                best = max(best, (1 - alpha) * dp[j] + alpha * dp[nj]);
            }
            ndp[j] = best;
        }
        dp.swap(ndp);
    }
    cout << dp[0] << nl;
}
