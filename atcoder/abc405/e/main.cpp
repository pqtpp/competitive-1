#include "template"
#include "modint"

int main() { IO();
    buildfac(5000000);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    mint ans = mint(0);
    rep(i, b+1) {
        ans += comb(a+i-1, i) * comb(b+c+d-i, c);
    }
    cout << ans << nl;
}