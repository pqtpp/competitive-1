#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}


void solve() {
    int m; cin >> m;
    vi ans;
    vll pw(21); pw[0] = 1;
    rep(i, 20) pw[i+1] = pw[i] * 3;
    while (m) {
        int t = 20;
        while (m < pw[t]) t--;
        m -= pw[t];
        ans.pb(t);
    }
    Sort(ans);
    cout << ans.size() << nl;
    cout << ans;
}