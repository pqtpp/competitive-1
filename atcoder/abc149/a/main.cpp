#include "template"
#include "rollinghash"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
string shortest_palindrome(string S) {
    string R = S;
    reverse(R.begin(), R.end());

    rollinghash hS(S), hR(R);
    int n = S.size(), len = 0;
    for (int i = 0; i <= n; ++i) {
        // check if S[i..n) == reverse(R[0..n-i))
        if (hS.prod(i, n) == hR.prod(0, n - i)) {
            len = n - i;
            break;
        }
    }
    return R.substr(0, n - len) + S;
}

void solve() {
    string s = "aacecaaa";
    cout << shortest_palindrome(s) << endl;  // 出力: "aaacecaaa"
}