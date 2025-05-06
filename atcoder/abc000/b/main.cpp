#include "template"
#include "modint"

int main() { IO();
    setmod(1000000007);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;
    Sort(a);
    vec<mint> b(n);
    rep(i, n) b[i] = mint(a[i]);
    rep(i, n-1) b[i+1] += b[i];
    mint p = 1;
    mint ans = 0;
    rep(i, n) {
        cout << b[i] * p << nl;
        ans += b[i] * p;
        p *= 2;
    }
    cout << ans * mint(2).pow(n) << nl;
}