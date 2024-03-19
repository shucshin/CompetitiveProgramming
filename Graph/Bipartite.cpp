// Bipartite Check
vector<vi> AL;
vi color;
 
pair<bool,vi> bipartite_check(ll n) {
    bool bipartite = 1; queue<ll> q;
    FOR(i,1,n+1) { // 1-indexed
        if(color[i] != INF) continue;
        q.push(i); color[i] = 0;
        while(!q.empty()) {
            ll u = q.front(); q.pop();
            for(auto &v : AL[u]) {
                if(color[v] == INF) {color[v] = color[u]^1; q.push(v);} 
                else {bipartite &= color[u] != color[v];}
            }
        }
    }
    return {bipartite,color};
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, u, v; cin >> n >> m;
    AL.assign(n+1,{}); color.assign(n+1,INF);
    FOR(_,0,m) {
        cin >> u >> v;
        AL[u].pb(v); AL[v].pb(u);
    }
 
    pair<bool,vi> A = bipartite_check(n);
    if(A.fst == false) {
        cout << "IMPOSSIBLE\n";
    } else {
        FOR(i,1,n+1) cout << A.snd[i]+1 << " ";
        cout << endl;
    }

    return 0;
}