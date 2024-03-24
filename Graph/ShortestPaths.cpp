// Single-Source Shortest Paths with Unweighted Edges
struct Edge {ll u, v;};
vector<Edge> edges;

vector<vi> AL(n+1,{});
vi vis(n+1,0), d(n+1,0), p(n+1,-1);

// Depth First Search
void dfs(ll u) {
    vis[u] = 1;
    for(auto v : AL[u]) {
        if(!vis[v]) dfs(v);
    }
}

// Distances w/ recursive dfs when there's no cycles
void dfs(int u, int p=-1) {
    if(p != -1) {d[u] = d[p]+1;}
    for(auto v : AL[u]) {
        if(v != p) dfs(v,u);
    }
}

// Breath First Search
void bfs(ll s) {
    vis[s] = 1;
    queue<ll> q; q.push(s);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto v : AL[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                d[v] = d[u]+1;
                p[v] = u;
                q.push(v);
            }
        }
    }
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

bfs(1);
FOR(i,1,10) {
    vi A = getPath(i);
    if(A[0] != 1) {cout << "No Path\n"; continue;}
    cout << "Path: "; for(auto a : A) cout << a << " "; cout << endl;
}
