#include <bits/stdc++.h>
using namespace std;
using ll = long long; // %lld
using ld = long ld; // %0.5Lf
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

/**
 * C++ uses angles in radians
 * PI radians = 180 degrees
 * Degrees 0~360 | Radians 0PI~2PI
*/

//==Degrees to Radians==
ld toRadians(ld degrees) {return (degrees*PI)/180.0;}
//==Radians to Degrees==
ld toDegrees(ld radians) {return (radians*180.0)/PI;}

// Calculates location of a point given its parameters:
pt point(ld radians, ld radius=1, ld cx=0.0, ld cy=0.0) {
    point p; 
    p.x = cos(radius)*r+cx; 
    p.y = sin(radius)*r+cy;
    return p;
}

/* Oriented area of a triangle */
ll signed_area_parallelogram(pt p1, pt p2, pt p3) {return cross(p2 - p1, p3 - p2);}
ld triangle_area(pt p1, pt p2, pt p3) {return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;}
bool clockwise(pt p1, pt p2, pt p3) {return signed_area_parallelogram(p1, p2, p3) < 0;}
bool counter_clockwise(pt p1, pt p2, pt p3) {return signed_area_parallelogram(p1, p2, p3) > 0;}

/* Find area of simple polygon in O(N)*/
ld areaPolygon(const vector<pt>& fig) {
    ld res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        pt p = i ? fig[i - 1] : fig.back();
        pt q = fig[i];
        res += (p.x-q.x) * (p.y+q.y);
    }
    return fabs(res) / 2;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // Set to 10 decimal digits
    cout << fixed << setprecision(10) << ld(10.123456789101112131415) << endl;

    return 0;
}