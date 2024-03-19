// Binary Exponentiation
using lli = __int128;
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return (a/gcd(a,b))*b;}

//==Binary Exponentiation==
lli binpow(lli a, lli b) {
    lli r = 1; 
    while(b) {
	if(b & 1ll) r *= a; 
	a *= a; b >>= 1ll;
    } return r;
}

// With Modulus (Can be 1e9+7 or 998244353)
ll bcpow(ll a, ll b, ll m=MOD){
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % m;
        a = a * a % m; b >>= 1ll;
    } return r;
}