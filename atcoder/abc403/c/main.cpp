#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vec<set<int>> a(n);
    vi b(n);
    while (q--) {
        int x, y, z; cin >> x;
        if (x == 1) {
            cin >> y >> z; y--; z--;
            a[y].insert(z);
        } else if (x == 2) {
            cin >> y; y--;
            b[y]++;
        } else {
            cin >> y >> z; y--; z--;
            YN(a[y].count(z) || b[y] > 0);
        }
    }
}