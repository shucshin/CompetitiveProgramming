// Combinatorics
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
    ld r = 1; 
    rep(i,1,k+1) r = r * (n-k+i)/i; 
    return (ll)(r+0.01);
}

//==Binomial Coefficient w/ MOD==
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