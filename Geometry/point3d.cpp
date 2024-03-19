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