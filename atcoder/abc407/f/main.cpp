#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;
    vll p(n), q(n);
    vll r;
    rep(i, n) {
        while (!r.empty() && a[r.back()]<=a[i]) r.pop_back();
        if (r.empty()) {
            p[i] = -1;
        } else {
            p[i] = r.back();
        }
        r.push_back(i);
    }
    r.clear();
    per(i, n) {
        while (!r.empty() && a[r.back()]<a[i]) r.pop_back();
        if (r.empty()) {
            q[i] = n;
        } else {
            q[i] = r.back();
        }
        r.push_back(i);
    }
    vll P(2*n), Q(2*n);
    rep(i, n) {
        ll x = a[i];
        ll L = i - p[i], R = q[i] - i;
        ll m = min(L, R), M = max(L, R);
        ll y = L + R; y--;
        if (0 < m) {
            Q[1] += x;
            Q[m+1] -= x;
        }
        if (m < M) {
            P[m+1] += x * m;
            P[M+1] -= x * m;
        }
        if (M < y) {
            P[M+1] += x * (y + 1);
            P[y+1] -= x * (y + 1);
            Q[M+1] -= x;
            Q[y+1] += x;
        }
    }
    ll ans=0, ans2=0;
    rep1(i, n) {
        ans += Q[i];
        ans2+= P[i];
        cout << ans * i + ans2 << nl;
    }
}