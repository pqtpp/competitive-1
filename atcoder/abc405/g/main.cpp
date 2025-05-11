#include "template"
#include "modint"
#include "segtree"

int main() { IO();
    buildfac(1000000);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

map<int, int> op(const map<int, int>& a, const map<int, int>& b) {
    map<int, int> re;
    for (auto& [k, v] : a) re[k] = v;
    for (auto& [k, v] : b) re[k] += v;
    return re;
}
map<int, int> e() { return {}; }

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    rep(i, n) a[i]--;
    vec<map<int, int>> b(n);
    rep(i, n) b[i][a[i]] = 1;
    segtree<map<int, int>, op, e> seg(b);
    while (q--) {
        int l, r, x; cin >> l >> r >> x; --l; --x;
        map<int, int> p = seg.prod(l, r);
        ll s = 0;
        map<int, int> m;
        for (auto& [y, z] : p) {
            if (y < x) {
                m[y] = z;
                s += z;
            }
        }
        mint ans = fac[s];
        for (auto& [x, y] : m) ans *= ifac[y];
        cout << ans << nl;
    }
}
