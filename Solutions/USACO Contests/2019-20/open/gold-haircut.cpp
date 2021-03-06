#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

#define F			first
#define S			second
#define SZ(x)		int((x).size())
#define ALL(x)		(x).begin(), (x).end()
#define PB			push_back
#define FOR(i,x,y)	for(int i=(x); i<=(y); i++)
#define F0R(i,x)	FOR(i, 0, (x)-1)
#define ROF(i,x,y)	for(int i=(y); i>=(x); i--)
#define R0F(i, x)	ROF(i, 0, (x)-1)
#define EACH(i,x)	for(auto& i : (x))

template<class T> bool ckmin(T& a, const T &b) {
	return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T& a, const T &b) {
	return (b > a ? a = b, 1 : 0); }

void dbg() { cerr << endl; }
template<class T, class ...U> void dbg(const T& t, const U&... u) {
	cerr << ' ' << t; dbg(u...); }
#ifdef LOCAL
	#define DBG(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]:", dbg(__VA_ARGS__)
#else
	#define DBG(...) 0
#endif

void IO(string s = "") {
	cin.tie(0)->sync_with_stdio(0);
	if(SZ(s)) {
		freopen((s+".in").c_str(),"r",stdin); 
		freopen((s+".out").c_str(),"w",stdout);
	}
}

template<class T> struct BIT {
    int N; vector<T> t; BIT() {}
    BIT(int N) : N(N), t(N+1) {}
    void upd(int i, T V) { for(; i<=N; i+=i&(-i)) t[i]+=V; }
    T sum(int i) { T R=0; for(; i; i-=i&(-i)) R+=t[i]; return R; }
    T qry(int l, int r) { return sum(r)-sum(l-1); }
};


int main() {
	IO("haircut");
	
	int n, x;
	BIT<ll> t;
	cin >> n;
	t = BIT<ll>(n+1);
	vector<ll> a(n+1);

	F0R(i,n) {
		cin >> x; ++x;
		a[x] += t.qry(x+1, n+1);
		t.upd(x, 1);
	}
	ll ans = 0;
	F0R(i,n) {
		ans += a[i];
		cout << ans << '\n';
	}

}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACHy
	* template by bqi343
*/