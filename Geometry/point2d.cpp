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

struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}
    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
    }
};
point2d operator*(ftype a, point2d b) {
    return b * a;
}

//==Dot Product== 
/* Product of the length of the first vector by the length of the 
   projection of the second vector onto the first one */
ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}

//==Norm of a (squared length)== |a|^2 = a*a
ftype norm(point2d a) {
    return dot(a, a);
}

//==Length of a: |a| = sqrt(a*a)==
double abs(point2d a) {
    return sqrt(norm(a));
}

//==Projection of a onto b: (a*b)/|b|==
double proj(point2d a, point2d b) {
    return dot(a, b) / abs(b);
}

//==Angle between vectors: arccos((a*b)/(|a|*|b|))==
double angle(point2d a, point2d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}

//==Cross Product==
ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}

//==Line Intersection==
/* a initial point
   d direction */
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    
    return 0;
}