// Fibonacci Numbers
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
pi fibs(ll n) {
    if(n == 0) return {0, 1};
    auto p = fibs(n >> 1);
    ll c = p.fst * (2*p.snd-p.fst);
    ll d = p.fst * p.fst+p.snd*p.snd;
    if(n & 1) return {d, c+d};
    else return {c, d};
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cout << fib(1) << endl;
    cout << fib(15) << endl;
    pi p = fibs(15);
    cout << p.fst << " " << p.snd << endl;

    return 0;
}