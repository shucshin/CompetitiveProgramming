// Euclidean Algorithms
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


// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    

    return 0;
}