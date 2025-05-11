#include "template"
#include "BIT"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(2*n, 0);
    vpi line(m);
    rep(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        if (y < x) swap(x, y);
        line[i] = {x, y}; 
        a[x] = a[y] =  1;
    }
    vi b(2*n+1);
    rep1(i, 2*n) b[i] = b[i-1] + a[i-1];
    troS(line);
    int q; cin >> q;
    vec<pair<pi, int>> queries(q);
    rep(i, q) {
        int x, y, z; cin >> x >> y; x--; y--;
        queries[i] = {{x, y}, i};
    }
    troS(queries);
    BIT<ll> seg(2*n);
    vll ans(q);
    ll cnt = 0;
    range(query, queries) {
        auto [z, i] = query; auto [x, y] = z;
        while (cnt < m && x < line[cnt].first) {
            seg.add(line[cnt].second, 1);
            cnt++;
        }
        ll s = seg.sum(y);
        ll t = b[y] - b[x+1];
        ans[i] = t - 2 * s;
    }
    range(i, ans) cout << i << nl;
}