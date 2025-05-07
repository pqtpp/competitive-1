#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x;
    int ans = 0;
    for (int i=0; i<x; i++) {
        if (i % 2 == 0) {
            ans += 3;
        } else {
            ans -= 2;
        }
    }
    cout << ans << endl;
}