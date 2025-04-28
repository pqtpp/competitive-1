#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
void solve() {
    int n; ll d;
    cin>>n>>d;
    vector<int> a(n);
    int m=0;
    for(int i=0;i<n;i++){cin>>a[i]; m = max(m, a[i]);}
    vector<ll> cnt(m+1);
    for(int x:a) cnt[x]++;
    ll t = 0;
    if(d==0){
        for(ll c:cnt) if(c>0) t++;
    } else {
        for(int r=0;r<d && r<=m;r++){
            ll pre=0, cur=0;
            for(int x=r; x<=m; x+=d){
                ll nxt = max(cur, pre + cnt[x]);
                pre = cur;
                cur = nxt;
            }
            t += cur;
        }
    }
    cout << (n - t) << nl;
}
