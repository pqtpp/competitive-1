#include "template"
#include "rollinghash"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    str t; cin >> t;
    str revt = t; Reverse(revt);
    rollinghash T(t), REVT(revt);
    /*
    0: CBAABC
    1: ACBABC
    2: ABCBAC
    3: ABCCBA
     */
    /*
    ABCBAC
     ABC BAC 
    A BC B AC
    AB C BA C
    ABC  BAC 
     */
    rep(i, n+1) {
        if (T.hash(0, i)==REVT.hash(0, i)) {
            if (T.hash(i, n)==REVT.hash(i, n)) {
                rep(j, n) {
                    if (j < i) {
                        cout << t[j];
                    } else {
                        cout << t[n+j];
                    }
                }
                cout << nl << i << nl;
            }
        }
    }
}