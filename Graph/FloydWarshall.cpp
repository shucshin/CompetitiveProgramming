// Floyd Warshall
const ll MXN = 5e2+5;
vector<vi> fw(MXN,vi(MXN,INF)); // for Floyd-Warshall

void floydWarshall(ll n) {
    FOR(i,0,n) fw[i][i] = 0;
    FOR(k,0,n) FOR(i,0,n) FOR(j,0,n) {
        if(fw[i][k] < INF && fw[k][j] < INF) 
            fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
    }
    FOR(i,0,n) FOR(j,0,n) FOR(k,0,n) { // Negative Cycles
        if(fw[k][k] < 0 && fw[i][k] < INF && fw[k][j] < INF) fw[i][j] = -INF;
    }
}

// Edges
FOR(_,0,m) {
    cin >> u >> v >> w;
    fw[u][v] = min(fw[u][v],w); fw[v][u] = min(fw[v][u],w);
    // if(w < fw[u][v]) {fw[u][v] = fw[v][u] = w;} 
}
floydWarshall(n); // n+1 for 1-indexed
// Queries
FOR(_,0,q) {
    cin >> u >> v;
    if(fw[u][v]==INF) cout << "-1\n"; // No Route
    else if(fw[u][v]==-INF) cout << "Negative Cycle\n"; // Neg Cycle
    else cout << fw[u][v] << endl;
}

// Reset
// FOR(i,0,n) FOR(j,0,n) fw[i][j] = INF;
