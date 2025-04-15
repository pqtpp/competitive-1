#include "template"

int main() {
    int T=1;
    // cin >> T;
    while (T--) solve();
}
#define q(i,j) cout << '?' << sp << i << sp << j << endl;
void solve() {
    int n; cin >> n;
    vi a;
    int ans = inf;
    for (int i=3; i<=n; i++) {
        int x, y;
        q(1, i);
        cin >> x;
        q(i, 2);
        cin >> y;
        chmin(ans, x + y);
        if (x + y == 3) a.pb(i);
    }
    if (ans == 3) {
        if (a.size() == 2) {
            q(a[0], a[1]);
            int x; cin >> x;
            if (x != 1) ans = 1;
        } else {
            ans = 1;
        }
    }
    cout << '!' << sp << ans << endl;
}