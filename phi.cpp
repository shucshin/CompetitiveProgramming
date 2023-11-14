// Euler's Totient Function (Phi-Function)
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
    vi phi(n+1);
    FOR(i,0,n+1) phi[i] = i;
    FOR(i,2,n+1) {
        if(phi[i]==i) {
            for(int j=i; j <= n; j+=i) phi[j]-=phi[j]/i;
        }
    }
    return phi;
}

//==Phi Function from 1 to n using divisor sum property. Worse case O(n log n)==
vi phi_1_to_n(ll n) {
    vi phi(n+1); phi[0]=0; phi[1]=1;
    FOR(i,2,n+1) phi[i] = i-1;
    FOR(i,2,n+1) {
        for(ll j = 2*i; j <= n; j+=i) phi[j] -= phi[i];
    }
    return phi;
}


// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   cout << phi(13) << endl; // 12
   vi A = phi_n(21), B = phi_1_to_n(21);
   FOR(i,1,22) cout << A[i] << " "; cout << endl;
   FOR(i,1,22) cout << B[i] << " "; cout << endl;

    return 0;
}