#include "template"
#include "graphtemplate"
#include "segtree"
#include "dijkstra"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void eulertour(graph<ll, false, true> &g, vi &in, vi &out, vll &et, int v, ll d, int p) {
    in.pb(v);
    et.pb(d);
    range(e, g[v]) {
        if (e.to == p) continue;
        eulertour(g, in, out, et, e.to, e.cost, v);
    }
    out.pb(v);
    et.pb(-d);
}

void solve() {
    int n; cin >> n;
    graph<ll, false, true> g(n);
    g.read(n-1, 1);
    vi in, out; vll et;
    eulertour(g, in, out, et, 0, 0, -1);
    vi in2(n), out2(n);
    rep(i, n) {
        in2[in[i]] = i;
        out2[out[i]] = i;
    }
    auto op=[](ll a,ll b){return a+b;};
    segtree<ll, op> seg(et);
    int q; cin >> q;
    vll d = dijkstra(g, 0);
    while (q--) {
        ll x, y, z; cin >> x >> y >> z;
        if (x == 1) {
            y--;
            auto e = g._edge[2*y];
            int p=e.from, q=e.to;
            if (d[q] < d[p]) swap(p, q) {
                seg.set(in2[q], z);
                seg.set(out2[q], -z);
            }
        } else {
            y--; z--;
            if (in[y] > in[z]) swap(y, z);
            int l=0, r=n;
            while (1 < r - l) {
                int m = (l + r) / 2;
                if (in[m] <= in[y] && out[z] <= out[m]) {
                    r = m;
                } else {
                    l = m;
                }
            }
            int lca = l;
            ll ans = seg.prod(in[lca], in[y] + 1) + seg.prod(in[lca], in[z] + 1);
            cout << ans << nl;
        }
    }
}