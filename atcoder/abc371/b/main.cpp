#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi flag(n);
    rep(i, m) {
        int x; char c; cin >> x >> c; x--;
        YN(c=='M' && chmax(flag[x], 1));
    }
}