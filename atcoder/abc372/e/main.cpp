#include "template"
#include "UnionFind"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    UnionFind uf(n);
    vvi data(n, vi(10)); rep(i, n) data[i][0] = i+1;
    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 1) {
            y--; z--;
            vi next(20);
            rep(i, 10) {
                next[i] = data[uf.root(y)][i];
                next[10+i] = data[uf.root(z)][i];
            }
            Sort(next);
            Reverse(next);
            if (uf.merge(y, z)) rep(i, 10) data[uf.root(y)][i] = next[i];
        } else {
            y--; z--;
            y = uf.root(y);
            cout << (data[y][z]==0 ? -1 : data[y][z]) << nl;
        }
    }
}