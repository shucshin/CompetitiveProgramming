// Graph
vector<vi> AL(n,{}); 
vi vis(n,0), dist(n,0), subtree(n,0), leaf(n,0);

void subtrees(int u, int p=-1) { // subtrees(1,1)
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

// Gets path from initial node to node u
vi getPath(ll u) {
    vi A = {u};
    while(p[u] != -1) {
        A.pb(p[u]);
        u = p[u];
    } reverse(all(A));
    return A;
}

// Retrieval of shortest path to s
vi getPath(ll s) {
    if(d[s]==INF) return {};
    vi A;
    for(ll u = s; u != -1; u = p[u]) A.pb(u);
    reverse(all(A));
    return A;
}