#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vll cnt(n * 3);
    ll s = (ll)m * (m - 1) / 2;
    rep(i, m) {
        ll a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        if (n+3-a <= b) {
            cnt[a+b-n]++;
        } else {
            cnt[a+b]++;
        }
    }
    range(i, cnt) s -= (ll)i * (i - 1) / 2;
    cout << s << nl;
}