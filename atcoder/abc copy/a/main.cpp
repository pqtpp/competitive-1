#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    ll r = INF;
    vpll a(n); cin >> a;
    rep(i, n) a[i].fi *= 6;
    rep(i, n) a[i].se *= 6;
    rep(i, n) rep(j, i) {
        ll x = (a[i].fi + a[j].fi) / 2;
        ll y = (a[i].se + a[j].se) / 2;
        ll R = (a[i].fi-x) * (a[i].fi-x) + (a[i].se-y) * (a[i].se-y);
        bool flag = true;
        rep(t, n) {
            auto [X, Y] = a[t];
            if (R < (X-x)*(X-x)+(Y-y)*(Y-y)) {
                flag = false;
            }
        }
        if (flag) chmin(r, R);
    }
    rep(i, n) rep(j, i) rep(k, j) {
        // 3点の外接円の半径を求める
        auto [x1, y1] = a[i];
        auto [x2, y2] = a[j];
        auto [x3, y3] = a[k];
        ll A = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        if (A == 0) continue; // 3点が一直線上にある場合はスキップ
        ll B = (x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2);
        ll C = (x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1);
        ll D = (x1 * x1 + y1 * y1) * (x2 * y3 - x3 * y2) + (x2 * x2 + y2 * y2) * (x3 * y1 - x1 * y3) + (x3 * x3 + y3 * y3) * (x1 * y2 - x2 * y1);
        ll r2 = B * B + C * C + D * D;
        if (r2 == 0) continue; // 3点が重なっている場合はスキップ
        ll R = r2 / (4 * A * A);
        if (R < r) {
            bool flag = true;
            rep(t, n) {
                auto [X, Y] = a[t];
                if (R < (X * X + Y * Y) * 4 / (B * B + C * C + D * D)) {
                    flag = false;
                    break;
                }
            }
            if (flag) chmin(r, R);
        }
    }
    cout << sqrt(r) / 6 << nl;
}