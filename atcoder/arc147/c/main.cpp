#include "template"
#include "isqrt"
#include "BIT"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    const int m = 2800000;
    BIT<int> seg(m);
    vector<char> cnt(m+1, 1);
    rep(i, m) seg.add(i, 1);
    unordered_set<int> visited;
    int q; cin >> q;
    while(q--){
        int a, k; cin >> a >> k;
        if(visited.insert(a).second && a <= m){
            for(int x=a; x <= m; x+=a){
                int p = x - 1;
                if(cnt[p]) {
                    cnt[p] = 0;
                    seg.add(p-1, -1);
                }
            }
        }
        int p = seg.lower_bound(k);
        cout << p + 1 << nl;
    }
}