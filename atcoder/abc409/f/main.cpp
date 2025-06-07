#include "template"
#include "UnionFind"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    int m = n + q;
    vpll p(m);
    rep(i, n) {
        int x, y; cin >> x >> y;
        p[i] = {x, y};
    }
    UnionFind uf(m);
    pqg<pair<ll, pll>> qu;
    rep(i, n) rep(j, i) {
        int d = abs(p[i].fi-p[j].fi) + abs(p[i].se-p[j].se);
        qu.push({d, {j, i}});
    }
    int cnt = n;
    int k = n;
    while (q--) {
        int x; cin >> x;
        if (x == 1) {
            int y, z; cin >> y >> z;
            k++;
            p[cnt] = {y, z};
            rep(i, cnt) {
                if (uf.same(i, cnt)) continue;
                int d = abs(p[i].fi - y) + abs(p[i].se - z);
                qu.push({d, {i, cnt}});
            }
            cnt++;
        } elif (x == 2) {
            if (k == 1) cout << -1 << nl;
            else {
                while (!qu.empty() && uf.same(qu.top().se.fi, qu.top().se.se)) {
                    qu.pop();
                }
                auto [d, _] = qu.top();
                cout << d << nl;
                while (!qu.empty()) {
                    auto [dd, pp] = qu.top();
                    if (d != dd) break;
                    qu.pop();
                    if (uf.merge(pp.fi, pp.se)) k--;
                }
            }
        } else {
            int y, z; cin >> y >> z; y--; z--;
            YN(uf.same(y, z));
        }
    }
}