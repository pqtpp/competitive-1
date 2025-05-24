#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int x, y; cin >> x >> y;
    int cnt = 0;
    rep1(i, 6) rep1(j, 6) { 
        if (x <= i + j or y <= abs(i - j)) {
            cnt++;
        }
    }
    cout << 1.0 * cnt / 36 << nl;
}