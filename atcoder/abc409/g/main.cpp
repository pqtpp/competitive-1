#include "template"
#include "modint"
#include "convolution"

int main() { IO();
    buildfac(200000);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    int P; cin >> P;
    mint p, q; p = mint(P) / mint(100);
    q = mint(1) - p;
    vec<mint> inv(n+1);
    rep1(i, n) inv[i] = mint(1) / mint(i);
    vec<mint> dp(n+1); dp[0] = mint(1);
    rep1(i, n) dp[i] = dp[i-1] * (inv[i] * q + 1);
    vi a(n), b(n);
    a[0] = 1;
    b[0] = 1;
    rep1(i, n-1) {
        a[i] = (fac[i-1] * dp[i].inv()).val;
        b[i] = (q.pow(i) * ifac[i]).val;
    }
    vi c = convolution(a, b);
    vec<mint> ans(n);
    ans[0] = dp[n-1];
    rep1(i, n-1) ans[i] = dp[n-1] * p.pow(i) * fac[i-1] * c[i-1];
    range(i, ans) cout << i << nl;
}