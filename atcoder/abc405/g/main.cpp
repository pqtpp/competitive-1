#include "template"
#include "modint"
#include "Mo"
#include "sqrttree"

int main() { IO();
    buildfac(300000);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a; rep(i, n) a[i]--;
    Mo mo(n);
    vi queries(q), ans(q);
    rep(i, q) {
        int x, y, z; cin >> x >> y >> z;
        queries[i] = z-1;
        mo.add(x-1, y);
    }
    sqrttree<pll,[](pll a,pll b){return pll{a.fi+b.fi,a.se*b.se%mod};},[](){return pll{0,1};},pll,[](pll a,pll b){return pll{a.fi+b.fi,a.se*b.se%mod};},[](pll a,pll b){return pll{a.fi+b.fi,a.se*b.se%mod};}> seg(n);
    vll inve(n+1); rep1(i, n) inve[i] = mint(i).inv().val;
    auto add = [&](int x) {
        seg.apply(a[x], pll{1, seg[a[x]].fi+1});
    };
    auto erase = [&](int x) {
        seg.apply(a[x], {-1, inve[seg[a[x]].fi]});
    };
    auto out = [&](int x) {
        auto [s, t] = seg.prod(0, queries[x]);
        ans[x] = (mint(fac[s])/t).val;
    };
    mo.build(add, erase, out);
    range(i, ans) cout << i << nl;
}

