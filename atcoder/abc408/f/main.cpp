#include "template"
#include "generalsegtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, d, r; cin >> n >> d >> r;
    rangemax_ll seg(n);
    vi h(n), invh(n);
    rep(i, n) {
        cin >> h[i]; h[i]--;
        invh[h[i]] = i;
    }
    vll dp(n);
    rep(i, n) {
        if (d <= i) {
            ll I = invh[i-d];
            seg.set(I, dp[i-d]);
        }
        ll p = invh[i];
        ll L = max(0LL, p-r);
        ll R = min(n-1LL, p+r);
        ll ans = 0;
        if (d <= i) {
            ans = max(0LL, seg.prod(L, R+1));
        }
        dp[i] = ans + 1;
    }
    cout << Max(dp)-1 << nl;
}