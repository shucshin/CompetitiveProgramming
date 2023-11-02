// Lowest Common Ancestor (Binary Lifting)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

class LCA {
private:
    vector<vector<pi> > graph; vector<vi> up;
    vi depth, dist; ll l, MAXN;
public:
    LCA(ll n) {
        graph.assign(n,{}); up.assign(n,vi(20));
        depth.assign(n,0); dist.assign(n,0);
        FOR(i,0,n) {up[i][0] = i;}
        l = ceil(log2(n)); MAXN = n;
    }
    void addEdge(ll u, ll v, ll w) {graph[u].pb({v,w}); graph[v].pb({u,w});}
    void init() {
        dfs(0);
        FOR(i,1,l) {FOR(j,0,MAXN) up[j][i] = up[up[j][i-1]][i-1];}
    }

    void dfs(ll u) {
        for(auto &[v,w] : graph[u]) {
            if(v != up[u][0]) {
                depth[v] = depth[u]+1;
                dist[v] = dist[up[v][0]=u]+w;
                dfs(v);
            }
        }
    }

    ll jump(ll x, ll d) {
        FOR(i,0,l) {if((d>>i)&1) x = up[x][i];} 
        return x;
    }

    ll lca(ll u, ll v) {
        if(depth[u] < depth[v]) swap(u,v);
        u = jump(u, depth[u]-depth[v]);
        if(u==v) return u;
        RFOR(i,0,l) {
            if(up[u][i] != up[v][i])
                u = up[u][i], v = up[v][i];
        }
        return up[u][0];
    }

    ll distance(int u, int v) {
        return dist[u]+dist[v]-2*dist[lca(u,v)];
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ll n, m, u, v, w; cin >> n;
    LCA anc(n); 
    FOR(i,0,n-1) {
        cin >> u >> v >> w;
        anc.addEdge(u,v,w);
    }
    anc.init();
    cin >> m;
    FOR(i,0,m) {
        cin >> u >> v;
        cout << anc.distance(u,v) << endl;
    }
    return 0;
}