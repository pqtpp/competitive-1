#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str t, u;
    cin >> t >> u;
    int n = t.size();
    int m = u.size();
    bool ans = false;
    rep(i, n) {
        bool ans2 = true;
        rep(j, m) {
            if (t[i] != u[j] && t[i] != '?') {
                answ  = false;
            }
        }
        if (ans2) ans = true;
    }
}