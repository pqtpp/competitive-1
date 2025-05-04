#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vll c(n); cin >> c;
    vvi a(n);
    rep(i, m) {
        int k; cin >> k;
        rep(j, k) {
            int x; cin >> x; x--;
            a[x].pb(i);
        }
    }
    ll ans = INF;
    vi pw(n+1, 1); rep(i, n) pw[i+1] = pw[i] * 3;
    rep(i, pw[n]) {
        ll ans2 = 0;
        vi cnt(m);
        rep(j, n) {
            int x = i % pw[j+1] / pw[j];
            ans2 += x * c[j];
            range(k, a[j]) {
                cnt[k] += x;
            }
        }
        range(j, cnt) if (j < 2) ans2 = INF;
        chmin(ans, ans2);
    }
    cout << ans << nl;
}