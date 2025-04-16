#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ll n; cin >> n;
    vi a(n); cin >> a;
    vvi b(n);
    rep(i, n) b[a[i]-1].pb(i);
    rep(i, n) b[i].pb(n);
    ll ans = 0;
    rep(i, n) {
        ll ans2 = n*(n+1)/2;
        ll p = -1;
        rep(j, b[i].size()) {
            ll k = b[i][j] - p;
            ans2 -= k*(k-1)/2;
            p = b[i][j];
        }
        ans += ans2;
    }
    cout << ans << nl;
}