#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    int k; cin >> k;
    int cnt = 0;
    range(i, a) if (k <= i) cnt++;
    cout << cnt << nl;
}