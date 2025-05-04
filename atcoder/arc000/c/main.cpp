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
    if (n == 2 || n == 3) {
        cout << 1 << nl;
        return;
    }
    vec<char> c(4); cin >> c;
    if (c[1] == 'A' && c[0] == 'A' || c[1] == 'B' && c[3] == 'B') {
        cout << 1 << nl;
        return;
    }
    if (c[1] != c[2]) {
        mint ans = 2;
        cout << ans.pow(n-3) << nl;
        return;
    }
    mint ans1 = 1, ans2 = 1;
    rep(i, n-2) {
        ans1 += ans2;
        swap(ans1, ans2);
    }
    cout << ans1 << nl;
}