#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    str s; cin >> s;
    rep(i, 26) {
        char x = 'a' + i;
        bool flag = true;
        range(c, s) {
            if (c == x) {
                flag = false;
            }
        }
        if (flag) {
            cout << x << nl;
            return;
        }
    }
}