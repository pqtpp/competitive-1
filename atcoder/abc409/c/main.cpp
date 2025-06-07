#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, l; cin >> n >> l;
    if (l%3) {
        cout << 0 << nl;
        return;
    }
    ll c = 0;
    map<ll, ll> freq;
    freq[0]++;
    rep(i, n-1) {
        ll x; cin >> x;
        c += x;
        c %= l;
        freq[c]++;
    }
    ll ans = 0;
    for (auto& [k, v] : freq) {
        ll x, y;
        if (!freq.count(k + l/3) || !freq.count(k + 2*l/3)) continue;
        x = freq[k+l/3];
        y = freq[k+2*l/3];
        ans += v * x * y;
    }
    cout << ans << nl;
}