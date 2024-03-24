// Centroids
vi subtree(n,0), p(n,0);
vector<vi> AL(n,{});

void dfs(int u) {
    subtree[u] = 1;
    for(auto v : AL[u]) {
        if(v == p[u]) continue;
        p[v] = u;
        dfs(v);
        subtree[u] += subtree[v];
    }
} // Subtree sizes for each node inclusive

ll centroid(ll u) {
    for(auto v : AL[u]) {
        if(v != p[u] && subtree[v]*2 >= AL.size()) 
            return centroid(v);
    } return u;
} // Subtrees rooted from here are size <= n/2 

p[0] = -1;  dfs(0);
ll c = centroid(0);