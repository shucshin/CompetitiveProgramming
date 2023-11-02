// Topological Sort
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using ti = tuple<ll,ll,ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
const ll MOD = 1e9+7;

class Toposort {
private:
    vector<vi> graph; int MAXN;
    vi ts, tl, vis, indegree;
    priority_queue<ll, vi, greater<ll> > pq;
public:
    Toposort(int n) {
        MAXN = n;
        tl.assign(MAXN,0);
        graph.assign(n,{});
        vis.assign(n,0);
        indegree.assign(n,0);
    }
    void addEdge(int u, int v) {graph[u].pb(v); indegree[v]++;}
    void addEdgeTL(int v, int u) {graph[u].pb(v); indegree[v]++;}
    void topo(int a) {
        vis[a] = 1;
        for(auto &u : graph[a]) {if(!vis[u]) topo(u);}
        ts.pb(a);}
    vi toposort() {
        for(int i = MAXN-1; i >= 0; i--) {if(!vis[i]) topo(i);}
        //FOR(i,0,MAXN) {if(!vis[i]) topo(i);}
        reverse(all(ts)); return ts;
    }
    
    vi khan() {
        FOR(i,0,MAXN) {if(!indegree[i]) pq.push(i);}
        while(!pq.empty()) {
            int u = pq.top(); pq.pop(); ts.pb(u);
            for(auto &v : graph[u]) {
                --indegree[v];
                if(!indegree[v]) pq.push(v);}
        } return ts;
    }

    vi topolabel() { // order of node appearance lexicographically
        set<ll,greater<> > s; int c = MAXN-1;
        FOR(i,0,MAXN) {if(!indegree[i]) s.insert(i);} 
        while(!s.empty()) {
            ll u = *s.begin(); s.erase(u); tl[u] = c;
            for(auto &x : graph[u]) {
                if(--indegree[x]==0) s.insert(x);
            } c--;
        }
        return tl;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n=5, m=4, u, v; //--u, --v
    Toposort tp1(n); tp1.addEdge(2,0); tp1.addEdge(1,0); tp1.addEdge(1,2); tp1.addEdge(3,4);
    Toposort tp2(n); tp2.addEdge(2,0); tp2.addEdge(1,0); tp2.addEdge(1,2); tp2.addEdge(3,4);
    Toposort tp3(n); tp3.addEdgeTL(2,0); tp3.addEdgeTL(1,0); tp3.addEdgeTL(1,2); tp3.addEdgeTL(3,4);

    vi kh = tp1.khan(); cout << "Khan: "; 
    FOR(i,0,n) {cout << kh[i]+1 << " ";} cout << endl;

    vi ts = tp2.toposort(); cout << "Topo: "; 
    FOR(i,0,n) {cout << ts[i]+1 << " ";} cout << endl;

    vi tl = tp3.topolabel(); cout << "Topo Label: ";
    FOR(i,0,n) {cout << tl[i]+1 << " ";} cout << endl;
    return 0;
}