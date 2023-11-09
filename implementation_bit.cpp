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

string tobinary(ll n) {
    string s = "";
    RFOR(i,0,(int)log2(n)+1) {
        1&(n>>i) ? s+="1" : s+="0";
    } return s;
}


//==Two nums that are sum s and xor x==
pi sumxor(ll s, ll x) {
    ll z = (s-x)/2, a = 0, b = 0;
    for(int i = 0; i < (int)log2(s); i++) {
        ll xi = (x & (1 << i));
        ll zi = (z & (1 << i));
        if(xi && zi) {return {-1,-1};}
        if(!xi && zi) {
            a = ((1 << i) | a);
            b = ((1 << i) | b);}
        if(xi && !zi) {a = ((1 << i) | a);}}
    return {a,b};
}

//==Number of numers that have only 1 zero from a to b in binary==
ll only1zero(ll a, ll b) {
    ll i = (ll)log2(a), j = (ll)log2(b);
    ll first = (i*(i-1))/2, last = (j*(j-1))/2;
    i++; j++;
    ll x = (1LL << i)-1, y = (1LL << j)-1;
    for(ll k = i-2; k >= 0; k--) {
        if((x & ~(1LL << k)) < a) first++;
    } 
    for(ll k = j-2; k >= 0; k--) {
        if((y & ~(1LL << k)) <= b) last++;
    } 
    return last-first;
}

//==Maximal AND==
// Turn on k bits in total in any elem in array
ll maximalAND(vi &A, ll k) {
    vi bits(31,0); int n = A.size();
    FOR(i,0,n) {
        for(int j = (int)log2(A[i]); j >= 0; j--) {
            if(A[i] & (1 << j)) bits[j]++;
        } 
    }
    int bit = 30;
    while(k > 0) {
        while(bits[bit] == n || n-bits[bit] > k) bit--;
        if(bit < 0) break;
        FOR(i,0,n) {
            A[i] |= (1 << bit);
            k -= (n-bits[bit]);
            bits[bit] = n;
        }
    }
    ll ans = pow(2,31)-1;
    FOR(i,0,n) ans &= A[i];
    return ans;
}

//==Look Back==
// Minimum number of A[i]<<=1 needed to make array non-decreasing
ll look_back(vi &A) {
    ll n = A.size();
    ll ans = 0, cur = 0;
    FOR(i,1,n) {
        ll c = 0, a = A[i-1], b = A[i];
        if(A[i-1] <= A[i]) {
            while(a*2 <= b) a<<=1, c++;
            c = max(0ll,cur-c);
        } else {
            while(a > b) b<<=1, c++;
            c += cur;
        }
        ans += c; cur = c;
    } return ans;
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    return 0;
}