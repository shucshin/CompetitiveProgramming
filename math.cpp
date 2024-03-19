const ld PI = 3.1415926535897932384626433832795028841971; // acos(-1);

// Last number reachable as multiple of k in 1~n
ll multipleK(ll n, ll k) {
    return n/k*k;
}

// Partition x into x1,...,xk so that all of them <= y
// e.g. x=12 y=5 => x={4,4,4}. x=11 y=5 => x={3,4,4}
tuple<ll,ll,ll> partition(ll x, ll y) { // elems, operations, maximized min
    ll a = (x+y-1)/y; // ceil(x/y);
    return {a,a-1,x/a};
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