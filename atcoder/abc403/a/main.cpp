#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    ll ans = 0;
    for (int i=0; i<n; i+=2) {
        ans += a[i];
    }
    cout << ans << nl;
}