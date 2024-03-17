// Dijkstra Algorithm
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
vi d, p, M; // d = distance, p = parent

// Dijkstra with Set (Red-Black Trees), supports removing elems
void dijkstraSet(ll s, ll x=-1) { // Exclude node x
    set<pi> q;
    q.insert({0,s}); d[s] = 0;
    while(!q.empty()) {
        ll u = q.begin()->snd; q.erase(q.begin());
        if(u == x) continue;
        for(auto a : AL[u]) {
            ll v = a.fst, w = a.snd;
            if(d[u] + w < d[v]) {
                q.erase({d[v],v});
                d[v] = d[u]+w;
                p[v] = u;
                q.insert({d[v],v});
            }
        }
    }
}

// Dijkstra with priority_queue (Heaps), vertex can appear multiple times with diff dst
void dijkstraPQ(ll s, ll x=-1) { // Exclude node x
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0,s}); d[s] = 0;
    while(!pq.empty()) {
        ll u = pq.top().snd, d_u = pq.top().fst; pq.pop();
        if(u == x || d_u != d[u]) continue;
        for(auto a : AL[u]) {
            ll v = a.fst, w = a.snd;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                p[v] = u;
                pq.push({d[v],v});
            }
        }
    }
}

// Gets path from initial node to node u
vi getPath(ll u) {
    vi A = {u};
    while(p[u] != -1) {
        A.pb(p[u]);
        u = p[u];
    } reverse(all(A));
    return A;
}

// Weights of edges 0 or 1, O(|E|)
void bfs01(ll s) {
    deque<ll> q; d[s] = 0; 
    q.push_front(s);
    while(!q.empty()) {
        ll u = q.front(); q.pop_front();
        for(auto [v,w] : AL[u]) {
            if(d[u]+w < d[v]) {
                d[v] = d[u]+w;
                p[v] = u;
                w==1 ? q.push_back(v) : q.push_front(v);
            }
        }
    }
}

// D'Esopo-Pape Algorithm. Works with Negative Edge Weights
void DEsopoPape(ll s) {
    deque<ll> q; q.pb(s); d[s] = 0;
    while(!q.empty()) {
        ll u = q.front(); q.pop_front();
        M[u] = 0;
        for(auto [v,w] : AL[u]) {
            if(d[v] > d[u]+w) {
                d[v] = d[u]+w;
                p[v] = u;
                if(M[v] == 2) {
                    M[v] = 1; q.pb(v);
                } else if(!M[v]) {
                    M[v] = 1; q.push_front(v);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, u, v, w; // cin >> n >> m;
    n = 8;
    AL.assign(n+1,{}); d.assign(n+1,INF); p.assign(n+1,-1);
    M.assign(n+1,2); // for D'Esopo-Pape

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

    // DEsopoPape(1);
    // dijkstraPQ(1);
    dijkstraSet(1);
    // bfs01(1);
    FOR(i,1,9) cout << d[i] << " "; cout << endl;
    FOR(i,1,9) cout << p[i] << " "; cout << endl;

    FOR(i,1,9) {
        vi A = getPath(i);
        cout << "Path: "; for(auto a : A) cout << a << " "; cout << endl;
    }

    return 0;
}
