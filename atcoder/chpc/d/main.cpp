#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i=0; i<n; i++) {
        char c = s[i];
        if (c == 'J') {
            cout << 'O';
        } else if (c == 'O') {
            cout << 'I';
        } else {
            cout << 'J';
        }
    }
    cout << endl;
}