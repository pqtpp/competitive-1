#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n+1);
    rep(i, m) {
        int x, y; cin >> x >> y; x--;
        a[x]++;
        a[y]--;
    }
    rep1(i, n) a[i] += a[i-1];
    int ans = inf;
    rep(i, n) chmin(ans, a[i]);
    cout << ans << nl;
}