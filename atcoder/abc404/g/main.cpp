#include "template"

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    edges.reserve(2*M + N);

    // 区間和：P[R] - P[L-1] = S
    for(int i = 0; i < M; i++){
        int L, R;
        ll S;
        cin >> L >> R >> S;
        // P[R] >= P[L-1] + S
        edges.push_back({L-1, R, S});
        // P[L-1] >= P[R] - S
        edges.push_back({R, L-1, -S});
    }

    // A[j] >= 1  =>  P[j] >= P[j-1] + 1
    for(int j = 1; j <= N; j++){
        edges.push_back({j-1, j, 1});
    }

    // Bellman–Ford で最長経路を求める
    vector<ll> dist(N+1, -INF);
    dist[0] = 0;

    bool updated = false;
    for(int iter = 0; iter <= N; iter++){
        updated = false;
        for(auto &e : edges){
            if(dist[e.u] == -INF) continue;
            if(dist[e.v] < dist[e.u] + e.w){
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        // N+1 回目（iter == N）でも更新があれば正閉路 -> 矛盾
        if(iter == N && updated){
            cout << -1 << "\n";
            return 0;
        }
        if(!updated) break;
    }

    // 解があれば dist[N] が A の総和の最小値
    cout << dist[N] << "\n";
}