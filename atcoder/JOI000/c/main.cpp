#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, m) {
        int x, y; cin >> x >> y; y--;
        a[y] = x;
    }
    vi b;
    rep(i, n - m) {
        int x; cin >> x;
        b.pb(x);
    }
    int lgn=0;
    int N = 1;
    vi pw(1, 1);
    while (N < n) {
        N *= 3;
        lgn++;
        pw.pb(N);
    }
    ll l = 1, r = 1000000001;
    while (1 < r - l) {
        ll mid = l + (r - l) / 2;
        queue<int> q;
        rep(i, n) {
            if (a[i] == 0) {
                q.push(1);
            } elif (mid <= a[i]) {
                q.push(0);
            } else {
                q.push(inf);
            }
        }
        while (1 < q.size()) {
            vi t;
            rep(i, 3) {
                t.pb(q.front());
                q.pop();
            }
            Sort(t);
            q.push(min(inf, t[0] + t[1]));
        }
        int cnt = 0;
        range(i, b) if (mid <= i) cnt++;
        if (q.front() <= cnt) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << nl;
}