#include<bits/stdc++.h>
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
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return (a/gcd(a,b))*b;}

//==cout << __int128==
ostream&operator<<(ostream& dest, __int128_t value){
    ostream::sentry s(dest);
    if(s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128]; char* d = end(buffer);
        do {--d; *d = "0123456789"[tmp%10]; tmp /= 10;} while (tmp != 0);
        if(value < 0) {--d; *d = '-';}
        int len = end(buffer)-d;
        if(dest.rdbuf()->sputn(d,len) != len) {dest.setstate(ios_base::badbit);}
    }
    return dest;
} 

//==Binary Exponentiation==
lli binpow(lli a, lli b) {
    lli r = 1; 
    while(b) {
	if(b & 1ll) r *= a; 
	a *= a; b >>= 1ll;
    } return r;
}

ll bcpow(ll a, ll b, ll m=MOD){
    ll r = 1;
    while(b) {
        if(b&1ll) r = r * a % m;
        a = a * a % m; b >>= 1ll;
    } return r;
}

//==Sum from a to b==
ll gauss(ll a, ll b) {
    return (b-a+1)*(a+b)/2;
}

//==Sum of odd numbers from a to b w/ exponents==
ll sum_odd(ll a, ll b) {
    return binpow((b+1)/2,2)-binpow(a/2,2);
}

//==Sum of odd numbers from a to b==
ll sumOdd(ll a, ll b) {
    if(a%2==0) a++;
    if(b%2==0) b--;
    ll n = (b-a+2)/2;
    return n*(a+b)/2;
}

//==Sum of first n potencies of base x==
lli potencySum(ll x, ll n) { // 1 + x + x^2 + ... + x^n
    if((n)*log2(x) >= 100) return LLONG_MAX;
    return (binpow(x,n+1)-1)/(x-1);
}

//==Zig-Zag Sum of first n potencies of base x==
lli potencySumZ(ll x, ll n) { // 1 - x + x^2 - x^3 + ... 
    if((n)*log2(x) >= 100) {return n%2 ? LLONG_MIN : LLONG_MAX;}
    if(n%2) return -(binpow(x,n+1)-1)/(x+1);
    return (binpow(x,n+1)+1)/(x+1);
}

//==Check if k is sum of first n potencies for any base x==
bool sum_of_potencies(ll k) {
    FOR(n,2,60) { // first n potencies
        ll l = 2, r = INF;
        while(l <= r) {
            ll x = l+(r-l)/2; // base
            lli sum = potencySum(x,n);
            if(sum == k) {return true;}
            sum<=k ? l=x+1 : r=x-1;
        }
    } return false;
}

// Binary GCD
ll gcd_bin(ll a, ll b) {
    if(!a || !b) return a | b;
    unsigned shift = __builtin_ctz(a|b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if(a > b) swap(a,b);
        b -= a;
    } while(b);
    return a << shift;
}

//==Recursive Extended GCD==
/* Finds x, y for ax + by = gcd(a,b) */
ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {x = 1; y = 0; return a;}
    ll x1, y1, d = gcd_ext(b, a % b, x1, y1);
    x = y1; y = x1-y1*(a/b);
    return d;
}

