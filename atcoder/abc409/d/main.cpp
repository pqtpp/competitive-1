#include "template"

int main() { IO();
    int T=1;
    cin >> T;
    while (T--) solve();
}

void solve() {
    int n; str s; cin >> n >> s;
    int l=-1;
    rep(i, n-1) {
        if (s[i] > s[i+1]) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        cout << s << nl;
        return;
    }
    int r;
    for (r=l+1; r<n; r++) {
        if (s[r] > s[l]) {
            break;
        }
    }
    rep(i, n) {
        if (i == r-1) {
            cout << s[l];
        } elif (ismid(l, i, r)) {
            cout << s[i+1];
        } else {
            cout << s[i];
        }
    }
    cout << nl;
}