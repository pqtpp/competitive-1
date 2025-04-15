#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;
    vi ans(n);
    stack<int> s; s.push(inf);
    per(i, n) {
        ans[i] = s.size() - 1;
        while (s.top() < a[i]) s.pop();
        s.push(a[i]);
    }
    cout << ans;
}