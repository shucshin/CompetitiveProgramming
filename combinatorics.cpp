#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using vll = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)
const ll MOD = 1e9+7;
const ll MAXN = 1e6;

vll fac(MAXN), inv(MAXN);
//==Binary Exponentiation for Modular Multiplicative Inverse==
ll bcpow(ll a, ll b){ // bcpow(a,MOD-2) :: Modular Inverse of a
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % MOD;
        a = a * a % MOD; b >>= 1ll;
    } return r;
}

//==Binary Exponentiation==
ll binpow(ll a, ll b) {
    ll r = 1; 
    while(b) {
	if(b & 1ll) r = r * a; 
	a = a * a; b >>= 1ll;
    } return r;
}

//==Calculates Factorials and Inverses==
void facinv() {
    fac[0] = 1; fac[1] = 1;
    FOR(i,2,MAXN) fac[i] = fac[i-1]*i%MOD; 
    inv[MAXN-1] = bcpow(fac[MAXN-1], MOD-2);
    for(ll i = MAXN-2; i >= 0; i--) inv[i] = inv[i+1]*(i+1ll)%MOD;
} 

//==Binomial Coefficient==
ll nCk(ll n, ll k) {
    return n < k ? 0 : fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main() {
    int n = 15; // cin >> n;
    ll ans; facinv();
    FOR(i,1,n+1) {
        cout << nCk(i*i,2) << " ";
    } cout << endl;
    return 0;
}