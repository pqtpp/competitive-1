---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphtemplate.hpp
    title: graph/graphtemplate.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/yosupo-scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
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
    \ id;\n};\ntemplate<class T = int>\nusing edges = vector<edge<T>>;\ntemplate <class\
    \ T = int, bool directed = false, bool weighted = false>\nstruct graph {\n   \
    \ bool isdirected, isweighted;\n    edges<T> _edges;\n    vector<edges<T>> data;\n\
    \    T sumcost;\n    graph(int n) : isdirected(directed), isweighted(weighted),\
    \ data(n), sumcost(T{}) {}\n    void add_edge(int from, int to, T cost = 1, int\
    \ id = -1) {\n        if (id == -1) id = _edges.size();\n        data[from].push_back(edge<T>(from,\
    \ to, cost, id));\n        _edges.push_back(edge<T>(from, to, cost, id));\n  \
    \      if (!isdirected) {\n            data[to].push_back(edge<T>(to, from, cost,\
    \ id));\n        }\n        sumcost += cost;\n    }\n    void add_edge(edge<T>\
    \ _e) {\n        add_edge(_e.from, _e.to, _e.cost, _e.id);\n    }\n    void read(int\
    \ m, int indexed = 1) {\n        for (int i=0; i<m; i++) {\n            int from,\
    \ to;\n            T cost = 1;\n            cin >> from >> to;\n            if\
    \ (isweighted) cin >> cost;\n            add_edge(from - indexed, to - indexed,\
    \ cost);\n        }\n    }\n    int size() {\n        return data.size();\n  \
    \  }\n    edges<T> operator[](int k) {\n        return data[k];\n    }\n};\n#line\
    \ 4 \"graph/scc.hpp\"\nusing namespace std;\ntemplate<class T = int, bool directed\
    \ = true, bool weighted = false>\nvector<vector<int>> scc(graph<T, directed, weighted>&\
    \ g) {\n    int n = g.size();\n    vector<int> low(n), num(n, -1), stack;\n  \
    \  vector<bool> onStack(n);\n    vector<vector<int>> re;\n    auto dfs = [&](auto&\
    \ self, int x) -> void {\n        low[x] = num[x] = stack.size();\n        stack.push_back(x);\n\
    \        onStack[x] = true;\n        for (auto& _e : g[x]) {\n            int\
    \ y = _e.to;\n            if (num[y] == -1) {\n                self(self, y);\n\
    \                low[x] = min(low[x], low[y]);\n            } else if (onStack[y])\
    \ {\n                low[x] = min(low[x], num[y]);\n            }\n        }\n\
    \        if (low[x] == num[x]) {\n            vector<int> component;\n       \
    \     while (true) {\n                int y = stack.back(); stack.pop_back();\
    \ onStack[y] = false;\n                component.push_back(y);\n             \
    \   if (y == x) break;\n            }\n            re.push_back(component);\n\
    \        }\n    };\n    for (int i=0; i<n; i++) if (num[i] == -1) dfs(dfs, i);\n\
    \    reverse(re.begin(), re.end());\n    return re;\n}\n#line 5 \"verify/yosupo-scc.test.cpp\"\
    \nint main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\
    \n}\r\n\r\nvoid solve() {\r\n    int n, m; cin >> n >> m;\r\n    graph<int, true,\
    \ false> g(n);\r\n    g.read(m, 0);\r\n    vvi h = scc(g);\r\n    cout << h.size()\
    \ << nl;\r\n    range(i, h) {\r\n        cout << i.size() << sp;\r\n        cout\
    \ << i;\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n#include \"template\"\
    \r\n#include \"scc\"\r\n#include \"graphtemplate\"\r\nint main() { IO();\r\n \
    \   int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nvoid\
    \ solve() {\r\n    int n, m; cin >> n >> m;\r\n    graph<int, true, false> g(n);\r\
    \n    g.read(m, 0);\r\n    vvi h = scc(g);\r\n    cout << h.size() << nl;\r\n\
    \    range(i, h) {\r\n        cout << i.size() << sp;\r\n        cout << i;\r\n\
    \    }\r\n}"
  dependsOn:
  - util/template.hpp
  - graph/scc.hpp
  - graph/graphtemplate.hpp
  isVerificationFile: true
  path: verify/yosupo-scc.test.cpp
  requiredBy: []
  timestamp: '2025-04-22 03:33:46+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-scc.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-scc.test.cpp
- /verify/verify/yosupo-scc.test.cpp.html
title: verify/yosupo-scc.test.cpp
---
