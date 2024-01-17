// Binary Exponentiation
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
const ll INF = 1e9;
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return (a/gcd(a,b))*b;}

//==cin >> __int128==
istream& operator >> (istream& in, __int128& v) {
    string s; in >> s; v = 0;
    for(auto &it:s) if(isdigit(it)) v=v*10+it-'0';
    if(s[0]=='-') v*=-1;
    return in;
}

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

// With Modulus (Can be 1e9+7 or 998244353)
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


// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cout << gauss(1,100) << endl;
    cout << sum_odd(1,100) << endl;
    cout << sumOdd(1,100) << endl;


    return 0;
}