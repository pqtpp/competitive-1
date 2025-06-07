#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    ll l=0, r=inf;
    while (1 < r - l) {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        rep(i, n) {
            if (mid <= a[i]) cnt++;
        }
        if (mid <= cnt) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << nl;
}