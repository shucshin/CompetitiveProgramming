// Dijkstra Algorithm
struct Edge {ll u, v, w;};
vector<Edge> edges;

vector<vector<pi>> AL(n+1,{});
vi d(n+1,INF), p(n+1,-1), M(n+1,2); // d = distance, p = parent

// Dijkstra with Set (Red-Black Trees), supports removing elems
void dijkstraSet(ll s, ll x=-1) { // Exclude node x
    set<pi> q;
    q.insert({0,s}); d[s] = 0;
    while(!q.empty()) {
        ll u = q.begin()->snd; q.erase(q.begin());
        if(u == x) continue;
        for(auto a : AL[u]) {
            ll v = a.fst, w = a.snd;
            if(d[u] + w < d[v]) {
                q.erase({d[v],v});
                d[v] = d[u]+w;
                p[v] = u;
                q.insert({d[v],v});
            }
        }
    }
}

// Dijkstra with priority_queue (Heaps), vertex can appear multiple times with diff dst
void dijkstraPQ(ll s, ll x=-1) { // Exclude node x
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0,s}); d[s] = 0;
    while(!pq.empty()) {
        ll u = pq.top().snd, d_u = pq.top().fst; pq.pop();
        if(u == x || d_u != d[u]) continue;
        for(auto a : AL[u]) {
            ll v = a.fst, w = a.snd;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                p[v] = u;
                pq.push({d[v],v});
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

// Weights of edges 0 or 1, O(|E|)
void bfs01(ll s) {
    deque<ll> q; d[s] = 0; 
    q.push_front(s);
    while(!q.empty()) {
        ll u = q.front(); q.pop_front();
        for(auto [v,w] : AL[u]) {
            if(d[u]+w < d[v]) {
                d[v] = d[u]+w;
                p[v] = u;
                w==1 ? q.push_back(v) : q.push_front(v);
            }
        }
    }
}

// D'Esopo-Pape Algorithm. Works with Negative Edge Weights
void DEsopoPape(ll s) {
    deque<ll> q; q.pb(s); d[s] = 0;
    while(!q.empty()) {
        ll u = q.front(); q.pop_front();
        M[u] = 0;
        for(auto [v,w] : AL[u]) {
            if(d[v] > d[u]+w) {
                d[v] = d[u]+w;
                p[v] = u;
                if(M[v] == 2) {
                    M[v] = 1; q.pb(v);
                } else if(!M[v]) {
                    M[v] = 1; q.push_front(v);
                }
            }
        }
    }
}