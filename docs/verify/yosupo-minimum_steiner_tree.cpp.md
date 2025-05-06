---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  - icon: ':warning:'
    path: graph/minimumsteinertree.hpp
    title: graph/minimumsteinertree.hpp
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/minimum_steiner_tree
  bundledCode: "#line 1 \"verify/yosupo-minimum_steiner_tree.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/minimum_steiner_tree\"\r\n#line 2 \"util/template.hpp\"\
    \n#ifdef poe\n#define debug(x) cerr<<#x<<\": \"<<x<<endl\n#else\n#define debug(x)\n\
    // #pragma GCC target(\"arch=skylake-avx512\")\n// #pragma GCC target(\"avx2\"\
    )\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\
    #endif\n#include<bits/stdc++.h>\nusing namespace std;\nusing ll=long long;\nusing\
    \ ull=unsigned long long;\nusing ld=long double;\nusing pi=pair<int,int>;\nusing\
    \ pll=pair<ll,ll>;\nusing str=string;\ntemplate<class T>using vec=vector<T>;\n\
    using vi=vec<int>;using vvi=vec<vi>;using vvvi=vec<vvi>;using vvvvi=vec<vvvi>;using\
    \ vvvvvi=vec<vvvvi>;\nusing vll=vec<ll>;using vvll=vec<vll>;using vvvll=vec<vvll>;using\
    \ vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;\nusing vpi=vec<pi>;using vvpi=vec<vpi>;using\
    \ vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using vvvvvpi=vec<vvvvpi>;\nusing vpll=vec<pll>;using\
    \ vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using vvvvpll=vec<vvvpll>;using vvvvvpll=vec<vvvvpll>;\n\
    template<class T>using pq=priority_queue<T,vector<T>>;\ntemplate<class T>using\
    \ pqg=priority_queue<T,vector<T>,greater<T>>;\n#define rep(i,n) for(int i=0;i<(int)(n);i++)\n\
    #define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n#define per(i,n) for(int i=(int)(n)-1;0<=i;i--)\n\
    #define per1(i,n) for(int i=(int)(n);0<i;i--)\n#define range(i,x) for(auto&i:x)\n\
    #define range2(i,j,x) for(auto&[i,j]:x)\n#define all(x) (x).begin(),(x).end()\n\
    #define rall(x) (x).rbegin(),(x).rend()\n#define Sort(x) sort((x).begin(),(x).end())\n\
    #define troS(x) sort((x).rbegin(),(x).rend())\n#define Reverse(x) reverse((x).begin(),(x).end())\n\
    #define uniq(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(),(x).end()),(x).end())\n\
    #define nextp(x) next_permutation((x).begin(),(x).end())\n#define nextc(x,k) next_combination((x).begin(),(x).end(),k)\n\
    #define bit(x,i) (((x)>>(i))&1)\n#define pf push_front\n#define pb push_back\n\
    #define df pop_front\n#define db pop_back\n#define fi first\n#define se second\n\
    #define elif else if\n#define Yes cout<<\"Yes\"<<'\\n'\n#define No cout<<\"No\"\
    <<'\\n'\n#define YN(x) cout<<((x)?\"Yes\":\"No\")<<'\\n'\n#define O(x) cout<<(x)<<'\\\
    n'\n#define ismid(a,b,c) ((a)<=(b)&&(b)<(c))\ntemplate<class S,class T>bool chmin(S&a,T\
    \ b){if(a>b){a=b;return true;}return false;}\ntemplate<class S,class T>bool chmax(S&a,T\
    \ b){if(a<b){a=b;return true;}return false;}\ntemplate<class T>bool next_combination(T\
    \ l,T r,int k){T m=l+k;if(l==r||l==m||r==m)return false;T t=m;while(l!=t){t--;if(*t<*(r-1)){T\
    \ d=m;while(*t>=*d)d++;iter_swap(t,d);rotate(t+1,d+1,r);rotate(m,m+(r-d)-1,r);return\
    \ true;}}rotate(l,m,r);return false;}\ntemplate<class T>T Min(T a,T b){return\
    \ a<b?a:b;}\ntemplate<class T,class...Args>T Min(T a,T b,Args...args){return Min(Min(a,b),args...);}\n\
    template<class T>T Max(T a,T b){return a>b?a:b;}\ntemplate<class T,class...Args>T\
    \ Max(T a,T b,Args...args){return Max(Max(a,b),args...);}\ntemplate<class T>T\
    \ Sum(T a){return a;}\ntemplate<class T,class... Args>T Sum(T a,Args... args){return\
    \ a+Sum(args...);}\ntemplate<class T>T Max(const vector<T>&v){return *max_element(all(v));}\n\
    template<class T>T Min(const vector<T>&v){return *min_element(all(v));}\ntemplate<class\
    \ T>T Sum(const vector<T>&v){return accumulate(all(v),T(0));}\ntemplate<class\
    \ S,class T>T Max(const pair<S,T>&p){return max(p.first,p.second);}\ntemplate<class\
    \ S,class T>T Min(const pair<S,T>&p){return min(p.first,p.second);}\ntemplate<class\
    \ S,class T>T Sum(const pair<S,T>&p){return p.first+p.second;}\ntemplate<class\
    \ S,class T>istream&operator>>(istream&s,pair<S,T>&p){s>>p.first>>p.second;return\
    \ s;}\ntemplate<class S,class T>ostream&operator<<(ostream&s,pair<S,T>&p){s<<p.first<<'\
    \ '<<p.second<<'\\n';return s;}\ntemplate<class T>istream&operator>>(istream&s,vector<T>&v){for(auto&i:v)s>>i;return\
    \ s;}\ntemplate<class T>ostream&operator<<(ostream&s,vector<T>&v){for(auto&i:v)s<<i<<'\
    \ ';s<<'\\n';return s;}\ntemplate<class F>long long bsearch(long long ok,long\
    \ long ng,F&f){while(abs(ok-ng)>1){long long mid=(ok+ng)/2;if(f(mid))ok=mid;else\
    \ ng=mid;}return ok;}\nconst int dxy[5]={0,1,0,-1,0};\nconst int dx[8]={0,1,0,-1,1,1,-1,-1};\n\
    const int dy[8]={1,0,-1,0,1,-1,1,-1};\n#define nl '\\n'\n#define sp ' '\n#define\
    \ inf ((1<<30)-(1<<15))\n#define INF (1LL<<61)\n#define mod 998244353\n\nvoid\
    \ IO() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout<<fixed<<setprecision(30);\n\
    }\n\nvoid solve();\n#line 3 \"graph/graphtemplate.hpp\"\nusing namespace std;\n\
    // \u8FBA\u306E\u69CB\u9020\u4F53 edge(from, to, cost, id)\ntemplate<class T =\
    \ int>\nstruct edge {\n    int from, to;\n    T cost;\n    int id;\n};\n// \u9802\
    \u70B9\u306E\u69CB\u9020\u4F53 vector<edge<T>>\ntemplate<class T = int>\nusing\
    \ edges = vector<edge<T>>;\n// \u30B0\u30E9\u30D5\u306E\u69CB\u9020\u4F53 graph<T,\
    \ directed, weighted> \ntemplate <class T = int, bool directed = false, bool weighted\
    \ = false>\nstruct graph {\n    bool isdirected, isweighted;\n    edges<T> _edges;\n\
    \    vector<edges<T>> data;\n    T sumcost;\n    graph() = default;\n    // \u9802\
    \u70B9\u6570 n \u306E\u30B0\u30E9\u30D5\u3092\u4F5C\u6210\u3059\u308B\n    graph(int\
    \ n) : isdirected(directed), isweighted(weighted), data(n), sumcost(T{}) {}\n\
    \    // from \u304B\u3089 to \u3078\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n    void\
    \ add_edge(int from, int to, T cost = 1, int id = -1) {\n        if (id == -1)\
    \ id = _edges.size() / (2 - directed);\n        data[from].push_back(edge<T>(from,\
    \ to, cost, id));\n        _edges.push_back(edge<T>(from, to, cost, id));\n  \
    \      if (!isdirected) {\n            data[to].push_back(edge<T>(to, from, cost,\
    \ id));\n        }\n        sumcost += cost;\n    }\n    // \u8FBA\u3092\u8FFD\
    \u52A0\u3059\u308B\n    void add_edge(edge<T> _e) {\n        add_edge(_e.from,\
    \ _e.to, _e.cost, _e.id);\n    }\n    // \u6A19\u6E96\u5165\u529B\u304B\u3089\u8FBA\
    \u3092\u8AAD\u307F\u8FBC\u3080\n    void read(int m, int indexed = 1) {\n    \
    \    for (int i=0; i<m; i++) {\n            int from, to;\n            T cost\
    \ = 1;\n            cin >> from >> to;\n            if (isweighted) cin >> cost;\n\
    \            add_edge(from - indexed, to - indexed, cost);\n        }\n    }\n\
    \    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\n    int size() {\n        return\
    \ data.size();\n    }\n    // \u9802\u70B9\u3092\u8FD4\u3059\n    edges<T> operator[](int\
    \ k) {\n        return data[k];\n    }\n};\n#line 4 \"graph/minimumsteinertree.hpp\"\
    \nusing namespace std;\ntemplate <class T, bool directed = false, bool weighted\
    \ = true>\nvector<int> minimumsteinertree(graph<T, directed, weighted> &g, vector<int>\
    \ &v) {\n    vector<vector<T>> dp(1<<v.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    vector<vector<T>> d(g.size(), vector<T>(g.size(), numeric_limits<T>::max()));\n\
    \    vector<vector<int>> id(g.size(), vector<int>(g.size(), -1));\n    vector<vector<pair<int,\
    \ int>>> par(1<<v.size(), vector<pair<int, int>>(g.size(), {-1, -1}));\n    for\
    \ (auto& _e : g._edges) {\n        d[_e.from][_e.to] = _e.cost;\n        id[_e.from][_e.to]\
    \ = _e.id;\n    }\n    for (int i=0; i<g.size(); i++) {\n        d[i][i] = 0;\n\
    \    }\n    for (int i=0; i<v.size(); i++) {\n        dp[1<<i][v[i]] = 0;\n  \
    \  }\n    for (int i=0; i<(1<<v.size()); i++) {\n        for (int j=i; 0<j; j=(j-1)&i)\
    \ {\n            for (int k=0; k<g.size(); k++) {\n                if (dp[j][k]\
    \ == numeric_limits<T>::max() || dp[i^j][k] == numeric_limits<T>::max()) continue;\n\
    \                if (dp[i][k] == dp[j][k] + dp[i^j][k]) {\n                  \
    \  dp[i][k] = dp[j][k] + dp[i^j][k];\n                    par[i][k] = {0, j};\n\
    \                }\n            }\n        }\n        priority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> q;\n        for (int j=0; j<g.size();\
    \ j++) {\n            if (dp[i][j] != numeric_limits<T>::max()) q.push({dp[i][j],\
    \ j});\n        }\n        while (!q.empty()) {\n            auto [x, y] = q.top();\
    \ q.pop();\n            if (dp[i][y] < x) continue;\n            for (auto& _e\
    \ : g[y]) {\n                if (x + _e.cost < dp[i][_e.to]) {\n             \
    \       dp[i][_e.to] = x + _e.cost;\n                    q.push({x + _e.cost,\
    \ _e.to});\n                    par[i][_e.to] = {1, y};\n                }\n \
    \           }\n        }\n    }\n    vector<int> res;\n    auto restore = [&](auto&&\
    \ self, int S, int u) -> void {\n        auto [x, from] = par[S][u];\n       \
    \ if (x == 0) {\n            int S1 = from;\n            int S2 = S ^ S1;\n  \
    \          self(self, S1, u);\n            self(self, S2, u);\n        } else\
    \ if (x == 1) {\n            if (id[from][u] != -1) res.push_back(id[from][u]);\n\
    \            self(self, S, from);\n        }\n    };\n    T ans = numeric_limits<T>::max();\n\
    \    int c = -1;\n    for (int i=0; i<g.size(); i++) {\n        if (dp[(1<<v.size())-1][i]\
    \ < ans) {\n            ans = dp[(1<<v.size())-1][i];\n            c = i;\n  \
    \      }\n    }\n    restore(restore, (1<<v.size())-1, c);\n    return res;\n\
    }\n#line 4 \"verify/yosupo-minimum_steiner_tree.cpp\"\n\r\nint main() { IO();\r\
    \n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, m; cin >> n >> m;\r\n    graph<ll, false, true> g(n);\r\
    \n    g.read(m, 0);\r\n    int k; cin >> k;\r\n    vi v(k); cin >> v;\r\n    vi\
    \ a = minimumsteinertree(g, v);\r\n    ll ans = 0;\r\n    range(i, a) ans += g._edges[i*2].cost;\r\
    \n    cout << ans << sp << a.size() << nl;\r\n    cout << a << nl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_steiner_tree\"\r\
    \n#include \"template\"\r\n#include \"minimumsteinertree\"\r\n\r\nint main() {\
    \ IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\
    \n\r\nvoid solve() {\r\n    int n, m; cin >> n >> m;\r\n    graph<ll, false, true>\
    \ g(n);\r\n    g.read(m, 0);\r\n    int k; cin >> k;\r\n    vi v(k); cin >> v;\r\
    \n    vi a = minimumsteinertree(g, v);\r\n    ll ans = 0;\r\n    range(i, a) ans\
    \ += g._edges[i*2].cost;\r\n    cout << ans << sp << a.size() << nl;\r\n    cout\
    \ << a << nl;\r\n}"
  dependsOn:
  - util/template.hpp
  - graph/minimumsteinertree.hpp
  - graph/graphtemplate.hpp
  isVerificationFile: false
  path: verify/yosupo-minimum_steiner_tree.cpp
  requiredBy: []
  timestamp: '2025-05-06 09:03:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/yosupo-minimum_steiner_tree.cpp
layout: document
redirect_from:
- /library/verify/yosupo-minimum_steiner_tree.cpp
- /library/verify/yosupo-minimum_steiner_tree.cpp.html
title: verify/yosupo-minimum_steiner_tree.cpp
---
