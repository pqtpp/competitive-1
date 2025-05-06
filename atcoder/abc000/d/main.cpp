#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpi a(n); cin >> a;
    vec<ld> d;
    int x=0, y=0;
    rep(i, n) {
        auto [X, Y] = a[i];
        d.pb(sqrt((X-x)*(X-x) + (Y-y)*(Y-y)));
        x = X; y = Y;
    }
    vec<vec<ld>> dp(n+1, vec<ld>(n+1, (ld)inf));
    dp[0][0] = 0;
    rep(i, n) rep(j, i) {
        chmin()
    }
}