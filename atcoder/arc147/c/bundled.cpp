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
#define ismid(a,b,c) ((a)<=(b)&&(b)<(c))
template<class S,class T>bool chmin(S&a,T b){if(a>b){a=b;return true;}return false;}
template<class S,class T>bool chmax(S&a,T b){if(a<b){a=b;return true;}return false;}
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
using namespace std;

// floor(sqrt(n)) を返す
long long isqrt(long long n) {
    assert(0 <= n);
    long long re = sqrt(n);
    while ((re + 1) * (re + 1) <= n) re++;
    while (n < re * re) re--;
    return re;
}
using namespace std;
template<class T>
struct BIT {
    int _n;
    vector<T> data;
    // BIT を0-indexed で構築する O(n)
    BIT(int n) : _n(n), data(_n) {}
    // p 番目の値にx を加算する O(log n)
    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p-1] += x;
            p += p & -p;
        }
    }
    // p 番目の値をx にする O(log n)
    void set(int p, T x) {
        add(p, x - get(p));
    }
    // [0, r) の総和を求める O(log n)
    T sum(int r) {
        assert(0 <= r &&  r <= _n);
        T re = T{};
        while (0 < r) {
            re += data[r-1];
            r -= r & -r;
        }
        return re;
    }
    // [l, r) の総和を求める O(log n)
    T sum(int l, int r) {
        assert(l <= r);
        return sum(r) - sum(l);
    }
    // p 番目の値を取得する O(log n)
    T get(int p) {
        return sum(p+1) - sum(p);
    }
    // p 番目の値を取得する O(log n)
    T operator[](int p) {
        return get(p);
    }
    // 全体の総和を取得する O(log n)
    T all_sum() {
        return sum(_n);
    }
    // [l, r) にx を加算する 一点取得はsum(p) で行う 区間和クエリができなくなるので注意 O(log n)
    void imos(int l, int r, T x) {
        add(l, x);
        if (r < _n) add(r, T{}-x);
    }
    // x <= sum(p) となる最小のp を求める O(log n)
    int lower_bound(T x) {
        if (x <= 0) return 0;
        int re = 0, t = 1;
        while (t < _n) t <<= 1;
        while (t) {
            if (re + t < _n && data[re+t] < x) {
                x -= data[re+t];
                re += t;
                t >>= 1;
            }
        }
        return re;
    }
    // x < sum(p) となる最小のp を求める O(log n)
    int upper_bound(T x) {
        if (x < 0) return 0;
        int re = 0, t = 1;
        while (t < _n) t <<= 1;
        while (t) {
            if (re + t < _n && data[re+t] <= x) {
                x -= data[re+t];
                re += t;
                t >>= 1;
            }
        }
        return re;
    }
};

int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    const int m = 2800000;
    BIT<int> seg(m);
    vector<char> cnt(m+1, 1);
    rep(i, m) seg.add(i, 1);
    unordered_set<int> visited;
    int q; cin >> q;
    while(q--){
        int a, k; cin >> a >> k;
        if(visited.insert(a).second && a <= m){
            for(int x=a; x <= m; x+=a){
                int p = x - 1;
                if(cnt[p]) {
                    cnt[p] = 0;
                    seg.add(p-1, -1);
                }
            }
        }
        int p = seg.lower_bound(k);
        cout << p + 1 << nl;
    }
}
