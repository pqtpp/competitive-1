#include "template"
#include "modint"
int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    ull n; int k; cin >> n >> k;
    vec<mint> p2(61);
    p2[0] = 1;
    rep1(i, 60) p2[i] = p2[i-1] * 2;
    vec<vec<mint>> dp(k+1, vec<mint>(2)), ss(k+1, vec<mint>(2));
    dp[0][1] = 1; ss[0][1] = 0;
    per(i, 61) {
        int I = (n >> i) & 1;
        vec<vec<mint>> ndp(k+1, vec<mint>(2));
        vec<vec<mint>> nsum(k+1, vec<mint>(2));
        rep(j, k+1) {
            rep(t, 2) {
                if (dp[j][t] == 0) continue;
                mint x = dp[j][t];
                mint acc  = ss[j][t];
                {
                    int nt = t && (I == 0);
                    ndp[j][nt] += x;
                    nsum[j][nt] += acc;
                }
                if (j+1 <= k && (!t || I == 1)) {
                    int nt = t && (I == 1);
                    ndp[j+1][nt] += x;
                    nsum[j+1][nt] += acc + x * p2[i];
                }
            }
        }
        dp.swap(ndp);
        ss.swap(nsum);
    }
    mint ans = ss[k][0] + ss[k][1];
    cout << ans.val << nl;
}