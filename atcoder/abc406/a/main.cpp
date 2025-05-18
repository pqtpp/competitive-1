#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    YN(a*60+b>c*60+d);
}