#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, s; cin >> n >> s;
    int t=0; t += s;
    rep(i, n) {
        int x; cin >> x;
        if (t < x) {
            No;
            return;
        }
        t = x + s;
    }
    Yes;
}