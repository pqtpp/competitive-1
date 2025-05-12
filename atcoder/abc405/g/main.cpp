#include "template"
#include "modint"
#include "Mo"
#include "sqrttree"

int main() { IO();
    buildfac(1000000);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a;
    Mo mo(n);
    vi queries(q), ans(q);
    rep(i, q) {
        int x, y, z; cin >> x >> y >> z;
        queries[i] = z;
        mo.add(x-1, y);
    }
    using S = int;
    auto op = []() {};
    auto e = []() {};
    auto add = [&](int x) {};
    auto erase = [&](int x) {};
    auto out = [&](int x) {};
}

