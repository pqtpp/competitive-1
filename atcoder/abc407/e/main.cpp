#include "template"
#include "generalsegtree"
int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    pq<ll> q;
    ll sum=0, cnt=0;
    rep(i, 2*n) {
        ll x; cin >> x;
        q.push(x);
        if (cnt < i/2+1) {
            sum += q.top(); q.pop();
            cnt++;
        }
    }
    O(sum);
}