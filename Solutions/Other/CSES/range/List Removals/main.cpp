#include <bits/stdc++.h>
using namespace std;

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

    /* Output */
    template<class A> void pr(A x) { cout << ts(x); }
    template<class H, class... T> void pr(const H& h, const T&... t) {
        pr(h); pr(t...); }
    void pl() { cout << "\n"; }
}
using namespace IO;

/* ============================ */

struct segTree {

	int n;
	vector<int> st;

	segTree(int n_) {
		n = n_;
		st.assign(4*n, 0);
		build(1, 1, n);
	}

	int left(int i) { return i*2; }
	int right(int i) { return i*2+1; }

	void build(int id, int L, int R) {
		if (L == R) {
			st[id] = L-R+1;
			return;
		}
		build(left(id), L, (L+R)/2);
		build(right(id), (L+R)/2+1, R);
		st[id] = st[left(id)] + st[right(id)];
	}

	void update(int id, int L, int R, int P, int value) {
		if (P > R || P < L) return;
		if (P >= L && P <= R) st[id] += value;
		if (L == R) return;
		update(left(id), L, (R+L)/2, P, value);
		update(right(id), (R+L)/2+1, R, P, value);
	}

	void update(int P, int value) {
		update(1, 1, n, P, value);
	}

	int get(int id, int L, int R, int X) {
        st[id]--;
        if (L==R) return L;
        if (st[left(id)] >= X) return get(left(id), L, (R+L)/2, X);
        else return get(right(id), (R+L)/2+1, R, X-st[left(id)]);
	}

	int get(int X) {
		return get(1, 1, n, X);
	}
};



int main() {
    setIO("");

    int n; re(n);
    vi a(n+1), b(n+1);
    for1(i,n) re(a[i]);
    for1(i,n) re(b[i]);
    segTree t(n);
    for1(i,n) {
        cout << a[t.get(b[i])] <<" ";
    }
}