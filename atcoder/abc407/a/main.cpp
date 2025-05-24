#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ld a, b; cin >> a >> b;
    cout << ((int)(round(a/b))) << nl;
}