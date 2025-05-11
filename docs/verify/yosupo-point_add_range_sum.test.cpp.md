---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/sqrttree.hpp
    title: structure/sqrttree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo-point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\n#line 2 \"util/template.hpp\"\
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
    }\n\nvoid solve();\n#line 3 \"structure/sqrttree.hpp\"\nusing namespace std;\n\
    \n// S: \u5024\u578B, F: \u4F5C\u7528\u7D20\u578B\n// op: \u30E2\u30CE\u30A4\u30C9\
    \u6F14\u7B97 (S x S -> S)\n// e: \u5358\u4F4D\u5143 (S)\n// mapping: \u4F5C\u7528\
    \ (F x S x int -> S)\n// composition: \u4F5C\u7528\u7D20\u5408\u6210 (F x F ->\
    \ F)\n// id: \u6052\u7B49\u5199\u50CF (F)\n\ntemplate <class S,\n          S (*op)(S,\
    \ S),\n          S (*e)(),\n          class F,\n          S (*mapping)(F, S, int),\n\
    \          F (*composition)(F, F),\n          F (*id)()>\nstruct SqrtTree {\n\
    \    struct Block {\n        int l, r;\n        vector<S> data;\n        S sum;\n\
    \        F lazy;\n        bool pending;\n\n        Block() = default;\n\n    \
    \    Block(const vector<S>& base, int l_, int r_)\n            : l(l_), r(r_),\
    \ data(base.begin() + l_, base.begin() + r_),\n              sum(e()), lazy(id()),\
    \ pending(false) {\n            rebuild();\n        }\n\n        void apply(F\
    \ f) {\n            lazy = composition(f, lazy);\n            pending = true;\n\
    \        }\n\n        void push() {\n            if (!pending) return;\n     \
    \       for (int i = 0; i < r - l; ++i)\n                data[i] = mapping(lazy,\
    \ data[i], 1);\n            lazy = id();\n            pending = false;\n     \
    \       rebuild();\n        }\n\n        void rebuild() {\n            sum = e();\n\
    \            for (auto& x : data) sum = op(sum, x);\n        }\n\n        void\
    \ update(int ql, int qr, F f) {\n            if (qr <= l || r <= ql) return;\n\
    \            if (ql <= l && r <= qr) {\n                apply(f);\n          \
    \      return;\n            }\n            push();\n            for (int i = max(l,\
    \ ql); i < min(r, qr); ++i)\n                data[i - l] = mapping(f, data[i -\
    \ l], 1);\n            rebuild();\n        }\n\n        S query(int ql, int qr)\
    \ {\n            if (qr <= l || r <= ql) return e();\n            if (ql <= l\
    \ && r <= qr) return pending ? mapping(lazy, sum, r - l) : sum;\n            push();\n\
    \            S res = e();\n            for (int i = max(l, ql); i < min(r, qr);\
    \ ++i)\n                res = op(res, data[i - l]);\n            return res;\n\
    \        }\n    };\n\n    int n, bsize;\n    vector<Block> blocks;\n\n    SqrtTree()\
    \ = default;\n\n    SqrtTree(const vector<S>& base) {\n        n = base.size();\n\
    \        bsize = sqrt(n) + 1;\n        for (int i = 0; i < n; i += bsize)\n  \
    \          blocks.emplace_back(base, i, min(n, i + bsize));\n    }\n\n    void\
    \ update(int l, int r, F f) {\n        for (auto& b : blocks)\n            b.update(l,\
    \ r, f);\n    }\n\n    S query(int l, int r) {\n        S res = e();\n       \
    \ for (auto& b : blocks)\n            res = op(res, b.query(l, r));\n        return\
    \ res;\n    }\n};\n#line 4 \"verify/yosupo-point_add_range_sum.test.cpp\"\n\r\n\
    int main() { IO();\r\n    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\
    \n}\r\n\r\nusing S2 = long long;\r\nS2 op2(S2 a, S2 b) { return a + b; }\r\nS2\
    \ e2() { return 0LL; }\r\nusing F2 = long long;\r\nS2 mapping2(F2 f, S2 x, int\
    \ len) { return x + f * len; }\r\nF2 composition2(F2 f, F2 g) { return f + g;\
    \ }\r\nF2 id2() { return 0LL; }\r\n\r\nvoid solve() {\r\n    int n, q; cin >>\
    \ n >> q;\r\n    vec<S2> a(n); cin >> a;\r\n    SqrtTree<S2, op2, e2, F2, mapping2,\
    \ composition2, id2> seg(a);\r\n    while (q--) {\r\n        int x, y, z; cin\
    \ >> x >> y >> z;\r\n        if (x == 0) {\r\n            seg.update(y, y+1, z);\r\
    \n        } else {\r\n            cout << seg.query(y, z) << nl;\r\n        }\r\
    \n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n#include \"template\"\r\n#include \"sqrttree\"\r\n\r\nint main() { IO();\r\n\
    \    int T=1;\r\n    // cin >> T;\r\n    while (T--) solve();\r\n}\r\n\r\nusing\
    \ S2 = long long;\r\nS2 op2(S2 a, S2 b) { return a + b; }\r\nS2 e2() { return\
    \ 0LL; }\r\nusing F2 = long long;\r\nS2 mapping2(F2 f, S2 x, int len) { return\
    \ x + f * len; }\r\nF2 composition2(F2 f, F2 g) { return f + g; }\r\nF2 id2()\
    \ { return 0LL; }\r\n\r\nvoid solve() {\r\n    int n, q; cin >> n >> q;\r\n  \
    \  vec<S2> a(n); cin >> a;\r\n    SqrtTree<S2, op2, e2, F2, mapping2, composition2,\
    \ id2> seg(a);\r\n    while (q--) {\r\n        int x, y, z; cin >> x >> y >> z;\r\
    \n        if (x == 0) {\r\n            seg.update(y, y+1, z);\r\n        } else\
    \ {\r\n            cout << seg.query(y, z) << nl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - util/template.hpp
  - structure/sqrttree.hpp
  isVerificationFile: true
  path: verify/yosupo-point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-05-11 18:58:47+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-point_add_range_sum.test.cpp
- /verify/verify/yosupo-point_add_range_sum.test.cpp.html
title: verify/yosupo-point_add_range_sum.test.cpp
---
