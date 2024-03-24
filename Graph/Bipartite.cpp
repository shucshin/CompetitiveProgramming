// Bipartite Check
vector<vi> AL(n+1,{});
vi color(n+1,INF);
 
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

pair<bool,vi> A = bipartite_check(n);
if(A.fst == false) {
    cout << "IMPOSSIBLE\n";
} else {
    FOR(i,1,n+1) cout << A.snd[i]+1 << " ";
    cout << endl;
}