// Spanning Tree
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;
using ti = tuple<ll,ll,ll>;
#define endl '\n'
#define pb push_back
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
const ll MOD = 1e9+7;

struct Edge {ll u, v, w;};
// < Minimum Spanning Tree, > Maximum Spanning Tree
bool cmp(Edge a, Edge b) {return a.w > b.w;}

class MST {
private:
    vi p, rank, sz;
    ll sets, cost = 0;
public:
    vector<Edge> edges, mst;
    MST(int n) {
        p.assign(n,0);
        FOR(i,0,n) p[i] = i;
        rank.assign(n,0);
        sz.assign(n,1);
        sets = n;
    }
    int find(int i) {return (p[i]==i) ? i : (p[i] = find(p[i]));}
    bool same(int i, int j) {return find(i) == find(j);}
    ll size(int i) {return sz[find(i)];}
    void unite(int i, int j) {
        int a = find(i), b = find(j);
        if(a==b) return;
        if(rank[a] < rank[b]) swap(a,b);
        p[b] = a;
        if(rank[a] == rank[b]) ++rank[a];
        sz[a] = sz[b];
        --sets;
    }
    ll total_cost() {return cost;}
    void addEdge(int u, int v, ll w) {Edge e; e.u = u; e.v = v; e.w = w; edges.pb(e);}
    vector<Edge> Kruskal() {
        sort(all(edges),cmp);
        for(Edge e : edges) {
            --e.u; --e.v;
            if(!same(e.u,e.v)) {
                cost += e.w; cost %= MOD; if(cost < 0) cost += MOD;
                mst.pb(e);
                unite(e.u,e.v);
            }
        }
        return mst;
    }
    void second_best() {
        // Aún no la implemento
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<ti> edges = {{1,2,10},{2,3,2},{4,3,5},{6,3,15},{3,5,4},{4,5,3},{2,6,6}};
    MST st(6);
    FOR(i,0,edges.size()) {
        ll u = get<0>(edges[i]), v = get<1>(edges[i]), w = get<2>(edges[i]);
        st.addEdge(u,v,w);
    }
    vector<Edge> mst = st.Kruskal();
    for(auto a : mst) {
        cout << "u,v,w: " << a.u+1 << " " << a.v+1 << " " << a.w << endl;
    }
    cout << "cost: " << st.total_cost() << endl;

    return 0;
}