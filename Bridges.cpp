// Articulation Points and Bridges
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;
using ti = tuple<ll,ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
const ll MOD = 1e9+7;

class Bridges {
private:
    vector<vi> graph; ll dfsNumberCounter, dfsRoot, rootChildren, MAXN, UNVISITED = -1;
    vi dfs_num, dfs_low, dfs_parent, articulation_vertex, articulation_points;
    vector<pi> bridges;
public:
    Bridges(int n) {
        dfsNumberCounter = 0, MAXN = n;
        graph.assign(n,{});
        dfs_num.assign(n,UNVISITED);
        dfs_low.assign(n,0);
        dfs_parent.assign(n,-1);
        articulation_vertex.assign(n,0);
    }
    void addEdge(int u, int v) {graph[u].pb(v); graph[v].pb(u);} 
    void articulationPointAndBridge(int u) {
        dfs_num[u] = dfsNumberCounter++;
        dfs_low[u] = dfs_num[u];
        for(auto &v : graph[u]) {
            if(dfs_num[v] == UNVISITED) {
                dfs_parent[v] = u;
                if(u == dfsRoot) ++rootChildren;
                articulationPointAndBridge(v);
                if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;
                if(dfs_low[v] > dfs_num[u]) {bridges.pb({u,v});}
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            } else if(v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
    void artibridge() {
        FOR(u,0,MAXN) {
            if(dfs_num[u] == UNVISITED) {
                dfsRoot = u; rootChildren = 0;
                articulationPointAndBridge(u);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
        FOR(u,0,MAXN) {if(articulation_vertex[u]) articulation_points.pb(u);}
    }
    vector<pi> getBridges() {return bridges;}
    vi getArticulation() {return articulation_points;}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n=5, m=5, u, v;
    Bridges br(n); br.addEdge(0,1); br.addEdge(1,2); br.addEdge(2,3); br.addEdge(2,4); br.addEdge(0,2);
    br.artibridge();
    vector<pi> bridges = br.getBridges();
    vi articu = br.getArticulation();
    cout << "Bridges: "; FOR(i,0,bridges.size()) {cout << "{" << bridges[i].fst+1 << " " << bridges[i].snd+1 << "} ";} cout << endl;
    cout << "Arculation Points: "; FOR(i,0,articu.size()) {cout << articu[i]+1 << " ";} cout << endl;
    return 0;
}
