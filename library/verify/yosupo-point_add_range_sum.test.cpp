#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "template"
#include "sqrttree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vll a(n); cin >> a;
    sqrttree<ll,[](ll a,ll b){return a+b;}, [](){return 0;},ll,[](ll a,ll b,ll l){return b+a*l;},[](ll a,ll b){return a+b;},[](){return 0;}> seg(a);
    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        if (x == 0) {
            seg.update(y, y+1, z);
        } else {
            cout << seg.prod(y, z) << nl;
        }
    }
}