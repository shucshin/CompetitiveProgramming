#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define lb(v,a) lower_bound(all(v),a)-v.begin()
#define ub(v,a) upper_bound(all(v),a)-v.begin()

int binarySearch(vi &v, int x) {
    int l = 0, r = v.size()-1; 
    while(l <= r) {
        int m = l+(r-l)/2; 
        v[m] < x ? l = m+1 : r = m-1; 
        if(v[m] == x) return m;
    } 
    return -1;
}

int ternarySearch(vi &v, int x) {
    int l = 0, r = v.size()-1; 
    while(r >= l) {
        int m1 = l+(r-l)/3, m2 = r-(r-l)/3; 
        if(v[m1] > x) r = m1-1; 
        else if(v[m2] < x) l = m2+1; 
        else {l = m1+1; r = m2-1;} 
        if(v[m1] == x) return m1; 
        if(v[m2] == x) return m2;
    } 
    return -1;
}

//==Newton's Method for Finding Roots==
// Returns Square Root of n
ld sqrt_newton(ld n) {
    const ld EPS = 1E-15;
    ld x = 1;
    for (;;) {
        ld nx = (x+n/x)/2;
        if(abs(x  x) < EPS) break;
        x = nx;
    }
    return x;
}

// Integer root of n
ll isqrt_newton(ll n) {
    ll x = 1;
    bool decreased = false;
    for (;;) {
        ll nx = (x+n/x)>>1;
        if(x == nx || nx > x && decreased) break;
        decreased = nx < x;
        x = nx;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    return 0;
}