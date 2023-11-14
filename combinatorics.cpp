// Combinatorics
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
const ll MOD = 1e9+7; // 998244353
const ll INF = 1e18;
const ll MXN = 2e6+5;
const ll MXC = 1e4+5;


//==Legendre's Formula==
// Max power of prime number p that can divide n!
ll prime_pow(ll n, ll p) {
    ll x = 0;
    while(n) {n /= p; x += n;} 
    return x;
}

//==Legendre's Formula (Efficient)==
ll pow_fact(ll n, ll k) {
    ll x = 0, p = k;
    while(p <= n) {
        x += n/p;
        p *= k;
    }
    return x;
}

//==Power of Factorial Divisor==
/* Given n, k. Find largest power of k denoted as x such that n! is divisible by k^x
   For every prime factor, find largest power that divides n!
   Return minimum of all found powers
*/
ll composite_pow(ll n, ll k) {
    ll x = INF;
    for(ll i = 2; i*i <= n; i++) {
        ll c = 0;
        while(k%i==0) {c++; k/=i;}
        if(c > 0) {
            ll pow = pow_fact(n,i)/c;
            x = min(x,pow);
        }
    }
    if(k >= 2) {
        ll pow = pow_fact(n,k);
        x = min(x,pow);
    }
    return x;
}


//==Binary Exponentiation for Modular Multiplicative Inverse==
ll bcpow(ll a, ll b, ll m=MOD){ // bcpow(a,MOD-2) :: Modular Inverse of a
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % m;
        a = a * a % m; b >>= 1ll;
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
vi fac(MXN), inv(MXN);
void facinv() {
    fac[0] = 1; fac[1] = 1;
    FOR(i,2,MXN) fac[i] = fac[i-1]*i%MOD; 
    inv[MXN-1] = bcpow(fac[MXN-1], MOD-2);
    for(ll i = MXN-2; i >= 0; i--) inv[i] = inv[i+1]*(i+1ll)%MOD;
} 

//==Binomial Coefficient==
ll nCk(ll n, ll k) {
    return n < k ? 0 : fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

//==Catalan Numbers==
vi catalan(MXC);
void catalan_nums() {
    catalan[0] = catalan[1] = 1;
    FOR(i,2,MXC) {
        catalan[i] = 0;
        FOR(j,0,i) {
            catalan[i] += (catalan[j]*catalan[i-j-1])%MOD;
            if (catalan[i] >= MOD) catalan[i] -= MOD;
        }
    }
}

int main() {
    facinv(); catalan_nums();
    cout << prime_pow(146,15) << endl; 
    cout << composite_pow(146,15) << endl; // 35
    cout << pow_fact(146,15) << endl;

    FOR(i,1,15) {
        cout << fac[i] << " " << inv[i] << endl;
    }
    
    FOR(i,0,15) cout << catalan[i] << " "; cout << endl;


    return 0;
}