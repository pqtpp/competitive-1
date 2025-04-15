#include "template"
#include "prime"
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n; n *= 2;
    vi p;
    enumprimes(n, p);
    cout << *lower_bound(all(p), n/2) << nl;
}