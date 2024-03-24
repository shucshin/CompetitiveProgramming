// Bellman-Ford Algorithm
struct Edge {ll u, v, w;};
vector<Edge> edges;

vector<vector<pi>> AL(n+1,{});
vi d(n+1,INF), p(n+1,-1); // d = distance, p = parent

// Bellman-Ford (No Negative Edges)
void bellmanFord(ll s) {
    d[s] = 0;
    for(;;) {
        bool any = 0;
        for(Edge e : edges) 
            if(d[e.u] < INF) 
                if(d[e.v] > d[e.u]+e.w) {
                    d[e.v] = d[e.u]+e.w;
                    p[e.v] = e.u;
                    any = 1;
                }
        if(!any) break;
    }
}

// Retrieval of shortest path to s
vi getPath(ll s) {
    if(d[s]==INF) return {};
    vi A;
    for(ll u = s; u != -1; u = p[u]) A.pb(u);
    reverse(all(A));
    return A;
}

// Finding Negative Cycle with Bellman-Ford
vi bellmanFordNC(ll s, ll n) { // d.assign(n+1,0); for Cycle Finding
    ll x; d[s] = 0;
    FOR(_,0,n) {
        x = -1;
        for(Edge e : edges)
            if(d[e.u] < INF)
                if(d[e.v] > d[e.u]+e.w) {
                    d[e.v] = max(-INF,d[e.u]+e.w);
                    p[e.v] = e.u;
                    x = e.v;
                }
    }
    if(x==-1) return {}; // no Neg Cycle
    FOR(_,0,n) x = p[x];
    vi cycle;
    for(ll u=x;;u=p[u]) {
        cycle.pb(u);
        if(u==x && cycle.size()>1) break;
    } reverse(all(cycle));
    return cycle;
}

// All Nodes that belong in a Neg Cycle
void negative_infinity(ll n) {
    queue<ll> q; 
    FOR(u,0,n) { // u,1,n+1 for 1-indexed
        if(d[u] < INF)
            for(auto [v,w] : AL[u]) 
                if(d[v] > d[u]+w) q.push(v);
    }
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        d[u] = -INF;
        for(auto [v,w] : AL[u]) {
            if(d[v]==-INF) continue;
            q.push(v);
        }
    } cout << endl;
}

// Shortest Path Faster Algorithm, improvement of Bellman-Ford Algorithm
bool spfa(ll s) {
    ll n = AL.size(); 
    vi c(n,0), inq(n,0);
    queue<ll> q; q.push(s);
    d[s] = 0; inq[s] = 1;
    while(!q.empty()) {
        ll u = q.front(); q.pop(); inq[u] = 0;
        for(auto [v,w] : AL[u]) {
            if(d[v] > d[u]+w) {
                d[v] = d[u]+w;
                p[v] = u;
                if(!inq[v]) {
                    q.push(v); inq[v] = 1; c[v]++;
                    if(c[v] > n) return false; // Neg Cycle
                }
            }
        }
    } return true;
}

// Edges
FOR(_,0,m) {
    cin >> u >> v >> w;
    edges.pb({u,v,w});
    AL[u].pb({v,w}); // AL[v].pb({u,w});
} 

// bellmanFord(1); // No Neg Edges
vi A = bellmanFordNC(1,n+1);
negative_infinity(n);
// !spfa(1) ? printf("Neg Cycle\n") : printf("No Neg Cycle\n");

// Queries
FOR(_,0,q) {
    cin >> u;
    if(d[u]==INF)       cout << "Impossible\n"; // No Path
    else if(d[u]==-INF) cout << "-Infinity\n";  // Neg Cycle
    else                cout << d[u] << endl;
}
