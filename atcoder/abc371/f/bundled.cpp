#ifdef poe
#define debug(x) cerr<<#x<<": "<<x<<endl
#else
#define debug(x)
// #pragma GCC target("arch=skylake-avx512")
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#endif
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pi=pair<int,int>;
using pll=pair<ll,ll>;
using str=string;
template<class T>using vec=vector<T>;
using vi=vec<int>;using vvi=vec<vi>;using vvvi=vec<vvi>;using vvvvi=vec<vvvi>;using vvvvvi=vec<vvvvi>;
using vll=vec<ll>;using vvll=vec<vll>;using vvvll=vec<vvll>;using vvvvll=vec<vvvll>;using vvvvvll=vec<vvvvll>;
using vpi=vec<pi>;using vvpi=vec<vpi>;using vvvpi=vec<vvpi>;using vvvvpi=vec<vvvpi>;using vvvvvpi=vec<vvvvpi>;
using vpll=vec<pll>;using vvpll=vec<vpll>;using vvvpll=vec<vvpll>;using vvvvpll=vec<vvvpll>;using vvvvvpll=vec<vvvvpll>;
template<class T>using pq=priority_queue<T,vector<T>>;
template<class T>using pqg=priority_queue<T,vector<T>,greater<T>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define per(i,n) for(int i=(int)(n)-1;0<=i;i--)
#define per1(i,n) for(int i=(int)(n);0<i;i--)
#define range(i,x) for(auto&i:x)
#define range2(i,j,x) for(auto&[i,j]:x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define Sort(x) sort((x).begin(),(x).end())
#define troS(x) sort((x).rbegin(),(x).rend())
#define Reverse(x) reverse((x).begin(),(x).end())
#define uniq(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(),(x).end()),(x).end())
#define nextp(x) next_permutation((x).begin(),(x).end())
#define nextc(x,k) next_combination((x).begin(),(x).end(),k)
#define bit(x,i) (((x)>>(i))&1)
#define pf push_front
#define pb push_back
#define df pop_front
#define db pop_back
#define fi first
#define se second
#define elif else if
#define Yes cout<<"Yes"<<'\n'
#define No cout<<"No"<<'\n'
#define YN(x) cout<<((x)?"Yes":"No")<<'\n'
#define O(x) cout<<(x)<<'\n'
template<class S,class T>bool chmin(S&a,T b){if(a>b){a=b;return true;}return false;}
template<class S,class T>bool chmax(S&a,T b){if(a<b){a=b;return true;}return false;}
template<class S,class T,class U>bool ismid(S a,S b,S c){return a<=b&&b<c;}
template<class T>bool next_combination(T l,T r,int k){T m=l+k;if(l==r||l==m||r==m)return false;T t=m;while(l!=t){t--;if(*t<*(r-1)){T d=m;while(*t>=*d)d++;iter_swap(t,d);rotate(t+1,d+1,r);rotate(m,m+(r-d)-1,r);return true;}}rotate(l,m,r);return false;}
template<class T>T Min(T a,T b){return a<b?a:b;}
template<class T,class...Args>T Min(T a,T b,Args...args){return Min(Min(a,b),args...);}
template<class T>T Max(T a,T b){return a>b?a:b;}
template<class T,class...Args>T Max(T a,T b,Args...args){return Max(Max(a,b),args...);}
template<class T>T Sum(T a){return a;}
template<class T,class... Args>T Sum(T a,Args... args){return a+Sum(args...);}
template<class T>T Max(const vector<T>&v){return *max_element(all(v));}
template<class T>T Min(const vector<T>&v){return *min_element(all(v));}
template<class T>T Sum(const vector<T>&v){return accumulate(all(v),T(0));}
template<class S,class T>T Max(const pair<S,T>&p){return max(p.first,p.second);}
template<class S,class T>T Min(const pair<S,T>&p){return min(p.first,p.second);}
template<class S,class T>T Sum(const pair<S,T>&p){return p.first+p.second;}
template<class S,class T>istream&operator>>(istream&s,pair<S,T>&p){s>>p.first>>p.second;return s;}
template<class S,class T>ostream&operator<<(ostream&s,pair<S,T>&p){s<<p.first<<' '<<p.second<<'\n';return s;}
template<class T>istream&operator>>(istream&s,vector<T>&v){for(auto&i:v)s>>i;return s;}
template<class T>ostream&operator<<(ostream&s,vector<T>&v){for(auto&i:v)s<<i<<' ';s<<'\n';return s;}
template<class F>long long bsearch(long long ok,long long ng,F&f){while(abs(ok-ng)>1){long long mid=(ok+ng)/2;if(f(mid))ok=mid;else ng=mid;}return ok;}
const int dxy[5]={0,1,0,-1,0};
const int dx[8]={0,1,0,-1,1,1,-1,-1};
const int dy[8]={1,0,-1,0,1,-1,1,-1};
#define nl '\n'
#define sp ' '
#define inf ((1<<30)-(1<<15))
#define INF (1LL<<61)
#define mod 998244353

