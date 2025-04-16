#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    vi a(3); iota(all(a), 0);
    vi b(3);
    rep(i, 3) {
        char c; cin >> c; if (c == '<') b[i] = 1;
    }
    do {
        bool flag = true;
        if (b[0] xor (a[0] < a[1])) flag = false;
        if (b[1] xor (a[0] < a[2])) flag = false;
        if (b[2] xor (a[1] < a[2])) flag = false;
        if (flag) {
            rep(i, 3) {
                if (a[i] == 1) {
                    cout << "ABC"[i] << nl;
                }
            }
        }
    } while (nextp(a));
}