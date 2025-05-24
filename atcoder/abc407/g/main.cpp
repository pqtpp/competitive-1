#include "template"
#line 1 "graph/flow/primal-dual.hpp"
/**
 * @brief Primal Dual(最小費用流)
 *
 */
template <typename flow_t, typename cost_t>
struct PrimalDual {
  struct edge {
    int to;
    flow_t cap;
    cost_t cost;
    int rev;
    bool isrev;
  };

  vector<vector<edge> > graph;
  vector<cost_t> potential, min_cost;
  vector<int> prevv, preve;
  const cost_t innerINF;

  PrimalDual(int V) : graph(V), innerINF(numeric_limits<cost_t>::max()) {}

  void add_edge(int from, int to, flow_t cap, cost_t cost) {
    graph[from].emplace_back(
        (edge){to, cap, cost, (int)graph[to].size(), false});
    graph[to].emplace_back(
        (edge){from, 0, -cost, (int)graph[from].size() - 1, true});
  }

  cost_t min_cost_flow(int s, int t, flow_t f) {
    int V = (int)graph.size();
    cost_t ret = 0;
    using Pi = pair<cost_t, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi> > que;
    potential.assign(V, 0);
    preve.assign(V, -1);
    prevv.assign(V, -1);

    while (f > 0) {
      min_cost.assign(V, innerINF);
      que.emplace(0, s);
      min_cost[s] = 0;
      while (!que.empty()) {
        Pi p = que.top();
        que.pop();
        if (min_cost[p.second] < p.first) continue;
        for (int i = 0; i < (int)graph[p.second].size(); i++) {
          edge &e = graph[p.second][i];
          cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] -
                            potential[e.to];
          if (e.cap > 0 && min_cost[e.to] > nextCost) {
            min_cost[e.to] = nextCost;
            prevv[e.to] = p.second, preve[e.to] = i;
            que.emplace(min_cost[e.to], e.to);
          }
        }
      }
      if (min_cost[t] == innerINF) return -1;
      for (int v = 0; v < V; v++) potential[v] += min_cost[v];
      flow_t addflow = f;
      for (int v = t; v != s; v = prevv[v]) {
        addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
      }
      f -= addflow;
      ret += addflow * potential[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge &e = graph[prevv[v]][preve[v]];
        e.cap -= addflow;
        graph[v][e.rev].cap += addflow;
      }
    }
    return ret;
  }

  void output() {
    for (int i = 0; i < graph.size(); i++) {
      for (auto &e : graph[i]) {
        if (e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/"
             << rev_e.cap + e.cap << ")" << endl;
      }
    }
  }
};

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int h, w; cin >> h >> w;
    vvll a(h, vll(w)); cin >> a;
    ll sum = 0; rep(i, h) sum += Sum(a[i]);
    int n = h * w, s = n, t = n + 1;
    PrimalDual<int, ll> pd(n + 2);
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    auto id = [&](int i, int j) { return i * w + j; };
    rep(i, h) rep(j, w) {
        int u = id(i, j);
        if ((i + j) % 2 == 0) {
            pd.add_edge(s, u, 1, 0);
            rep(d, 4) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                pd.add_edge(u, id(ni, nj), 1, a[i][j] + a[ni][nj]);
            }
        } else {
            pd.add_edge(u, t, 1, 0);
        }
    }
    ll ans = 0;
    while (true) {
        ll c = pd.min_cost_flow(s, t, 1);
        if (0 <= c || c == -1) break;
        ans += c;
    }
    cout << sum - ans << nl;
}