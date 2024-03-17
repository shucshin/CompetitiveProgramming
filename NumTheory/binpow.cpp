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

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << gauss(1,100) << endl;
    cout << sum_odd(1,100) << endl;
    cout << sumOdd(1,100) << endl;
    
    return 0;
}