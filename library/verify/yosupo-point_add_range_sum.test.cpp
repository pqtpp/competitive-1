#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "template"
#include "sqrttree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

using S2 = long long;
S2 op2(S2 a, S2 b) { return a + b; }
S2 e2() { return 0LL; }
using F2 = long long;
S2 mapping2(F2 f, S2 x, int len) { return x + f * len; }
F2 composition2(F2 f, F2 g) { return f + g; }
F2 id2() { return 0LL; }

void solve() {
    int n, q; cin >> n >> q;
    vec<S2> a(n); cin >> a;
    SqrtTree<S2, op2, e2, F2, mapping2, composition2, id2> seg(a);
    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 0) {
            seg.update(y, y+1, z);
        } else {
            cout << seg.query(y, z) << nl;
        }
    }
}