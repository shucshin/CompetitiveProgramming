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
#define sq(a) (a)*(a)
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
const ld PI = 3.1415926535897932384626433832795028841971; // acos(-1);

struct pt {
    ftype x, y;
    pt() {}
    pt(ftype x, ftype y): x(x), y(y) {}
    pt& operator+=(const pt &t) {x += t.x; y += t.y; return *this;}
    pt& operator-=(const pt &t) {x -= t.x; y -= t.y; return *this;}
    pt& operator*=(ftype t) {x *= t; y *= t; return *this;}
    pt& operator/=(ftype t) {x /= t; y /= t; return *this;}
    pt operator+(const pt &t) const {return pt(*this) += t;}
    pt operator-(const pt &t) const {return pt(*this) -= t;}
    pt operator*(ftype t) const {return pt(*this) *= t;}
    pt operator/(ftype t) const {return pt(*this) /= t;}
};  pt operator*(ftype a, pt b) {return b * a;}

//==Dot Product== 
/* Product of the length of the first vector by the length of the 
   projection of the second vector onto the first one */
ftype dot(pt a, pt b) {return a.x * b.x + a.y * b.y;}

//===Cross Product== 
/* Cross Product, know if two lines are parallel example
   if you have ABCD points, check if AB parallel CD
   (B-A).x*(D-C).y-(B-A).y*(D-C).x == 0 , which is cross of (B-A),(D-C)*/
ftype cross(pt a, pt b){return (a.x * b.y)-(a.y * b.x);}

//==Norm of a (squared length)== |a|^2 = a*a
ftype norm(pt a) {return dot(a, a);}

//==Length of a: |a| = sqrt(a*a)==
double abs(pt a) {return sqrt(norm(a));}

//==Projection of a onto b: (a*b)/|b|==
double proj(pt a, pt b) {return dot(a, b) / abs(b);}

//==Angle between vectors: arccos((a*b)/(|a|*|b|))==
// pt A, B, C; a = B-A, b = B-C; B is midpoint
ld angle(pt a, pt b) {return acos(dot(a, b) / abs(a) / abs(b));}

//==Line Intersection==
/* a initial point
   d direction */
pt intersect(pt a1, pt d1, pt a2, pt d2) {return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;}

//==Distance from a to b==
ld length(pt a, pt b) {return sqrt(sq(a.x-b.x)+sq(a.y-b.y));}

//==ABC angle==
ld angulo(pt a, pt b, pt c) {
    return acos((sq(length(b,a))*sq(length(b,c))*sq(length(a,c)))/(2*length(a,b)*length(b,c)));
}

/*==Line Slope (Pendiente)==
  y = mx + b
  m = (y2-y1)/(x2-x1)
  Parallel      = (m1 == m2)
  Perpendicular = (m1*m2 == -1) */
ld slope(pt a, pt b) {
    if(b.x-a.x == 0) return INF;
    return ((b.y-a.y)/(b.x-a.x));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // Set to 10 decimal digits
    cout << fixed << setprecision(10) << ld(10.123456789101112131415) << endl;

    return 0;
}