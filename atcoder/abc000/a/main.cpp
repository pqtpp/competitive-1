#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int l, r; cin >> l >> r;
    if ((l+r) % 2 == 0) {
        cout << "Invalid" << nl;
    } else {
        YN(l);
    }
}