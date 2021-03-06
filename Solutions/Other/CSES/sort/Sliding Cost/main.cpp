#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef string str;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<str> vs;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define pb push_back

#define for0(a,n) for(int a = 0; a < (n); ++a)
#define for1(a,n) for(int a = 1; a <= (n); ++a)
#define rof0(a,n) for(int a = (n-1); a >= 0; --a)
#define rof1(a,n) for(int a = (n); a >= 1; --a)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18;
const double PI = acos(-1);
const int X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};

/* Source: Benq (https://github.com/bqi343/USACO) [Modified] */

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

namespace IO {
    void setIO(string PROB = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(PROB)) {
            freopen((PROB+".in").c_str(),"r",stdin);
            freopen((PROB+".out").c_str(),"w",stdout);
        }
    }

    /* Input */
    template<class A, class B> void re(pair<A,B>& p);
    template<class A> void re(vector<A>& v);
    template<class T> void re(T& x) { cin >> x; }
    template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
    template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
    template<class A> void re(vector<A>& x) { trav(a,x) re(a); }

    /* To String */
    str ts(int i) { return to_string(i); }
    str ts(bool b) { return b ? "true" : "false"; }
    str ts(char c) { str s=""; s+=c; return s; }
    str ts(str s) { return s; }
    str ts(const char* s) { return (str)s; }
    template<class T> str ts(vector<T> v) {
        bool fst=1; str res="{";
        trav(a, v) {
            if (!fst) res += ", ";
            fst = 0; res += ts(a);
        }
        res+="}"; return res;
    }

    /* Output */
    template<class A> void pr(A x) { cout << ts(x); }
    template<class H, class... T> void pr(const H& h, const T&... t) {
        pr(h); pr(t...); }
    void pl() { cout << "\n"; }
}
using namespace IO;

/* ============================ */
using Node = pair<ll, int>;
struct BIT {

	int n;
	vector<Node> t;

	BIT(int n_) {
		n = n_;
		t.assign(n+1, {0,0});
	}

	void update(int i, Node value) {
		for (; i<=n; i+=i&(-i)) t[i].f+=value.f, t[i].s+=value.s;
	}

	Node get(int i) {
        Node res = {0,0};
		for(; i>0; i-=i&(-i)) res.f+=t[i].f, res.s+=t[i].s;
		return res;
	}

};

Tree<pii> T;
BIT bit(MX);
map<int,int> M;
ll calc() {
    ll m=(*(T.find_by_order((T.size()-1)/2))).f;
    Node q1=bit.get(M[m]-1);
    Node q2=bit.get(MX);
    Node q3=bit.get(M[m]); q2.f-=q3.f, q2.s-=q3.s;
    ll a1=abs(m*q1.s - q1.f);
    ll a2=abs(m*q2.s - q2.f);
    // cout<<"m="<<m<<" | " <<"("<<q1.f<<","<<q1.s<<")+("<<q2.f<<","<<q2.s<<") => "<<a1<<"+"<<a2<<"\n";
    return (a1+a2);
}

int main() {
    setIO("");

    int n,k; re(n,k);
    vi a(n); re(a);

    trav(_,a) M[_]=1;
    int cnt=1; trav(_,M) _.s=cnt++;

    for0(i,k) T.insert({a[i],i}), bit.update(M[a[i]], {a[i],1});
     cout << calc()<<" "; // calc();
    for(int i=k; i<n; i++) {
        T.erase(T.lower_bound({a[i-k], i-k}));
        bit.update(M[a[i-k]], {-a[i-k],-1});
        T.insert({a[i], i});
        bit.update(M[a[i]], {a[i],1});
        cout << calc()<<" "; // calc();
    }

}