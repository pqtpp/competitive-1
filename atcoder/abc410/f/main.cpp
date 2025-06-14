#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vec<str> s(h); cin >> s;
    if (h > w) {
        vec<str> t(w, str(h, ' '));
        rep(i, h) rep(j, w) t[j][i] = s[i][j];
        swap(s, t);
        swap(h, w);
    }
    vvi a(h, vi(w));
    rep(i, h) rep(j, w) a[i][j] = (s[i][j] == '#' ? 1 : -1);
    vvi sum2(h+1, vi(w));
    rep(i, h) rep(j, w) sum2[i+1][j] = sum2[i][j] + a[i][j];
    ll ans = 0;
    rep(i, h) {
        for (int k=i; k<h; k++) {
            vi b(w);
            rep(j, w) b[j] = sum2[k+1][j] - sum2[i][j];
            map<int, int> cnt;
            cnt[0]++;
            int sum = 0;
            rep(j, w) {
                sum += b[j];
                ans += cnt[sum];
                cnt[sum]++;
            }
        }
    }
    cout << ans << nl;
}
