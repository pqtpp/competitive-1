#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w, n; cin >> h >> w >> n;
    vec<set<int>> H(h), W(w);
    rep(i, n) {
        int x, y; cin >> x >> y; x--; y--;
        H[x].insert(y);
        W[y].insert(x);
    }
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y; y--;
        if (x == 1) {
            cout << H[y].size() << nl;
            if (H[y].size()) range(i, H[y]) W[i].erase(y);
            H[y].clear();
        } else {
            cout << W[y].size() << nl;
            if (W[y].size()) range(i, W[y]) H[i].erase(y);
            W[y].clear();
        }
    }
}