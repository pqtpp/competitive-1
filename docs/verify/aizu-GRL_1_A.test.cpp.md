---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  - icon: ':heavy_check_mark:'
    path: util/template.hpp
    title: util/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
  bundledCode: "#line 1 \"verify/aizu-GRL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja\"\
    \r\n#line 2 \"util/template.hpp\"\n#ifdef poe\n#define debug(x) cerr<<#x<<\":\
    \ \"<<x<<endl\n#else\n#define debug(x)\n// #pragma GCC target(\"arch=skylake-avx512\"\
    )\n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#endif\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using pi=pair<int,int>;\nusing pll=pair<ll,ll>;\nusing str=string;\ntemplate<class\
    \ T>using vec=vector<T>;\nusing vi=vec<int>;using vvi=vec<vi>;using vvvi=vec<vvi>;using\
    \ vvvvi=vec<vvvi>;using vvvvvi=vec<vvvvi>;\nusing vll=vec<ll>;using vvll=vec<vll>;using\
    \ vvvll=vec<vvll>;using vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;\nusing vpi=vec<pi>;using\
    \ vvpi=vec<vpi>;using vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using vvvvvpi=vec<vvvvpi>;\n\
    using vpll=vec<pll>;using vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using vvvvpll=vec<vvvpll>;using\
    \ vvvvvpll=vec<vvvvpll>;\ntemplate<class T>using pq=priority_queue<T,vector<T>>;\n\
    template<class T>using pqg=priority_queue<T,vector<T>,greater<T>>;\n#define rep(i,n)\
    \ for(int i=0;i<(int)(n);i++)\n#define rep1(i,n) for(int i=1;i<=(int)(n);i++)\n\
    #define per(i,n) for(int i=(int)(n)-1;0<=i;i--)\n#define per1(i,n) for(int i=(int)(n);0<i;i--)\n\
    #define range(i,x) for(auto&i:x)\n#define range2(i,j,x) for(auto&[i,j]:x)\n#define\
    \ all(x) (x).begin(),(x).end()\n#define rall(x) (x).rbegin(),(x).rend()\n#define\
    \ Sort(x) sort((x).begin(),(x).end())\n#define troS(x) sort((x).rbegin(),(x).rend())\n\
    #define Reverse(x) reverse((x).begin(),(x).end())\n#define uniq(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(),(x).end()),(x).end())\n\
    #define nextp(x) next_permutation((x).begin(),(x).end())\n#define nextc(x,k) next_combination((x).begin(),(x).end(),k)\n\
    #define bit(x,i) (((x)>>(i))&1)\n#define pf push_front\n#define pb push_back\n\
    #define df pop_front\n#define db pop_back\n#define fi first\n#define se second\n\
    #define elif else if\n#define Yes cout<<\"Yes\"<<'\\n'\n#define No cout<<\"No\"\
    <<'\\n'\n#define YN(x) cout<<((x)?\"Yes\":\"No\")<<'\\n'\n#define O(x) cout<<(x)<<'\\\
    n'\ntemplate<class S,class T>bool chmin(S&a,T b){if(a>b){a=b;return true;}return\
    \ false;}\ntemplate<class S,class T>bool chmax(S&a,T b){if(a<b){a=b;return true;}return\
    \ false;}\ntemplate<class S,class T,class U>bool ismid(S a,S b,S c){return a<=b&&b<c;}\n\
    template<class T>bool next_combination(T l,T r,int k){T m=l+k;if(l==r||l==m||r==m)return\
    \ false;T t=m;while(l!=t){t--;if(*t<*(r-1)){T d=m;while(*t>=*d)d++;iter_swap(t,d);rotate(t+1,d+1,r);rotate(m,m+(r-d)-1,r);return\
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
    template<class T = int>\nstruct edge {\n    int from, to;\n    T cost;\n    int\
    \ id;\n    edge(int _from, int _to, T _cost = 1, int _id = -1) : from(_from),\
    \ to(_to), cost(_cost), id(_id) {}\n};\ntemplate<class T = int>\nusing edges =\
    \ vector<edge<T>>;\ntemplate<class T = int>\nstruct directedgraph {\n    vector<edges<T>>\
    \ data;\n    edges<T> _edges;\n    bool _weighted;\n    int count;\n    T sumcost;\n\
    \    directedgraph(int n, bool weighted=false) : data(n), _weighted(weighted),\
    \ sumcost(T{}) {}\n    void add_edge(int from, int to, T cost = 1, int id=-1)\
    \ {\n        if (id == -1) id = count;\n        data[from].push_back(edge(from,\
    \ to, cost, id));\n        _edges.push_back(edge(from, to, cost, id));\n     \
    \   count++;\n        sumcost += cost;\n    }\n    void add_edge(edge<T> eg) {\n\
    \        add_edge(eg.from, eg.to, eg.cost, eg.id);\n    }\n    void read(int m,\
    \ int indexed = 1) {\n        for (int i=0; i<m; i++) {\n            int from,\
    \ to;\n            T cost=1;\n            cin >> from >> to;\n            if (_weighted)\
    \ cin >> cost;\n            add_edge(from - indexed, to - indexed, cost);\n  \
    \      }\n    }\n    int size() {\n        return data.size();\n    }\n    edges<T>\
    \ operator[](int k) {\n        return data[k];\n    }\n};\ntemplate<class T =\
    \ int>\nstruct undirectedgraph {\n    vector<edges<T>> data;\n    edges<T> _edges;\n\
    \    bool _weighted;\n    int count;\n    T sumcost;\n    undirectedgraph(int\
    \ n, bool weighted=false) : data(n), _weighted(weighted), sumcost(T{}) {}\n  \
    \  void add_edge(int from, int to, T cost = 1, int id=-1) {\n        if (id ==\
    \ -1) id = count;\n        data[from].push_back(edge(from, to, cost, id));\n \
    \       _edges.push_back(edge(from, to, cost, id));\n        data[from].push_back(edge(to,\
    \ from, cost, id));\n        count++;\n        sumcost += cost;\n    }\n    void\
    \ add_edge(edge<T> eg) {\n        add_edge(eg.from, eg.to, eg.cost, eg.id);\n\
    \    }\n    void read(int m, int indexed = 1) {\n        for (int i=0; i<m; i++)\
    \ {\n            int from, to, cost=1;\n            cin >> from >> to;\n     \
    \       if (_weighted) cin >> cost;\n            add_edge(from - indexed, to -\
    \ indexed, cost);\n        }\n    }\n    int size() {\n        return data.size();\n\
    \    }\n    edges<T> operator[](int k) {\n        return data[k];\n    }\n};\n\
    #line 4 \"graph/dijkstra.hpp\"\nusing namespace std;\ntemplate <class T>\nvector<T>\
    \ dijkstra(directedgraph<T>& g, int from=0) {\n    vector<T> dist(g.size(), numeric_limits<T>::max());\
    \ dist[from] = T{};\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> q;\n    q.push({T{}, from});\n    while (!q.empty()) {\n        auto\
    \ [t, x] = q.top(); q.pop();\n        for (auto& _e : g[x]) {\n            int\
    \ y = _e.to;\n            if (dist[x] + _e.cost < dist[y]) {\n               \
    \ dist[y] = dist[x] + _e.cost;\n                q.push({dist[y], y});\n      \
    \      }\n        }\n    }\n    return dist;\n}\ntemplate <class T>\nvector<T>\
    \ dijkstra(undirectedgraph<T>& g, int from=0) {\n    vector<T> dist(g.size(),\
    \ numeric_limits<T>::max()); dist[from] = T{};\n    priority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> q;\n    q.push({T{}, from});\n\
    \    while (!q.empty()) {\n        auto [t, x] = q.top(); q.pop();\n        for\
    \ (auto& _e : g[x]) {\n            int y = _e.to;\n            if (dist[x] + _e.cost\
    \ < dist[y]) {\n                dist[y] = dist[x] + _e.cost;\n               \
    \ q.push({dist[y], y});\n            }\n        }\n    }\n    return dist;\n}\n\
    template <class T>\nT dijkstra(directedgraph<T>& g, int from, int to) {\n    return\
    \ dijktra(g, from)[to];\n}\ntemplate <class T>\nT dijkstra(undirectedgraph<T>&\
    \ g, int from, int to) {\n    return dijktra(g, from)[to];\n}\n#line 5 \"verify/aizu-GRL_1_A.test.cpp\"\
    \nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\
    \n}\r\n\r\nvoid solve() {\r\n    int n, m, s; cin >> n >> m >> s;\r\n    directedgraph<ll>\
    \ g(n, true);\r\n    g.read(m, 0);\r\n    vll d = dijkstra(g, s);\r\n    range(i,\
    \ d) {\r\n        if (i == numeric_limits<ll>::max()) {\r\n            cout <<\
    \ \"INF\" << nl;\r\n        } else {\r\n            cout << i << nl;\r\n     \
    \   }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja\"\
    \r\n#include \"template\"\r\n#include \"graphtemplate\"\r\n#include \"dijkstra\"\
    \r\nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--)\
    \ solve();\r\n}\r\n\r\nvoid solve() {\r\n    int n, m, s; cin >> n >> m >> s;\r\
    \n    directedgraph<ll> g(n, true);\r\n    g.read(m, 0);\r\n    vll d = dijkstra(g,\
    \ s);\r\n    range(i, d) {\r\n        if (i == numeric_limits<ll>::max()) {\r\n\
    \            cout << \"INF\" << nl;\r\n        } else {\r\n            cout <<\
    \ i << nl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - util/template.hpp
  - graph/graphtemplate.hpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: verify/aizu-GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2025-04-16 06:46:13+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu-GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu-GRL_1_A.test.cpp
- /verify/verify/aizu-GRL_1_A.test.cpp.html
title: verify/aizu-GRL_1_A.test.cpp
---
