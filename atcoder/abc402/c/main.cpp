#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vvi a(m);
    rep(i, m) {
        int k; cin >> k;
        rep(j, k) {
            int x; cin >> x;
            a[i].pb(x-1);
        }
    }
    vi b(n); cin >> b;
    vi c(n);
    rep(i, n) c[b[i]-1] = i;
    vi ans(n);
    rep(i, m) {
        rep(j, a[i].size()) {
            a[i][j] = c[a[i][j]];
        }
        ans[Max(a[i])]++;
    }
    int o = m;
    vi ans2(n);
    per(i, n) {
        ans2[i] = o;
        o -= ans[i];
    }
    rep(i, n) cout << ans2[i] << nl;
}