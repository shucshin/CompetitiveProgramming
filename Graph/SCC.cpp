// Strongly Connected Components (Kosaraju's Algorithm)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()

class SCC {
private:
    vector<vi> AL, AL_T;
    vi A, dfs_num;
    ll MAXN, ans = 0;
public:
    SCC(int n) {
        AL.assign(n,{}); AL_T.assign(n,{});
        dfs_num.assign(n,0);
        MAXN = n;
    }
    void Kosaraju(int u, int pass) { //==pass== 1 original, 2 transpose
        dfs_num[u] = 1;
        vi &neighbor = (pass==1) ? AL[u] : AL_T[u];
        for(auto &v : neighbor) {
            if(!dfs_num[v]) Kosaraju(v,pass); 
        } A.pb(u);
    }
    void addEdge(int u, int v) {AL[u].pb(v); AL_T[v].pb(u);}
    ll components() {
        FOR(u,0,MAXN) {if(!dfs_num[u]) Kosaraju(u,1);}
        dfs_num.assign(MAXN,0);
        for(int i = MAXN-1; i >= 0; i--) {if(!dfs_num[A[i]]) Kosaraju(A[i],2), ans++;}
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v; cin >> n >> m;
    SCC scc(n);
    FOR(i,0,m) {
        cin >> u >> v; --u; --v;
        scc.addEdge(u,v);
    } 
    cout << scc.components() << endl;

    return 0;
}