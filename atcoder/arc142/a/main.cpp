#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;
    if (n % 2 == 0) {
        Sort(a);
        ll ans = 0;
        rep(i, n/2) ans += a[i+n/2]-a[i];
        cout << ans << nl;
    } else {
        vll ans(n);
        pq<ll> q;
        pqg<ll> qg;
        ll s=0;
        for (int i=0; i<n; i+=2) {
            ans[i] += s;
            ll m = min(a[i], a[i+1]), M = max(a[i], a[i+1]);
            q.push(m); qg.push(M); s += M - m;
            while (qg.top() < q.top()) {
                ll x = q.top(); q.pop();
                ll y = qg.top(); qg.pop();
                s += 2 * (x - y);
                q.push(y); qg.push(x);
            }
        }
        pq<ll> q2; pqg<ll> qg2;
        s = 0;
        for (int i=n-1; 0<=i; i-=2) {
            ans[i] += s;
            ll m = min(a[i], a[i-1]), M = max(a[i], a[i-1]);
            q2.push(m); qg2.push(M); s += M - m;
            while (qg2.top() < q2.top()) {
                ll x = q2.top(); q2.pop();
                ll y = qg2.top(); qg2.pop();
                s += 2 * (x - y);
                q2.push(y); qg2.push(x);
            }
        }
        cout << Max(ans) << nl;
    }
}