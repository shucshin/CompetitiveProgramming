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
#define rall(a) (a).rbegin(), (a).rend()
#define lb(v,a) lower_bound(all(v),a)-v.begin()
#define ub(v,a) upper_bound(all(v),a)-v.begin()
const ll MOD = 1e9+7; // 998244353
const ll INF = 1e9;

struct TreeNode {
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ll treeSum(ll u) {
    if(A[u] == 0) return 0;
    ll l = treeSum(A[L[u]]), r = treeSum(A[R[u]]);
    return A[u] + l + r;
}

ll treeMax(ll u) {
    if(A[u] == 0) return -INF;
    ll l = treeMax(A[L[u]]), r = treeMax(A[R[u]]);
    return max({A[u], l, r});
}

ll treeHeight(ll u) {
    if(A[u] == 0) return 0;
    ll l = treeHeight(A[L[u]]), r = treeHeight(A[R[u]]);
    return 1 + max(l,r);
}

bool treeExists(ll u, ll x) {
    if(A[u] == 0) return false;
    ll l = treeExists(L[u],x), r = treeExists(R[u],x);
    return A[u] == x || A[u] == l || A[u] == r;
}

void treeReverse(ll u) {
    if(!u) return;
    treeReverse(L[u]);
    treeReverse(R[u]);
    swap(L[u],R[u]);
}

void solve() {
    ll n; cin >> n;
    vi A(n); FOR(i,0,n) cin >> A[i]; // for(auto &a : A) cin >> a;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}