#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi c(n), a(n);
    rep1(i, n-1) cin >> c[i];
    rep1(i, n-1) cin >> a[i];
}