#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpll a(n+1); a[0] = {-inf, 0};
    rep1(i, n) cin >> a[i].first;
    rep1(i, n) cin >> a[i].second;
    rep(i, n) a[i+1].second += a[i].second;
    vll b(n+1);
    rep(i, n+1) b[i] = a[i].first;
    ll q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r; l--;
        ll L = upper_bound(all(b), l) - b.begin();
        ll R = upper_bound(all(b), r) - b.begin();
        cout << a[R-1].second - a[L-1].second << nl;
    }
}