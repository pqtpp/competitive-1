#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int t=0, v=0;
    for (int i=0; i<n; i++) {
        int T, V; cin >> T >> V;
        int dt = T - t;
        v -= dt;
        if (v < 0) v = 0;
        v += V;
        t = T;
    }
    cout << v << endl;
}