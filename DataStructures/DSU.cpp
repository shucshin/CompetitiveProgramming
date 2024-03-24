// Disjoint Set Union
class DSU {
private:
    vi p, rank, sz;
    int numSets;
public:
    DSU(int n) {
        p.assign(n,0);
        FOR(i,0,n) p[i] = i;
        rank.assign(n,0);
        sz.assign(n,1);
        numSets = n;
    }
    int find(int i) {return (p[i]==i) ? i : (p[i] = find(p[i]));}
    bool same(int i, int j) {return find(i) == find(j);}
    int numDisjoint() {return numSets;}
    ll size(int i) {return sz[find(i)];}
    void unite(int i, int j) {
        if(same(i,j)) return;
        int x = find(i), y = find(j);
        if(rank[x] > rank[y]) swap(x,y);
        p[x] = y;
        if(rank[x] == rank[y]) ++rank[y];
        sz[y] += sz[x];
        --numSets;
    }
};