#include "template"
#include "UnionFind"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi cnt(n);
    UnionFind uf(n);
    rep(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        uf.merge(x, y);
        cnt[x]++;
        cnt[y]++;
    }
    bool flag = true;
    if (n != m) flag = false;
    rep(i, n) {
        if (!uf.same(0, i)) flag = false;
        if (cnt[i] != 2) flag = false;
    }
    YN(flag);
}