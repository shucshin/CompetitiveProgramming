// Divisors

//==Divisors of N==
vi divisors(ll n) {
	vi d; d.pb(1); if(n != 1) d.pb(n); 
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

//==Practical Numbers==
/* All positive integers smaller than n can be 
represented as sums of distinct divisors of n */
bool practicalNum(ll n) {
    vi d = divisors(n); sort(all(d));
	ll r = 0; bool p; 
	for(auto a : d) {if(r+1 < a) break; r+=a;} 
	(r+1<n*2) ? p=0 : p=1; 
	return p;
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