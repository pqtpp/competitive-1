#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; str s; cin >> n >> s;
    int sum = 0;
    vi a(n);
    rep(i, n) {
        if(s[i] == '1'){
            sum++;
            a[i] = +1;
        } else {
            a[i] = -1;
        }
    }
    int ans = 0, c = 0;
    rep(i, n) {
        c = max(a[i], c + a[i]);
        ans = max(ans, c);
    }
    cout << sum - ans << nl;
}