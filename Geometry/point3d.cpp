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
#define rall(a) (a).rbegin(), (a).rend()
#define lb(v,a) lower_bound(all(v),a)-v.begin()
#define ub(v,a) upper_bound(all(v),a)-v.begin()
const ll MOD = 1e9+7; // 998244353
const ll MXN = 2e5+5;
const ll INF = 1e18;
const ld EPS = 1e-12;

struct pt {
    ftype x, y, z;
    pt() {}
    pt(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    pt& operator+=(const pt &t) {x += t.x; y += t.y; z += t.z; return *this;}
    pt& operator-=(const pt &t) {x -= t.x; y -= t.y; z -= t.z; return *this;}
    pt& operator*=(ftype t) {x *= t; y *= t; z *= t; return *this;}
    pt& operator/=(ftype t) {x /= t; y /= t; z /= t; return *this;}
    pt operator+(const pt &t) const {return pt(*this) += t;}
    pt operator-(const pt &t) const {return pt(*this) -= t;}
    pt operator*(ftype t) const {return pt(*this) *= t;}
    pt operator/(ftype t) const {return pt(*this) /= t;}
};  pt operator*(ftype a, pt b) {return b * a;}

//==Dot Product== 
/* Product of the length of the first vector by the length of the 
   projection of the second vector onto the first one */
ftype dot(pt a, pt b) {return a.x * b.x + a.y * b.y + a.z * b.z;}

//==Cross Product==
pt cross(pt a, pt b) {
    return pt(a.y * b.z - a.z * b.y,
              a.z * b.x - a.x * b.z,
              a.x * b.y - a.y * b.x);
}

ftype triple(pt a, pt b, pt c) {return dot(a, cross(b, c));}

//==Planes Intersection==
pt intersect(pt a1, pt n1, pt a2, pt n2, pt a3, pt n3) {
    pt x(n1.x, n2.x, n3.x);
    pt y(n1.y, n2.y, n3.y);
    pt z(n1.z, n2.z, n3.z); 
    pt d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return pt(triple(d, y, z),
              triple(x, d, z),
              triple(x, y, d)) / triple(n1, n2, n3);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}