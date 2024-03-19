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