#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int r, x; cin >> r >> x;
    if (x == 2) {
        YN(ismid(1200, r, 2400));
    } else {
        YN(ismid(1600, r, 3000));
    }
}