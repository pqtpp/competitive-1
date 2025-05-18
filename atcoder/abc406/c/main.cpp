#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    vi t(n,1), d(n,1), u(n,1);
    rep1(i,n-1) t[i] = (a[i-1] < a[i] ? t[i-1] + 1 : 1);
    per(i,n-1) d[i] = (a[i] < a[i+1] ? d[i+1] + 1 : 1);
    per(i,n-1) u[i] = (a[i] > a[i+1] ? u[i+1] + 1 : 1);
    ll ans = 0;
    rep(j,n-2){
        if(t[j] >= 2 && u[j] >= 2) {
            int k = j + u[j] - 1;
            if(k < n && d[k] >= 2) ans += 1LL * (t[j] - 1) * (d[k] - 1);
        }
    }
    cout << ans;

}