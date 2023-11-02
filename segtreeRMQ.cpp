#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)

class Segtree {
private:
    int n;
    vi A, st, lazy;
    int l(int p) {return p << 1;}
    int r(int p) {return(p << 1)+1;}
 
    ll conquer(ll a, ll b) {
        if(a==-1) return b;
        if(b==-1) return a;
        return min(a,b);
    }
 
    void build(int p, int L, int R) {
        if(L==R) st[p] = A[L];
        else {
            int m = (L+R)/2;
            build(l(p), L, m);
            build(r(p),m+1,R);
            st[p] = conquer(st[l(p)],st[r(p)]);
        }
    }
    
    void propagate(int p, int L, int R) {
        // set
        if(lazy[p]!=-1) {
            st[p] = lazy[p];
            if(L!=R) lazy[l(p)] = lazy[r(p)] = lazy[p];
            else A[L] = lazy[p];
            lazy[p] = -1;
        }
        // add
        /* if(lazy[p]!=0) {
            st[p]+=lazy[p];
            if(L!=R) {lazy[l(p)]+=lazy[p]; lazy[r(p)]+=lazy[p];}
            lazy[p] = 0;
        } */
    }
 
    ll RMQ(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if(i > j) return -1;
        if((L >= i) && (R <= j)) return st[p];
        int m = (L+R)/2;
        return conquer(RMQ(l(p), L, m, i, min(m,j)),
                       RMQ(r(p),m+1,R, max(i, m+1), j));
    }
    
    void update(int p, int L, int R, int i, int j, ll val) {
        propagate(p, L, R);
        if(i > j) return;
        if((L >= i) && (R <= j)) {
            lazy[p] = val;
            propagate(p, L, R);
        } else {
            int m = (L+R)/2;
            update(l(p), L, m, i, min(m,j), val);
            update(r(p), m+1, R, max(i, m+1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)]; // set -1, add 0
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)]; // set -1, add 0
            st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)]; // <= min, >= max
        }
    }
 
public:
    Segtree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {} // set -1, add 0
    Segtree(const vi &initialA) : Segtree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    void update(int i, int j, ll val) {update(1,0,n-1,i,j,val);}
    ll RMQ(int i, int j) {return RMQ(1,0,n-1,i,j);}
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, q, k, a, b; cin >> n >> q; ll x;
    vi A(n); FOR(i,0,n) cin >> A[i]; Segtree st(A); // 0-indexed
    while(q--) {
        cin >> k;
        if(k == 1) {cin >> a >> b >> x; a--; b--; st.update(a, b, x);}
        else {cin >> a >> b; a--; b--; cout << st.RMQ(a,b) << endl;}
    }
    return 0;
}