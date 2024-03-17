// Linear Diophantine Equations
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

//==Recursive Extended GCD==
/* Finds x, y for ax + by = gcd(a,b) */
ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {x = 1; y = 0; return a;}
    ll x1, y1, d = gcd_ext(b, a % b, x1, y1);
    x = y1; y = x1-y1*(a/b);
    return d;
}

//==Linear Diophantine Equation==
// ax + by = c, find x, y
bool find_any_sol(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd_ext(abs(a), abs(b), x0, y0);
    if(c%g) return false;
    x0 *= c / g;
    y0 *= c / g;
    if(a < 0) x0 = -x0;
    if(b < 0) y0 = -y0;
    return true;
}

void shift_sol(ll &x, ll &y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

ll find_all_sol(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!find_any_sol(a, b, c, x, y, g)) return 0;
    a /= g; b /= g;
    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;
    shift_sol(x, y, a, b, (minx-x)/b);
    if(x < minx) shift_sol(x, y, a, b, sign_b);
    if(x > maxx) return 0;
    ll lx1 = x;

    shift_sol(x, y, a, b, (maxx-x)/b);
    if (x > maxx) shift_sol(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift_sol(x, y, a, b, -(miny-y)/a);
    if(y < miny) shift_sol(x, y, a, b, -sign_a);
    if(y > maxy) return 0;
    ll lx2 = x;

    shift_sol(x, y, a, b, -(maxy-y)/a);
    if (y > maxy) shift_sol(x, y, a, b, sign_a);
    ll rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if(lx > rx) return 0;
    return (rx-lx)/abs(b)+1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}