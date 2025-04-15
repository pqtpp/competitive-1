#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    str s; cin >> s;
    int ans = 0;
    rep(i, n-2) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            ans++;
        }
    }
    while (q--) {
        int x; char c; cin >> x >> c;
        rep(i, 3) {
            int y = x - 3 + i;
            if (0 <= y && y < n-2) {
                if (s[y] == 'A' && s[y+1] == 'B' && s[y+2] == 'C') {
                    ans--;
                }
            }
        }
        s[x-1] = c;
        rep(i, 3) {
            int y = x - 3 + i;
            if (0 <= y && y < n-2) {
                if (s[y] == 'A' && s[y+1] == 'B' && s[y+2] == 'C') {
                    ans++;
                }
            }
        }
        cout << ans << nl;
    }
}