// Flood Fill
vector<vi> AL(n,vi(m)), vis(n,vi(m));
ll components = 0, component_size = 0;

void floodfill(ll r, ll c, ll color) {
    if((r < 0 || r >= n || c < 0 || c >= m)
     || AL[r][c] != color
     || vis[r][c]) return;
    vis[r][c] = 1;
    component_size++;
    floodfill(r, c+1, color);
    floodfill(r, c-1, color);
    floodfill(r+1, c, color);
    floodfill(r-1, c, color);
}

FOR(i,0,n) FOR(j,0,m) {
    char c; cin >> c; // . is component elem
    c == '.' ? AL[i][j] = 1 : AL[i][j] = 0;
}

FOR(i,0,n) FOR(j,0,m) {
    if(!vis[i][j] && AL[i][j] == 1) {
        component_size = 0;
        components++;
        floodfill(i,j,AL[i][j]);
    }
}