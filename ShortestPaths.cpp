// Single-Source Shortest Paths with Unweighted Edges
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
const ll MXN = 5e2+5;

struct Edge {ll u, v;};
vector<Edge> edges;

vector<vi> AL;
vi vis, d, p; // d = distance, p = parent

// Depth First Search
void dfs(ll u) {
    vis[u] = 1;
    for(auto v : AL[u]) {
        if(!vis[v]) dfs(v);
    }
}

// Distances w/ recursive dfs when there's no cycles
void dfs(int u, int p=-1) {
    if(p != -1) {d[u] = d[p]+1;}
    for(auto v : AL[u]) {
        if(v != p) dfs(v,u);
    }
}

// Breath First Search
void bfs(ll s) {
    vis[s] = 1;
    queue<ll> q; q.push(s);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto v : AL[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                d[v] = d[u]+1;
                p[v] = u;
                q.push(v);
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


// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, q, u, v; n = 9; // cin >> n >> m;
    AL.assign(n+1,{}); d.assign(n+1,0); p.assign(n+1,-1), vis.assign(n+1,0);

    /* FOR(_,0,m) { 
        cin >> u >> v; 
        AL[u].pb(v); AL[v].pb(u); 
        edges.pb({u,v});
    } */

    AL[1].pb(2); AL[2].pb(1);
    AL[1].pb(3); AL[3].pb(1);
    AL[2].pb(5); AL[5].pb(2);
    AL[2].pb(4); AL[4].pb(2);
    AL[4].pb(7); AL[7].pb(4);
    AL[3].pb(6); AL[6].pb(3);
    AL[5].pb(6); AL[6].pb(5);
    AL[5].pb(7); AL[7].pb(5);
    AL[6].pb(8); AL[8].pb(6);
    AL[7].pb(8); AL[8].pb(7);
    AL[1].pb(7); AL[7].pb(1);

    bfs(1);
    FOR(i,1,10) cout << vis[i] << " "; cout << endl;
    FOR(i,1,10) cout << d[i] << " "; cout << endl;
    FOR(i,1,10) cout << p[i] << " "; cout << endl;

    FOR(i,1,10) {
        vi A = getPath(i);
        if(A[0] != 1) {cout << "No Path\n"; continue;}
        cout << "Path: "; for(auto a : A) cout << a << " "; cout << endl;
    }

    return 0;
}
