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
long long modint_MOD = 998244353;
// mod の値を変更する(デフォルトは998244353)
void setmod(long long x) { modint_MOD = x; }
struct mint {
    long long val;
    mint(long long x=0) {
        val=(x%modint_MOD+modint_MOD)%modint_MOD;
    }
    mint& operator+=(const mint& a) { val = (val + a.val) % modint_MOD; return *this; }
    mint& operator-=(const mint& a) { val = (val - a.val + modint_MOD) % modint_MOD; return *this; }
    mint& operator*=(const mint& a) { val = val * a.val % modint_MOD ; return *this; }
    mint& operator/=(const mint& a) { return *this *= a.inv(); }
    mint operator+(const mint& a) const { return mint(*this) += a; }
    mint operator-(const mint& a) const { return mint(*this) -= a; }
    mint operator*(const mint& a) const { return mint(*this) *= a; }
    mint operator/(const mint& a) const { return mint(*this) /= a; }
    bool operator==(const mint& a) const { return val == a.val; }
    bool operator!=(const mint& a) const { return val != a.val; }
    mint& operator+=(int a) { return *this += mint(a); }
    mint& operator-=(int a) { return *this -= mint(a); }
    mint& operator*=(int a) { return *this *= mint(a); }
    mint& operator/=(int a) { return *this /= mint(a); }
    mint operator+(int a) const { return mint(*this) += a; }
    mint operator-(int a) const { return mint(*this) -= a; }
    mint operator*(int a) const { return mint(*this) *= a; }
    mint operator/(int a) const { return mint(*this) /= a; }
    bool operator==(int a) const { return val == mint(a).val; }
    bool operator!=(int a) const { return val != mint(a).val; }
    friend mint operator+(int a,const mint& b) { return mint(a) + b; }
    friend mint operator-(int a,const mint& b) { return mint(a) - b; }
    friend mint operator*(int a,const mint& b) { return mint(a) * b; }
    friend mint operator/(int a,const mint& b) { return mint(a) / b; }
    friend bool operator==(int a, const mint& b) { return mint(a) == b; }
    friend bool operator!=(int a, const mint& b) { return mint(a) != b; }
    mint& operator++() { return *this += 1; }
    mint operator++(int) { mint r = *this; *this += 1; return r; }
    mint& operator--() { return *this -= 1; }
    mint operator--(int) { mint r = *this; *this -= 1; return r; }
    // modpow を計算する。計算量O(log mod)
    mint pow(long long n) const {
        if (n != 0) n = ((n-2) % (modint_MOD-1) + modint_MOD) % (modint_MOD-1) + 1;
        mint r = 1, a = *this;
        while (n) {
            if (n & 1) r *= a;
            a *= a;
            n >>= 1;
        }
        return r;
    }
    mint inv() const { return pow(-1); }
    friend ostream& operator<<(ostream&s, const mint& a) { return s << a.val; }
    friend istream& operator>>(istream&s, mint& a) { long long x; s >> x; a = mint(x); return s; }
};
vector<mint>fac, ifac;
// n までの階乗を前計算する。O(n)
void buildfac(int n) {
    fac.resize(n + 1);
    ifac.resize(n + 1);
    fac[0] = 1;
    for (int i=1; i<=n; i++) fac[i] = fac[i-1] * i;
    ifac[n] = mint(1) / fac[n];
    for (int i=n; 0<i; i--) ifac[i-1] = ifac[i] * i;
}
// nCk を求める。buildfacの呼び出しが必須。O(1)
mint comb(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[k] * ifac[n-k] : 0; }
// nPk を求める。buildfacの呼び出しが必須。O(1)
mint perm(int n,int k) { return (0 <= k && k <= n ) ? fac[n] * ifac[n-k] : 0; }
using namespace std;
// Mo's algorithm
struct Mo {
    int n;
    vector<pair<int, int>> queries;
    explicit Mo(int n) : n(n) {}
    // クエリを追加する
    void add(int l, int r) {
        queries.push_back({l, r});
    }
    void add(vector<pair<int, int>>& qs) {
        for(auto& q : qs) {
            queries.push_back(q);
        }
    }
    long long hilbert_order(int x, int y, int p=20, int rotate = 0) {
        long long d = 0;
        for (int s=1<<(p-1); 0<s; s>>=1) {
            int rx = 0 < (x & s);
            int ry = 0 < (y & s);
            int r = (rx << 1) | ry;
            r = (r + rotate) & 3;
            d = (d << 2) | r;
            const int rd[4] = {3, 0, 0, 1};
            rotate = (rotate + rd[r]) & 3;
        }
        return d;
    }
    // クエリを実行する O((n+q) sqrt(n))
    template <class AL, class AR, class EL, class ER, class OUT>
    void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const OUT &out) {
        int q = queries.size();
        vector<int> ord(q);
        iota(begin(ord), end(ord), 0);
        vector<long long> hs(q);
        for (int i=0; i<q; i++) {
            hs[i] = hilbert_order(queries[i].first, queries[i].second);
        }
        sort(begin(ord), end(ord), [&](int a, int b) {
            return hs[a] < hs[b];
        });
        int l = 0, r = 0;
        for(auto idx : ord) {
            while(l > queries[idx].first) add_left(--l);
            while(r < queries[idx].second) add_right(r++);
            while(l < queries[idx].first) erase_left(l++);
            while(r > queries[idx].second) erase_right(--r);
            out(idx);
        }
    }
    // クエリを実行する O((n+q) sqrt(n))
    template <class A, class E, class OUT>
    void build(const A &add, const E &erase, const OUT &out) {
        build(add, add, erase, erase, out);
    }
};
using namespace std;
template <class S, auto op, auto e, class F, auto mapping, auto mapping2>
struct sqrttree {
    int n, bsize, m;
    vector<S> data, block;
    sqrttree() = default;
    sqrttree(int n) : sqrttree(vector<S>(n, e())) {}
    sqrttree(vector<S> v) {
        n = v.size();
        bsize = sqrt(n) + 1;
        m = bsize * bsize;
        data.reserve(m);
        block.reserve(bsize);
        for (int i=0; i<bsize; i++) {
            block[i] = e();
            for (int j=0; j<bsize; j++) {
                int k = i * bsize + j;
                if (k < n) {
                    data[k] = v[k];
                } else {
                    data[k] = e();
                }
                block[i] = op(block[i], data[k]);
            }
        }
    }
    void apply(int i, F f) {
        assert(0<=i && i<n);
        data[i] = mapping(f, data[i]);
        block[i/bsize] = mapping2(f, block[i/bsize]);
    }
    S get(int i) {
        assert(0 <= i && i < n);
        return data[i];
    }
    S operator[](int i) {
        return get(i);
    }
    S prod(int l, int r) {
        assert(0<=l && l<=r && r<=n);
        S re = e();
        for (int i=0; i<bsize; i++) {
            if (r<=i*bsize || (i+1)*bsize<=l) continue;
            if (l<=i*bsize && (i+1)*bsize<=r) re = op(re, block[i]);
            else {
                for (int j=0; j<bsize; j++) {
                    int k = i * bsize + j;
                    if (l<=k && k<r) {
                        re = op(re, data[k]);
                    }
                }
            }
        }
        return re;
    }
};

int main() { IO();
    buildfac(300000);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); cin >> a; rep(i, n) a[i]--;
    Mo mo(n);
    vi queries(q), ans(q);
    rep(i, q) {
        int x, y, z; cin >> x >> y >> z;
        queries[i] = z-1;
        mo.add(x-1, y);
    }
    sqrttree<int,[](int a,int b){return a+b;},[](){return 0;},int,[](int a,int b){return a+b;},[](int a,int b){return a+b;}> seg1(n);
    auto op = [](ll a, ll b) -> ll {return a * b % mod;};
    auto e = []() -> ll {return 1;};
    sqrttree<ll,op,e,ll,op,op> seg2(n);
    vll inve(n+1); rep1(i, n) inve[i] = mint(i).inv().val;
    auto add = [&](int x) {
        seg1.apply(a[x], 1);
        seg2.apply(a[x], seg1[a[x]]);
    };
    auto erase = [&](int x) {
        seg2.apply(a[x], inve[seg1[a[x]]]);
        seg1.apply(a[x], -1);
    };
    auto out = [&](int x) {
        ans[x] = (fac[seg1.prod(0, queries[x])] / seg2.prod(0, queries[x])).val;
    };
    mo.build(add, erase, out);
    range(i, ans) cout << i << nl;
}

