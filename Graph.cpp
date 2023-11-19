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
    vector<vi> AL; int MAXN;
    vi vis, dist, subtree, leaf;
public:
    Graph(int n) {
        MAXN = n;
        AL.assign(n,{});
        vis.assign(n,0);
        dist.assign(n,0);
        subtree.assign(n,0);
        leaf.assign(n,0);
    }
    vector<vi> getGraph() {return AL;}
    vi getSubtree() {subtrees(1,1); return subtree;}
    void addEdge(int u, int v) {AL[u].pb(v); AL[v].pb(u);}

    void subtrees(int u, int p=-1) {
        subtree[u] = 1;
        for(auto v : AL[u]) {
            if(p==v) continue;
            subtrees(v,u);
            subtree[u] += subtree[v];
        }
    }

    void leaves(int u, int p=-1) { // use vector<set<ll>> AL;
        leaf[u] = 0;
        for(auto v : AL[u]) {
            if(p==v) continue;
            leaves(v,u);
            leaf[u] += leaf[v];
        }
        if(AL[u].size()==1 && u != 1) leaf[u] = 1;
    }
};


//==Celebrity Problem== (n <= 1e5)
int celebrity(vector<vi> &AL, int n) {
    int i = 0, j = n-1;
    while(i < j) {
        (AL[j][i]==1) ? j-- : i++;
    }
    int c = i;
    FOR(i,0,n) {
        if(i != c) {
            if(AL[i][c] == 0 || AL[c][i] == 1) return -1;
        }
    }
    return c;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n = 9;
    Graph AL(n+1);
    AL.addEdge(1,2); AL.addEdge(1,5); AL.addEdge(2,3);
    AL.addEdge(2,4); AL.addEdge(5,6); AL.addEdge(5,7);
    AL.addEdge(3,8); AL.addEdge(3,9); 
    vector<vi> G = AL.getGraph();
    //cout << celebrity(G, 2) << endl;

    vi sub = AL.getSubtree(); 
    //vi sub = AL.getSub();
    cout << "Subtree: ";
    FOR(i,1,n+1) {
        cout << sub[i] << " ";
    } cout << endl;

    return 0;
}
