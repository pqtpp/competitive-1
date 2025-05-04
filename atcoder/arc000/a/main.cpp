#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi p(n, -1), cnt(n);
    rep1(i, n-1) {
        int x; cin >> x; x--;
        cnt[x]++;
        p[i] = x;
    }
    vi b(n);
    while (q--) {
        int m; cin >> m;
        vi a(m);
        int ans = 0;
        rep(i, m) {
            cin >> a[i]; a[i]--;
            b[a[i]]++;
            ans += cnt[a[i]] + 1;
        }
        range(i, a) {
            if (b[p[i]] == 1) {
                ans -= 2;
            }
        }
        range(i, a) {
            b[i]--;
        }
        cout << ans << nl;
    }
}