#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi cnt(n);
    while (q--) {
        int x; cin >> x;
        if (x == 0) {
            int k = Min(cnt);
            rep(i, n) {
                if (cnt[i] == k) {
                    cout << i + 1 << sp;
                    cnt[i]++;
                    break;
                }
            }
        } else {
            cout << x << sp;
            cnt[x-1]++;
        }
    }
    cout << nl;
}