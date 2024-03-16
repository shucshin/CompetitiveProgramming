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

struct segtree{
    int n;
    vector<long long> st;

    void build(vector<long long>& nums, int v, int tl, int tr){
        if (tl == tr) st[v] = nums[tl];
        else{
            int mid = (tl + tr) / 2;
            build(nums,2*v,tl,mid);
            build(nums,2*v + 1,mid+1,tr);
            st[v] = st[2*v] + st[2*v+1];
        }
    }

    void build(vector<long long>& nums){
        n = nums.size();
        st.resize(4 * n);
        build(nums,1,0,n-1);
    }

    long long query(int v, int tl, int tr, int l, int r){
        if (tl > r || tr < l) return 0;
        if (tl >= l && tr <= r) return st[v];
        int mid = (tl + tr) / 2;
        return query(2*v,tl,mid,l,r) + query(2*v+1,mid+1,tr,l,r);
    }

    long long query(int l, int r){
        return query(1,0,n-1,l,r);
    }
    void update(int v, int tl, int tr, int pos, long long val){
        if (tl == tr && tl == pos) st[v] = val;
        else{
            int mid = (tl + tr) / 2;
            if (pos <= mid) update(2*v,tl,mid,pos,val);
            else update(2*v+1,mid+1,tr,pos,val);
            st[v] = st[2*v] + st[2*v+1];
        }
    }
    void update(int pos, long long val){
        update(1,0,n-1,pos,val);
    }
};

//function to find the K-th One on the array
vi st; int n;
int findKtone(int k, int v, int tl, int tr){
            if (k > st[v])return -1;
            if( tl == tr){return tl;}
            int mid = (tl + tr) / 2;
            int leftsub = st[2*v];
            if(leftsub >= k){
                return findKtone(k,2*v,tl,mid); 
            } else {
                return findKtone(k-leftsub,2*v+1,mid+1,tr); 
            }
        }


//Function to get the first element at least X, or above X
int get_first(int v, int tl, int tr, int l, int r, int x) {
        if(tl > r || tr < l) return -1;
        if(st[v] <= x) return -1;
        if (tl== tr) return tl;
        int tm = tl + (tr-tl)/2;
        int left = get_first(2*v, tl, tm, l, r, x);
        if(left != -1) return left;
        return get_first(2*v+1, tm+1, tr, l ,r, x);
        }
        int get_first(int x, int l, int r){
            return get_first(1,0,n-1, l,r,x);
        }

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n, q, k, a, b; cin >> n >> q; ll x;
    segtree st;
    vi A(n); FOR(i,0,n) cin >> A[i]; st.build(A); // 0-indexed
    while(q--) {
        cin >> k;
        if(k == 1) {cin >> a >> x; a--; st.update(a, x);}
        else {cin >> a >> b; a--; b--; cout << st.query(a,b) << endl;}
    }

    return 0;
}