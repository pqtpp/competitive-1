#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vll a(h*w);
    rep(i, h*w) cin >> a[i];
    ll all = 0;
    range(i, a) all ^= i;
    ll ans = 0;
    auto dfs = [&](auto&& self, int t, ll cur) -> void {
        if (t == (1 << (h*w)) - 1) {
            chmax(ans, all^cur);
            return;
        }
        int i = 0;
        while (t & (1<<i)) i++;
        self(self, t|(1<<i), cur);
        int x = i/w, y = i%w;
        {
            int nx = x+1, ny = y;
            if (ismid(0, nx, h) && ismid(0, ny, w)) {
                int j = nx*w+ny;
                if (!(t & (1<<j))) {
                    self(self, t|(1<<i)|(1<<j), cur^a[i]^a[j]);
                }
            }
        }
        {
            int nx = x, ny = y+1;
            if (ismid(0, nx, h) && ismid(0, ny, w)) {
                int j = nx*w+ny;
                if (!(t & (1<<j))) {
                    self(self, t|(1<<i)|(1<<j), cur^a[i]^a[j]);
                }
            }
        }
    };
    dfs(dfs, 0, 0);
    cout << ans << nl;
}