void IO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(30);
}

void solve();

struct AngelBeats {
  using i64 = long long;
  static constexpr i64 IINF = numeric_limits<i64>::max() / 2.1;

  struct alignas(32) Node {
    i64 sum = 0, g1 = 0, l1 = 0;
    i64 g2 = -IINF, gc = 1, l2 = IINF, lc = 1, add = 0;
  };

  vector<Node> v;
  i64 n, log;

  AngelBeats() {}
  AngelBeats(int _n) : AngelBeats(vector<i64>(_n)) {}
  AngelBeats(const vector<i64>& vc) {
    n = 1, log = 0;
    while (n < (int)vc.size()) n <<= 1, log++;
    v.resize(2 * n);
    for (i64 i = 0; i < (int)vc.size(); ++i) {
      v[i + n].sum = v[i + n].g1 = v[i + n].l1 = vc[i];
    }
    for (i64 i = n - 1; i; --i) update(i);
  }

  void range_chmin(int l, int r, i64 x) { inner_apply<1>(l, r, x); }
  void range_chmax(int l, int r, i64 x) { inner_apply<2>(l, r, x); }
  void range_add(int l, int r, i64 x) { inner_apply<3>(l, r, x); }
  void range_update(int l, int r, i64 x) { inner_apply<4>(l, r, x); }
  i64 range_min(int l, int r) { return inner_fold<1>(l, r); }
  i64 range_max(int l, int r) { return inner_fold<2>(l, r); }
  i64 range_sum(int l, int r) { return inner_fold<3>(l, r); }

 private:
  void update(int k) {
    Node& p = v[k];
    Node& l = v[k * 2 + 0];
    Node& r = v[k * 2 + 1];

    p.sum = l.sum + r.sum;

    if (l.g1 == r.g1) {
      p.g1 = l.g1;
      p.g2 = max(l.g2, r.g2);
      p.gc = l.gc + r.gc;
    } else {
      bool f = l.g1 > r.g1;
      p.g1 = f ? l.g1 : r.g1;
      p.gc = f ? l.gc : r.gc;
      p.g2 = max(f ? r.g1 : l.g1, f ? l.g2 : r.g2);
    }

    if (l.l1 == r.l1) {
      p.l1 = l.l1;
      p.l2 = min(l.l2, r.l2);
      p.lc = l.lc + r.lc;
    } else {
      bool f = l.l1 < r.l1;
      p.l1 = f ? l.l1 : r.l1;
      p.lc = f ? l.lc : r.lc;
      p.l2 = min(f ? r.l1 : l.l1, f ? l.l2 : r.l2);
    }
  }

  void push_add(int k, i64 x) {
    Node& p = v[k];
    p.sum += x << (log + __builtin_clz(k) - 31);
    p.g1 += x;
    p.l1 += x;
    if (p.g2 != -IINF) p.g2 += x;
    if (p.l2 != IINF) p.l2 += x;
    p.add += x;
  }
  void push_min(int k, i64 x) {
    Node& p = v[k];
    p.sum += (x - p.g1) * p.gc;
    if (p.l1 == p.g1) p.l1 = x;
    if (p.l2 == p.g1) p.l2 = x;
    p.g1 = x;
  }
  void push_max(int k, i64 x) {
    Node& p = v[k];
    p.sum += (x - p.l1) * p.lc;
    if (p.g1 == p.l1) p.g1 = x;
    if (p.g2 == p.l1) p.g2 = x;
    p.l1 = x;
  }
  void push(int k) {
    Node& p = v[k];
    if (p.add != 0) {
      push_add(k * 2 + 0, p.add);
      push_add(k * 2 + 1, p.add);
      p.add = 0;
    }
    if (p.g1 < v[k * 2 + 0].g1) push_min(k * 2 + 0, p.g1);
    if (p.l1 > v[k * 2 + 0].l1) push_max(k * 2 + 0, p.l1);

    if (p.g1 < v[k * 2 + 1].g1) push_min(k * 2 + 1, p.g1);
    if (p.l1 > v[k * 2 + 1].l1) push_max(k * 2 + 1, p.l1);
  }

