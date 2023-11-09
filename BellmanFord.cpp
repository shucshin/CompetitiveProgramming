// Bellman-Ford Algorithm
#include <bits/stdc++.h>
using namespace std;
using lli = __int128;
using ll = long long; // %lld
using ld = long double; // %0.5Lf
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
const ll MOD = 1e9+7;
const ll INF = 1e18;

struct Edge {ll u, v, w;};
vector<Edge> edges;

vector<vector<pi>> AL;
vi d, p; // d = distance, p = parent

// Bellman-Ford
void bellmanFord(ll s) {
    d[s] = 0;
    for(;;) {
        bool any = 0;
        for(Edge e : edges) {
            ll u = e.u, v = e.v, w = e.w;
            if(d[u] < INF) {
                if(d[v] > d[u]+w) {
                    d[v] = d[u]+w;
                    p[v] = u;
                    any = 1;
                }
            }
        } if(!any) break;
    }
}

// Retrieval of shortest path to s
vi getPath(ll s) {
    if(d[s]==INF) return {};
    vi A;
    for(ll u = s; u != -1; u = p[u]) A.pb(u);
    reverse(all(A));
    return A;
}

// Finding Negative Cycle with Bellman-Ford
vi bellmanFordNC(ll s) {
    ll x, n = AL.size(); d[s] = 0;
    FOR(i,0,n) {
        x = -1;
        for(Edge e : edges) {
            ll u = e.u, v = e.v, w = e.w;
            if(d[v] > d[u]+w) {
                d[v] = d[u]+w;
                p[v] = u;
                x = v;
            }
        }
    }
    if(x==-1) {return {INF};} // no Neg Cycle
    FOR(i,0,n) x = p[x];
    vi cycle;
    for(ll u=x;;u=p[u]) {
        cycle.pb(u);
        if(u==x && cycle.size()>1) break;
    } reverse(all(cycle));
    return cycle;
}

// Shortest Path Faster Algorithm, improvement of Bellman-Ford Algorithm
bool spfa(ll s) {
    ll n = AL.size(); 
    vi c(n,0), inq(n,0);
    queue<ll> q; q.push(s);
    d[s] = 0; inq[s] = 1;
    while(!q.empty()) {
        ll u = q.front(); q.pop(); inq[u] = 0;
        for(auto [v,w] : AL[u]) {
            if(d[v] > d[u]+w) {
                d[v] = d[u]+w;
                p[v] = u;
                if(!inq[v]) {
                    q.push(v); inq[v] = 1; c[v]++;
                    if(c[v] > n) return false; // Neg Cycle
                }
            }
        }
    } return true;
}


// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, u, v, w; // cin >> n >> m;
    n = 8;
    AL.assign(n+1,{}); d.assign(n+1,INF); p.assign(n+1,-1);

    // FOR(_,0,m) { cin >> u >> v >> w; AL[u].pb({v,w}); AL[v].pb({u,w}); }
    AL[1].pb({2,2}); AL[2].pb({1,2});
    AL[1].pb({3,3}); AL[3].pb({1,3});
    AL[2].pb({5,8}); AL[5].pb({2,8});
    AL[2].pb({4,2}); AL[4].pb({2,2});
    AL[4].pb({7,4}); AL[7].pb({4,4});
    AL[3].pb({6,1}); AL[6].pb({3,1});
    AL[5].pb({6,3}); AL[6].pb({5,3});
    AL[5].pb({7,10}); AL[7].pb({5,10});
    AL[6].pb({8,4}); AL[8].pb({6,4});
    AL[7].pb({8,1}); AL[8].pb({7,1});
    AL[1].pb({7,5}); AL[7].pb({1,5});

    /* FOR(_,0,m) {
        cin >> u >> v >> w;
        Edge e; e.u = u; u.v = v; u.w = w;
        edges.pb(e);
    } */
    edges = {{1,2,2}, {2,1,2}, 
             {1,3,3}, {3,1,3}, 
             {2,5,8}, {5,2,8}, 
             {2,4,2}, {4,2,2},
             {4,7,4}, {7,4,4},
             {3,6,1}, {6,3,1},
             {5,6,3}, {6,5,3},
             {5,7,10}, {7,5,10},
             {6,8,4}, {8,6,4},
             {7,8,1}, {8,7,1},
             {1,7,5}, {7,1,5}
    };

    bellmanFord(1);
    // bellmanFordNC(1); for(auto a : negCycle) cout << a << " "; cout << endl;
    // !spfa(1) ? printf("Neg Cycle\n") : printf("No Neg Cycle\n");

    FOR(i,1,9) cout << d[i] << " "; cout << endl;
    FOR(i,1,9) cout << p[i] << " "; cout << endl;

    FOR(i,1,9) {
        vi A = getPath(i);
        cout << "Path: "; for(auto a : A) cout << a << " "; cout << endl;
    }

    return 0;
}
