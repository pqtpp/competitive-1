#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, d; cin >> h >> w >> d;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];
    int ans = 0;
    for (int i1=0; i1<h; i1++) {
        for (int j1=0; j1<w; j1++) {
            // s[i1][j1] に加湿器1を置く
            if (s[i1][j1] == '#') continue;
            for (int i2=0; i2<h; i2++) {
                for (int j2=0; j2<w; j2++) {
                    // s[i2][j2] に加湿器2を置く
                    if (s[i2][j2] == '#') continue;
                    if (i1==i2 && j1==j2) continue;
                    int cnt = 0;
                    for (int i=0; i<h; i++) {
                        for (int j=0; j<w; j++) {
                            // s[i][j] が加湿されてるか調べる
                            if (s[i][j] == '#') continue;
                            int m1 = abs(i - i1) + abs(j - j1);
                            int m2 = abs(i - i2) + abs(j - j2);
                            if (m1<=d || m2<=d) {
                                cnt++;
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
    }
    cout << ans << endl;
}