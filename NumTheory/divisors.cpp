// Divisors
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi A = divisors(12), B = divisors(11);
    for(auto a : A) cout << a << " "; cout << endl;
    for(auto a : B) cout << a << " "; cout << endl;
    cout << practicalNum(11) << endl;
    cout << practicalNum(12) << endl;

    return 0;
}