  void subtree_chmin(int k, i64 x) {
    if (v[k].g1 <= x) return;
    if (v[k].g2 < x) {
      push_min(k, x);
      return;
    }
    push(k);
    subtree_chmin(k * 2 + 0, x);
    subtree_chmin(k * 2 + 1, x);
    update(k);
  }

  void subtree_chmax(int k, i64 x) {
    if (x <= v[k].l1) return;
    if (x < v[k].l2) {
      push_max(k, x);
      return;
    }
    push(k);
    subtree_chmax(k * 2 + 0, x);
    subtree_chmax(k * 2 + 1, x);
    update(k);
  }

  template <int cmd>
  inline void _apply(int k, i64 x) {
    if constexpr (cmd == 1) subtree_chmin(k, x);
    if constexpr (cmd == 2) subtree_chmax(k, x);
    if constexpr (cmd == 3) push_add(k, x);
    if constexpr (cmd == 4) subtree_chmin(k, x), subtree_chmax(k, x);
  }

  template <int cmd>
  void inner_apply(int l, int r, i64 x) {
    if (l == r) return;
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) _apply<cmd>(l++, x);
        if (r & 1) _apply<cmd>(--r, x);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template <int cmd>
  inline i64 e() {
    if constexpr (cmd == 1) return IINF;
    if constexpr (cmd == 2) return -IINF;
    return 0;
  }

  template <int cmd>
  inline void op(i64& a, const Node& b) {
    if constexpr (cmd == 1) a = min(a, b.l1);
    if constexpr (cmd == 2) a = max(a, b.g1);
    if constexpr (cmd == 3) a += b.sum;
  }

  template <int cmd>
  i64 inner_fold(int l, int r) {
    if (l == r) return e<cmd>();
    l += n, r += n;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
    i64 lx = e<cmd>(), rx = e<cmd>();
    while (l < r) {
      if (l & 1) op<cmd>(lx, v[l++]);
      if (r & 1) op<cmd>(rx, v[--r]);
      l >>= 1;
      r >>= 1;
    }
    if constexpr (cmd == 1) lx = min(lx, rx);
    if constexpr (cmd == 2) lx = max(lx, rx);
    if constexpr (cmd == 3) lx += rx;
    return lx;
  }
};

/**
 * @brief Range Chmin Chmax Add Update Range Min Max Sum Segment Tree Beats!
 * @docs docs/segment-tree/segment-tree-beats.md
 */
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}
void solve() {
    int n; cin >> n;
    vll a(n); cin >> a;
    rep(i, n) {
        a[i] -= i;
    }
    AngelBeats seg(a);
    int q; cin >> q;
    ll ans = 0;
    while (q--) {
        ll x, y; cin >> x >> y; x--;
        ll z = seg.range_max(x, x+1);
        ll l, r;
        if (y <= z) {
            int ll=0, rr=x+1;
            while (1 < rr - ll) {
                int mid = ll + (rr - ll) / 2;
                if (y <= seg.range_min(mid, x+1)) {
                    rr = mid;
                } else {
                    ll = mid;
                }
            }
            l = ll, r = x+1;
        }
        else {
            int ll=x, rr = n+1;
            while (1 < rr - ll) {
                int mid = ll + (rr - ll) / 2;
                if (seg.range_max(x, mid) <= y) {
                    ll = mid;
                } else {
                    rr = mid;
                }
            }
            l = x, r = ll;
        }
        ll u = y * (r - l);
        ll t = seg.range_sum(l, r) + r * (r-1) / 2 - l * (l - 1) / 2 ;
        //cout << l << sp << r << sp << u << sp << t << nl;
        ans += abs(u - t);
        seg.range_update(l, r, y-x);
    }
    cout << ans << nl;
}
