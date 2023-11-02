// Graph
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n';
#define sq(a) (a)*(a)
#define pb push_back
#define fst first
#define snd second
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
const int INF = 1e9;
const ll MOD = 1e9+7;

class Graph {
private:
    vector<vi> graph; int MAXN;
    vi vis, dist, color, subtree;
public:
    Graph(int n) {
        MAXN = n;
        graph.assign(n,{});
        vis.assign(n,0);
        dist.assign(n,0);
        color.assign(n,INF);
        subtree.assign(n,0);
    }
    vector<vi> getGraph() {return graph;}
    vi getSubtree() {subtrees(1,1); return subtree;}
    void addEdge(int u, int v) {graph[u].pb(v); graph[v].pb(u);}

    void subtrees(int u, int p) {
        subtree[u] = 1;
        for(auto v : graph[u]) {
            if(p==v) continue;
            subtrees(v,u);
            subtree[u] += subtree[v];
        }
    }

    pair<bool,vi> bipartite_check() {
        bool bipartite = 1; queue<ll> q;
        FOR(i,0,MAXN) {
            if((color[i]==INF && graph[i].empty()) || color[i] != INF) continue;
            q.push(i); color[i] = 0;
            while(!q.empty()) {
                ll u = q.front(); q.pop();
                for(auto &v : graph[u]) {
                    if(color[v] == INF) {color[v] = color[u]^1; q.push(v);} 
                    else {bipartite &= color[u] != color[v];}
                }
            }
        }
        return {bipartite,color};
    }
};


//==Celebrity Problem== (n <= 1e5)
int celebrity(vector<vi> &graph, int n) {
    int i = 0, j = n-1;
    while(i < j) {
        (graph[j][i]==1) ? j-- : i++;
    }
    int c = i;
    FOR(i,0,n) {
        if(i != c) {
            if(graph[i][c] == 0 || graph[c][i] == 1) return -1;
        }
    }
    return c;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n = 9;
    Graph graph(n+1);
    graph.addEdge(1,2); graph.addEdge(1,5); graph.addEdge(2,3);
    graph.addEdge(2,4); graph.addEdge(5,6); graph.addEdge(5,7);
    graph.addEdge(3,8); graph.addEdge(3,9); 
    vector<vi> G = graph.getGraph();
    //cout << celebrity(G, 2) << endl;

    vi sub = graph.getSubtree(); 
    //vi sub = graph.getSub();
    cout << "Subtree: ";
    FOR(i,1,n+1) {
        cout << sub[i] << " ";
    } cout << endl;

    cout << graph.bipartite_check().fst << endl;
    return 0;
}
