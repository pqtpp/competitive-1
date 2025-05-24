#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    int n = s.size();
    vi a(n); rep(i, n) a[i] = s[i] - '0';
    ll ans = n + a.back();
    rep1(i, n-1) {
        ans += (10 + a[i-1] - a[i]) % 10;
    }
    cout << ans << nl;
}