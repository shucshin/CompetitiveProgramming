// Modular Arithmetic
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

//==Binary Exponentiation for Modular Multiplicative Inverse==
ll inv_bin(ll a, ll b=MOD-2){ // inv_bin(a,MOD-2) :: Modular Inverse of a
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % MOD;
        a = a * a % MOD; b >>= 1ll;
    } return r;
}

//==Modular Inverse==
ll inv(ll a) {
    return a <= 1 ? a : MOD-(ll)(MOD/a)*inv(MOD%a)%MOD;
}

//==Modular Inverse Precomputation from 1 to m-1
vi inverses(ll m) {
    vi inv(m); inv[1] = 1;
    FOR(a,2,m) {inv[a] = MOD-(ll)(MOD/a)*inv[MOD%a]%MOD;}
    return inv;
}

//==Recursive Extended GCD==
/* Finds x, y for ax + by = gcd(a,b) */
ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {x = 1; y = 0; return a;}
    ll x1, y1, d = gcd_ext(b, a % b, x1, y1);
    x = y1; y = x1-y1*(a/b);
    return d;
}

//==Modular Inverse for array of numbers==
vi invs(vi &A, ll m) {
    ll n = A.size(); if(n==0) return {};
    vi B(n); ll v = 1;
    FOR(i,0,n) {
        B[i] = v;
        v = static_cast<ll>(v)*A[i]%m;
    } ll x, y; gcd_ext(v,m,x,y);
    x = (x%m+m)%m;
    RFOR(i,0,n) {
        B[i] = static_cast<ll>(x)*B[i]%m;
        x = static_cast<ll>(x)*A[i]%m;
    } return B;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi A = {1,2,3,4,5,6,7,8,9,10};
    vi B = invs(A,MOD);
    for(auto a : B) cout << a << " "; cout << endl;
    vi C = inverses(11);
    for(auto a : C) cout << a << " "; cout << endl;
    FOR(i,1,11) {
        cout << inv(i) << " ";
    } cout << endl;
    return 0;
}