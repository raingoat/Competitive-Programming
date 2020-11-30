#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using str = string;

using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vii = vector<pii>;
template <class T> using v = vector<T>;

#define mp make_pair
#define f first
#define s second

#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define lb lower_bound
#define ub upper_bound

#define F0R(i,a) for(int i=0; i<(a); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define R0F(i,a) for(int i=(a)-1; i>=0; i--)
#define ROF(i,a,b) for(int i=(b); i>=a; i--)
#define trav(a,x) for (auto& a: x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int MX = 2e5+5;
const ld PI = acos(-1);
const int X[] = {1, 0, -1, 0},
          Y[] = {0, 1, 0, -1};

/* ============================ */

void setIO(str PROB = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(PROB)) {
        freopen((PROB+".in").c_str(), "r", stdin);
        freopen((PROB+".out").c_str(), "w", stdout);
    }
}

/* ============================ */

int main() {
    setIO("");

    int n,m,k; cin >> n >> m >> k;
    vector<pii> adj[n+1]; int cnt[n+1];
    F0R(i,m) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    FOR(i,1,n) cnt[i]=0;
    priority_queue<pll, vector<pll>, greater<pll> > PQ;
    PQ.push({0,1});
    while(!PQ.empty()) {
        ll d=PQ.top().f, i=PQ.top().s; PQ.pop();
        if (cnt[i]==k) continue;
        cnt[i]++;
        if (i == n) {
            cout << d <<" ";
            if (cnt[n]==k) break;
        }
        trav(e, adj[i]) PQ.push({d+e.s, e.f});
    }
}