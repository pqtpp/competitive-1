#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    ld x, y, r; cin >> x >> y >> r;
    ll X = x * 10000, Y = y * 10000, R = r * 10000;
    ll ans = 0;
    for (ll i=(X-R)/10000*10000; i<=(X+R+9999)/10000*10000; i+=10000) {
        ll l=(Y-R)/10000*10000, r=(Y+R+9999)/10000*10000;
        while (10000 < r - l) {
            r/=10000; l/=10000;
            ll m = (l + r) / 2;
            r*=10000; l*=10000;
            m*=10000;
            if ((i-X)*(i-X) + (m-Y)*(m-Y) <= R*R) {
                r = m;
            } else {
                l = m;
            }
        }
        ans += (r - l) / 10000;
    }
    cout << ans << nl;
}