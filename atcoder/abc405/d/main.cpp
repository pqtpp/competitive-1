#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vec<str> s(h); cin >> s;
    queue<pi> q;
    rep(i, h) rep(j, w) {
        if (s[i][j] == 'E') {
            q.push({i, j});
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        rep(i, 4) {
            int X = x + dxy[i], Y = y + dxy[i+1];
            if (ismid(0, X, h) && ismid(0, Y, w)) {
                if (s[X][Y] == '.') {
                    s[X][Y] = "<^>v"[i];
                    q.push({X, Y});
                }
            }
        }
    }
    range(i, s) cout << i << nl;
}