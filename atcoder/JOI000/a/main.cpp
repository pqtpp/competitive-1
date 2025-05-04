#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vpi a(n); rep(i, n) cin >> a[i].se >> a[i].fi;
    troS(a);
    int l = 0, r = n + 1;
    while (1 < r - l) {
        int mid = l + (r - l) / 2;
        pq<ll> q;
        ll sum = 0;
        rep(i, mid) {
            q.push(a[i].se);
            sum += a[i].se;
        }
        bool flag = false;
        if (sum <= a[mid-1].fi * mid) {
            flag = true;
        }
        for (int i = mid; i < n; i++) {
            sum -= q.top(); q.pop();
            sum += a[i].se; q.push(a[i].se);
            if (sum <= a[i].fi * mid) {
                flag = true;
            }
        }
        if (flag) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << nl;
}