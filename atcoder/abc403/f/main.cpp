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
int main() { IO();
    int T=1;
    // cin >> T;
    while (T--) solve();
}

// 使える数が1のみなのに注意したい
/*
<expr>   ::= <term> | <expr> "+" <term>
<term>   ::= <factor> | <term> "*" <factor>
<factor> ::= <number> | "(" <expr> ")"
<number> ::= "1" | "1" <number> 

*/
// AtCoder さんありがとうございます♡
void solve() {
    int n; cin >> n;
    vi dp_number(n+1, inf), dp_factor(n+1, inf), dp_term(n+1, inf), dp_expr(n+1, inf);
    vi FACTOR(n+1), TERM2(n+1), TERM(n+1), TERM3(n+1), EXPR2(n+1), EXPR(n+1);
    int one = 1;
    int cnt = 1;
    while (one <= n) {
        dp_number[one] = cnt;
        one *= 10;
        one++;
        cnt++;
    }
    rep1(i, n) {
        dp_factor[i] = dp_number[i];
        FACTOR[i] = 0;
        dp_term[i] = dp_factor[i];
        TERM2[i] = 0;
        rep1(j, i) {
            if (i % j == 0) {
                int k = i / j;
                if (chmin(dp_term[i], dp_term[j]+1+dp_factor[k])) {
                    TERM2[i] = 1;
                    TERM[i] = j;
                    TERM3[i] = 0;
                }
                if (chmin(dp_term[i], dp_factor[j]+1+dp_term[k])) {
                    TERM2[i] = 1;
                    TERM[i] = j;
                    TERM3[i] = 1;
                }
            }
        }
        dp_expr[i] = dp_term[i];
        EXPR2[i] = 0;
        rep(j, i) {
            if (chmin(dp_expr[i], dp_expr[j]+1+dp_term[i-j])) {
                EXPR2[i] = 1;
                EXPR[i] = j;
            }
        }
        if (chmin(dp_factor[i], dp_expr[i]+2)) {
            FACTOR[i] = 1;
        }
       if (chmin(dp_term[i], dp_factor[i])) {
            TERM2[i] = 0;
        }
    }
    function<string(int)> restore_expr, restore_term, restore_factor;
    restore_factor = [&](int x) -> str {
        if(FACTOR[x] == 0) return to_string(x);
        return string("(") + restore_expr(x) + ")";
    };
    restore_term = [&](int x) -> str {
        if(TERM2[x] == 0) return restore_factor(x);
        int j = TERM[x];
        int b = x / j;
        if(TERM3[x] == 0) return restore_term(j) + "*" + restore_factor(b);
        else return restore_factor(j) + "*" + restore_term(b);
    };
    restore_expr = [&](int x) -> str {
        if(EXPR2[x] == 0) return restore_term(x);
        int k = EXPR[x];
        return restore_expr(k) + "+" + restore_term(x-k);
    };
    str ans = restore_expr(n);
    cout << ans << nl;
}