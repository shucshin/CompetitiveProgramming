#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
#define endl '\n';
#define pb push_back
#define sq(a) (a)*(a)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
const int INF = 1e9;
const ll MOD = 1e9+7;
const ld pi = 3.1415926535897932384626433832795028841971;

//==Gauss's Circle Problem== # of lattice points within circle of radius r.
ll lattice_points(ll r) { // 1e9 lattice points with r = 18000
    ll points = 0;
    FOR(i,1,r+1) points += floor(sqrt(sq(r)-sq(i)));
    return 1ll+4ll*(r+points);
}

//==Circumscribed Circle== Polygon of v vertices, each side length s, return area.
ld circumscribed_circle(ld v, ld s) {
    ld area = s/(2*sin(pi/v));
    area*=(area*pi);
    return area;
}

//==Sierpinski Triangle==
void sierpinski(int n) {
    vector<vector<char> > v(n,vector<char>(2*n-1,'.'));
    v[0][n-1] = '*';
    FOR(i,1,n) {
        FOR(j,0,2*n-1) {
            int c = 0;
            if(j-1>=0 && v[i-1][j-1]=='*') c++; // check left-up
            if(j+1<2*n-1 && v[i-1][j+1]=='*') c++; // check right-up
            if(c==1) v[i][j] = '*'; // only one of them is *
        }
    }
    FOR(i,0,n) {FOR(j,0,2*n-1) cout << v[i][j]; cout << endl;}
}

//==Spiral Square Perimeter==
ll spiralSquare(ll n) {
    return 2 + n*(n+1) + n; // n is length of side of square
}

//==a^b < c^d==
bool abcd(ll a, ll b, ll c, ll d) {
    return (b*log(a) <= d*log(c));
}

//==Dice Moves to get n==
// Can only move to adjacent faces
ll diceMoves(ll n) {
    if(n==1) return -1;
    ll ans = (n/11)*2;
    ans += ((n%11)/5);
    if(((n%11)%5) != 0) ans++;
    if(n == 7) ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int k; cin >> k;
    int l = 0, r = 18000;
    while(l <= r) {
        int m = (l+r)/2;
        ll ppl = lattice_points(m);
        (ppl < k) ? l = m+1 : r = m-1;
    }
    cout << l << endl;
    return 0;
}
