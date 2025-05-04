#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n;
    cin >> n;
    vll a(n); cin >> a;
    Sort(a);
    vll p(n+1);
    rep(i, n) p[i+1] = p[i] + a[i];
    int ans = 0;
    rep1(i, n) {
        ll sum = p[i];
        int l = -1, r = i;
        while (1 < r - l) {
            int m = l + (r - l) / 2;
            if (sum < a[m] * i) r = m;
            else l = m;
        }
        chmax(ans, i - r);
    }
    cout << ans << nl;
}
