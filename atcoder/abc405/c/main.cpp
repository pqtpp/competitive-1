#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;
    ll s=0, S=0;
    range(i, a) {
        s += i;
        S += i * i;
    }
    cout << (s * s - S) / 2 << nl;
}