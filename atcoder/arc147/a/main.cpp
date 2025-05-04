#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    str s; cin >> s;
    int d=0, r=0;
    int n = s.size();
    range(i, s) {
        if (i == 'D') d++;
        elif (i == 'R') r++;
    }
    vpi L, R;
    int x=0, y=0;
    int cnt = 1;
    range(i, s) {
        if (i == 'D') {
            x++;
        } elif (i == 'R') {
            y++;
        } elif (cnt < h-d) {
            cnt++;
            x++;
        } else {
            y++;
        }
        L.pb({x, y});
    }
    x = 0, y = 0;
    cnt = 1;
    range(i, s) {
        if (i == 'D') {
            x++;
        } elif (i == 'R') {
            y++;
        } elif (cnt < w-r) {
            cnt++;
            y++;
        } else {
            x++;
        }
        R.pb({x, y});
    }
    ll ans = 1;
    rep(i, n) {ans += L[i].fi - R[i].fi + 1;}
    cout << ans << endl;
}