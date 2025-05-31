#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}
void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    auto f = [](auto&& self, ll a, ll b, ll c, ll d) -> pll {
        ll n = a / b;
        a -= n * b, c -= n * d;
        if (d < c) return {n+1, 1};
        auto [p, q] = self(self, d, c, b, a);
        return {p*n+q, p};
    };
    cout << f(f, a, b, c, d).se << nl;
}