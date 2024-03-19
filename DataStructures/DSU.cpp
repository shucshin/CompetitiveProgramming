// Disjoint Set Union
#include <bits/stdc++.h>
using namespace std;
using lli = __int128;
using ll = long long; // %lld
using ld = long double; // %0.5Lf
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
const ll MOD = 1e9+7;
const ll INF = 1e9;

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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    DSU dsu(5); // 0-indexed
    dsu.unite(0,1);
    dsu.unite(4,3);
    dsu.unite(2,3);
    cout << dsu.numDisjoint() << endl;
    cout << dsu.same(0,4) << endl;
    cout << dsu.same(0,1) << endl;
    FOR(i,0,5) {
        cout << dsu.find(i) << " ";
    } cout << endl;
    dsu.unite(1, 2);
    printf("%d\n", dsu.numDisjoint()); // 1
    for (int i = 0; i < 5; ++i) // 3 for {0, 1, 2, 3, 4}
        printf("find(%d) = %d, size(%d) = %d\n",
            i, dsu.find(i), i, dsu.size(i));
    return 0;
}