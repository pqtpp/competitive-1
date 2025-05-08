#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vvi a;
    rep1(i, n) {
        vi b(i);
        rep(j, i) { cin >> b[j]; b[j]--; }
        a.pb(b);
    }
    int c = 0;
    rep1(i, n-1) c = a[max(c, i)][min(c, i)];
    cout << c + 1 << nl;
}