#include "template"
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); iota(all(a), 1);
    int k = 0;
    while (q--) {
        int x, y; cin >> x >> y;
        if (x == 1) {
            int z; cin >> z;
            a[(k + y-1+n) % n] = z;
        } elif (x == 2) {
            cout << a[(k + y-1+n) % n] << nl;
        } else {
            k = (k + y) % n;
        }
    }
}