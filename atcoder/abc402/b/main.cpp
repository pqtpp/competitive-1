#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int q; cin >> q;
    queue<int> qu;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int y; cin >> y;
            qu.push(y);
        } else {
            cout << qu.front() << nl;
            qu.pop();
        }
    }
}