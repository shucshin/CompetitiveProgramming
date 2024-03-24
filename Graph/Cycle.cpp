// Cycles
vector<vi> AL(n+1,{});
vi vis(n+1,0), color(n+1,0), par(n+1,-1);
ll cycle_node = -1, cycle_ini = -1, cycle_end;

// Finds the nearest cycle node from u (Undirected Graph)
bool cycleNode(int u, int p=-1) {
    vis[u] = 1;
    for(auto v : AL[u]) {
        if(v != p && vis[v]) {
            // already visited node that is not current node's parent
            cycle_node = v; return true;
        } else if(!vis[v]) {
            if(cycleNode(v,u)) return true;
        }
    } return false;
}

// dfs for Directed Graph
bool dfs_di(int u) {
    color[u] = 1;
    for(auto v : AL[u]) {
        if(color[v] == 0) {
            par[v] = u;
            if(dfs_di(v)) return true;
        } else if(color[v] == 1) {
            cycle_end = u;
            cycle_ini = v;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

// dfs for Undirected Graph
bool dfs_un(int u, int p=-1) {
    vis[u] = 1;
    for(auto v : AL[u]) {
        if(v==p) continue;
        if(vis[v]) {
            cycle_end = u;
            cycle_ini = v;
            return true;
        }
        par[v] = u;
        if(dfs_un(v,par[v])) return true;
    }
    return false;
}

vi find_cycle(ll n, bool directed=0) {
    FOR(u,1,n+1) { // 1-indexed
        if(directed) {if(color[u]==0 && dfs_di(u)) break;}
        else {if(!vis[u] && dfs_un(u,par[u])) break;}
    }
    if(cycle_ini == -1) return {};
    vi cycle; cycle.pb(cycle_ini);
    for(ll u = cycle_end; u != cycle_ini; u = par[u]) {
        cycle.pb(u);
    } cycle.pb(cycle_ini);
    if(directed) reverse(all(cycle));
    return cycle;
}

//==Use==
vi A = find_cycle(n,1); // 0 if undirected
if(A.empty()) cout << "IMPOSSIBLE\n";
else {
    cout << A.size() << endl;
    for(auto a : A) cout << a << " ";
    cout << endl;
}