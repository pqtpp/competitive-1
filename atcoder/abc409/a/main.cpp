#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str s, t; cin >> s >> t;
    rep(i, n) {
        if (s[i] == 'o' && t[i] == 'o') {
            Yes;
            return;
        }
    }
    No;
}