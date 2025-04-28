#include "template"
#include "dynamicsegtree"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

struct T {
    bool len = 0;
    ll sum0 = 0, sum1 = 0;
};
T op(T a, T b) {
    if (a.len) swap(b.sum0, b.sum1);
    a.len ^= b.len;
    a.sum0 += b.sum0;
    a.sum1 += b.sum1;
    return a;
}

void solve() {
}