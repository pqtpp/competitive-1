#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); cin >> a;
    vi cnt(m); range(i, a) cnt[i-1]++;
    if (Min(cnt)==0) {
        cout << 0 << nl;
        return;
    }
    per(i, n) {
        if (--cnt[a[i]-1] == 0) {
            cout << n - i << nl;
            return;
        }
    }
}