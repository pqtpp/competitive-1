#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, h, m; cin >> n >> h >> m;
    vi a(n), b(n); rep(i, n) {
        cin >> a[i] >> b[i];
    }
    vi dp(h+1, -1); dp[h] = m;
    // dp[i] := 体力i の時残せる最大の魔力
    int ans = 0;
    rep(i, n) {
        vi ndp(h+1, -1);
        bool flag = false;
        rep(j, h+1) {
            if (dp[j] == -1) continue;
            if (b[i] <= dp[j]) {
                chmax(ndp[j], dp[j] - b[i]);
                flag = true;
            }
            if (a[i] <= j) {
                chmax(ndp[j - a[i]], dp[j]);
                flag = true;
            }
        }
        if (!flag) break;
        swap(dp, ndp);
        ans++;
    }
    cout << ans << nl;
}