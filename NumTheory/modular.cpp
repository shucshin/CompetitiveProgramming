// Modular Arithmetic
const ll MOD = 1e9+7; // 998244353
// if(ans < 0) ans += MOD;

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

//==Modular Inverse for array of numbers==
vi invs(vi &A, ll m=998244353) {
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