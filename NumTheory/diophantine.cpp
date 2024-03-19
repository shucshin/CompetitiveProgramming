// Linear Diophantine Equations

//==Linear Diophantine Equation==
// ax + by = c, find x, y (gcd_ext in euclidean.cpp)
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