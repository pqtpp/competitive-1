#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
int n, m;
vvi a(30, vi(30));
vi presum[30][30], nexsum[30][30];
vi pw(30);

void predfs(int i, int j, int d, int r);
void nexdfs(int I, int J, int i, int j, int d, int r);

void solve() {
    cin >> n >> m;
    rep1(i, n) rep1(j, n) cin >> a[i][j];
    
    pw[0] = 1 % m;
    rep1(i, n-1) pw[i] = (ll)pw[i-1]*10 % m;

    predfs(1, 1, 0, a[1][1] % m);

    rep1(i, n) {
        int j = n + 1 - i;
        if (j < 1 || j > n) continue;
        if (presum[i][j].empty()) continue;
        nexdfs(i, j, i, j, 0, 0);
        sort(all(nexsum[i][j]));
    }

    int res = 0;
    int P = pw[n-1]; // 10^{N-1} mod m

    rep1(i, n) {
        int j = n + 1 - i;
        if (j < 1 || j > n) continue;
        if (presum[i][j].empty() || nexsum[i][j].empty()) continue;

        for (int r1 : presum[i][j]) {
            int offset = (ll)r1 * P % m;
            int need = m - offset;
            auto &v = nexsum[i][j];
            int idx = lower_bound(all(v), need) - v.begin();

            // case 1: wraparound (r2 ≥ need)
            if (idx < v.size()) {
                int r2 = v.back(); // 最大値がベスト
                int score = (offset + r2 - m + m) % m;
                chmax(res, score);
            }
            // case 2: no wraparound (r2 < need)
            if (idx > 0) {
                int r2 = v[idx - 1];
                int score = (offset + r2) % m;
                chmax(res, score);
            }
        }
    }

    cout << res << '\n';
}

void predfs(int i, int j, int d, int r) {
    if (d == n - 1) { presum[i][j].pb(r); return; }
    if (i + 1 <= n) predfs(i+1, j, d+1,  (int)(((ll)r*10 + a[i+1][j]) % m));
    if (j + 1 <= n) predfs(i, j+1, d+1,  (int)(((ll)r*10 + a[i][j+1]) % m));
}

void nexdfs(int I, int J, int i, int j, int d, int r) {
    if (d == n - 1) { nexsum[I][J].pb(r); return; }
    if (i + 1 <= n) nexdfs(I, J, i+1, j, d+1,  (int)(((ll)r*10 + a[i+1][j]) % m));
    if (j + 1 <= n) nexdfs(I, J, i, j+1, d+1,  (int)(((ll)r*10 + a[i][j+1]) % m));
}