// Iterative Extended GCD
ll gcd_exti(ll a, ll b, ll &x, ll &y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while(b1) {
        ll q = a1/b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

//==Linear Diophantine Equation==
// ax + by = c, find x, y
bool find_any_sol(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd_ext(abs(a), abs(b), x0, y0);
    if(c%g) return false;
    x0 *= c / g;
    y0 *= c / g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

void shift_sol(ll &x, ll &y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_sol(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!find_any_solution(a, b, c, x, y, g)) return 0;
    a /= g; b /= g;
    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;
    shift_solution(x, y, a, b, (minx-x)/b);
    if(x < minx) shift_solution(x, y, a, b, sign_b);
    if(x > maxx) return 0;
    ll lx1 = x;

    shift_solution(x, y, a, b, (maxx-x)/b);
    if (x > maxx) shift_solution(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_solution(x, y, a, b, -(miny-y)/a);
    if(y < miny) shift_solution(x, y, a, b, -sign_a);
    if(y > maxy) return 0;
    ll lx2 = x;

    shift_solution(x, y, a, b, -(maxy-y)/a);
    if (y > maxy) shift_solution(x, y, a, b, sign_a);
    ll rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if(lx > rx) return 0;
    return (rx-lx)/abs(b)+1;
}


//==N-th Fibonacci==
ll fib(ll n) {
    ll a = 0, b = 1;
    FOR(i,0,n) {
        ll tmp = a + b;
        a = b; b = tmp;
    } return a;
}

//==Fibonacci Numbers==
// returns {F_n,F_n+1}
pi fib(ll n) {
    if(n == 0) return {0, 1};
    auto p = fib(n >> 1);
    ll c = p.fst * (2*p.snd-p.fst);
    ll d = p.fst * p.fst+p.snd*p.snd;
    if(n & 1) return {d, c+d};
    else return {c, d};
}

//==Sieve of Eratosthenes==
vi primes(ll n) {
	vi q, p(n+1,1); p[0]=0; p[1]=0; 
	for(ll i=2; i*i<=n; i++) {
	if(p[i]) {for(ll j=i*i; j<=n; j+=i) p[j]=0;}} 
	FOR(i,0,n+1) {if(p[i]) q.pb(i);}
	return q;
}

//==Linear Sieve==
// returns minimum prime factor lp[i]
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

//==Check if n is prime==
bool isPrime(ll n) {
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n%2==0 || n%3==0) return 0;
    for(ll i = 5; i*i <= n; i+=6) {
        if(n%i==0 || n%(i+2)==0) return 0;
    } return 1;
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

//==Phi Function (Euler's Totient Function)==
/* Counts number of ints [1,n] that are coprime to n
   Coprime = 2 nums that gcd 1. */
ll phi(ll n) {
    ll ans = n;
    for(ll i = 2; i*i <= n; i++) {
        if (n%i==0) {
            while (n%i==0) n /= i;
            ans -= ans/i;
        }
    }
    if(n > 1) ans-=ans/n;
    return ans;
}

//==Phi Function from 1 to n. O(n log log n)==
vi phi_n(ll n) {
    vi phi(n + 1);
    FOR(i,0,n+1) phi[i] = i;
    FOR(i,2,n+1) {
        if(phi[i]==i) {
            for(int j=i; j <= n; j+=i) phi[j]-=phi[j]/i;
        }
    }
    return phi;
}

//==Practical Numbers==
bool practicalNum(vi &d, ll n) {
	ll r = 0; bool p; 
	for(auto a : d) {if(r+1 < a) break; r+=a;} 
	(r+1<n*2) ? p=0 : p=1; 
	return p;
}

//==Divisors of N==
vi divisors(ll n) {
	vi d; d.pb(1); d.pb(n); 
	for(ll i=2; i*i<=n; i++) {
		if(n% i==0) i*i==n ? d.pb(i) : (d.pb(i), d.pb(n/i));} 
	return d;
}

//==Divisors of N in Set==
set<ll> divisorsSet(ll n) {
	set<ll> d; d.insert(1); d.insert(n); 
	for(ll i=2; i*i<=n; i++) {
		if(n% i==0) i*i==n ? d.insert(i) : (d.insert(i), d.insert(n/i));} 
	return d;
}

//==Number of Divisors==
ll numberOfDivisors(ll n) {
    ll ans = 1;
    for(ll i = 2; (ll)i*i <= n; i++) {
        if(n%i==0) {
            ll e = 0;
            do {e++; n /= i;} while (n%i==0);
            ans *= e+1;
        }
    }
    if(n > 1) ans *= 2;
    return ans;
}

//==Sum of Divisors==
ll sumOfDivisors(ll n) {
    ll ans = 1;
    for(ll i = 2; (ll)i*i <= n; i++) {
        if(n%i==0) {
            ll e = 0;
            do {e++; n /= i;} while (n%i==0);
            ll sum = 0, pow = 1;
            do {sum += pow; pow *= i;} while (e-- > 0);
            ans *= sum;
        }
    }
    if(n > 1) ans *= (1+n);
    return ans;
}

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
    FOR(a,2,m) {inv[a] = m-(ll)(m/a)*inv[m%a]%m;}
    return inv;
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


// Codeforces Round 595 Div. 3 | C. Good Numbers
//==Find next number x >= n that is a sum of distinct power of 3==
ll distinctPower3(ll n) {
    vi A; ll pos0, pos2 = -1;
    while(n > 0) {
        A.pb(n%3);
        if(A.back()==2) pos2 = A.size()-1;
        n /= 3;
    } A.pb(0);
    if(pos2 != -1) {
        pos0 = find(A.begin()+pos2, A.end(), 0)-A.begin();
        A[pos0] = 1; RFOR(i,0,pos0) A[i] = 0;
    }
    ll x = 0, pw = 1;
    FOR(i,0,A.size()) {x += pw*A[i]; pw *= 3;}
    if(A.back()==1) x = pw/3;
    return x;
}

// Codeforces Round 903 Div. 3 | D. Divide and Equalize
//==Determine if it's possible to equalize all elems by
//  choosing a divisor x of a_i and do a_i/=x and a_j*=x ==
bool div_equalize(vi &A) {
    map<ll,ll> m; ll n = A.size();
    FOR(i,0,n) { // decompose each elem into prime divisors
        ll x = 2;
        while(x*x <= A[i]) {
            while(A[i]%x == 0) {
                m[x]++, A[i] /= x;
            } x++;
        }
        if(A[i] > 1) m[A[i]]++;
    } // prime divisors freq added
    bool can = 1;
    for(auto x : m) {
        can &= (x.snd%n==0); 
    } // if all freq of each prime divisor == n then YES
    return can;
}

// g++ A.cpp -o A && ./A < input.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        isDiffPrime(a,b) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}