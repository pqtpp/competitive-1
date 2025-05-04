#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vec<str> s(n), t(n); cin >> t; cin >> s;
    int ans = inf;
    rep(i, 4) {
        int ans2 = i;
        rep(x, n) rep(y, n) if (s[x][y] != t[x][y]) ans2++;
        chmin(ans, ans2);
        vec<str> T = t;
        rep(x, n) rep(y, n) {
            T[y][n-x-1] = t[x][y];
        }
        rep(x, n) rep(y, n) t[x][y] = T[x][y];
    }
    cout << ans << nl;
}