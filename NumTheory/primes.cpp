// Prime Numbers
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

//==Sieve of Eratosthenes==
vi primes(ll n) {
	vi q, p(n+1,1); p[0]=0; p[1]=0; 
	for(ll i=2; i*i<=n; i++) {
	if(p[i]) {for(ll j=i*i; j<=n; j+=i) p[j]=0;}} 
	FOR(i,0,n+1) {if(p[i]) q.pb(i);}
	return q;
}

//==Check if n is prime==
bool isPrime(ll n) {
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(ll i = 5; i*i <= n; i+=6) {
        if(n%i==0 || n%(i+2)==0) return 0;
    } return 1;
}

// With Modulus (Can be 1e9+7 or 998244353)
ll bcpow(ll a, ll b, ll m=MOD){
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % m;
        a = a * a % m; b >>= 1ll;
    } return r;
}

//==Fermat Primality Test==
bool is_prime_fermat(ll n, ll m=5) {
    if(n < 4) return n == 2 || n == 3;
    FOR(i,0,m) {
        ll a = 2+rand()%(n-3);
        if(bcpow(a, n-1, n) != 1) return false;
    }
    return true;
}

//==Check if a^2-b^2 is prime==
bool isDiffPrime(ll a, ll b) {
    return (isPrime(a+b) && a-b==1) ? 1 : 0;
}

//==Minimum Prime Factor of N==
ll least_prime_factor(ll n) {
    if(n%2==0) return 2;
    for(ll i = 3; i*i <= n; i+=2) {
        if(n%i==0) return i;
    } return n;
}

//==Linear Sieve (Minimum Prime Factors)==
// lp[i] = Minimum Prime Factor of i
vi linear_sieve(ll n) {
    vi lp(n+1), pr; 
    for(ll i=2; i <= n; i++) {
        if(lp[i]==0) {lp[i]=i; pr.pb(i);}
        for(ll j=0; i*pr[j] <= n; j++) {
            lp[i*pr[j]] = pr[j];
            if(pr[j]==lp[i]) break;
        }
    }
    return lp;
}

//==Prime Factors of N==
vi prime_factors(ll n) {
    vi factors;
    while(n%2==0) {factors.pb(2); n /= 2;}
    for(ll i = 3; i <= sqrt(n); i+=2) {
        while(n%i==0) {factors.pb(i); n /= i;}
    }
    if(n>1) factors.pb(n);
    return factors;
}

//==Prime Factors of N with exponents==
map<ll,ll> prime_factorization(ll n) { // w/ exponents
    map<ll,ll> factors; // fst prime, snd exponent
    while(n%2==0) {factors[2]++; n /= 2;}
    for(ll i = 3; i <= sqrt(n); i+=2) {
        while(n%i==0) {factors[i]++; n /= i;}
    }
    if(n>1) factors[n]++;
    return factors;
}

//==Fermat's Factorization Method==
ll fact_fermat(ll n) {
    ll a = ceil(sqrt(n));
    ll b2 = a*a-n;
    ll b = round(sqrt(b2));
    while(b*b != b2) {
        a = a+1;
        b2 = a*a-n;
        b = round(sqrt(b2));
    }
    return a-b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi sieve = primes(30);
    for(auto a : sieve) cout << a << " "; cout << endl;
    vi A = linear_sieve(30);
    for(auto a : A) cout << a << " "; cout << endl;
    cout << isPrime(29) << " " << isPrime(30) << endl;
    cout << is_prime_fermat(29) << " " << is_prime_fermat(30) << endl;

    vi P = prime_factors(50);
    map<ll,ll> Q = prime_factorization(50);

    for(auto a : P) cout << a << " "; cout << endl;
    for(auto a : Q) cout << a.fst << "^" << a.snd << " "; cout << endl;

    return 0;
}