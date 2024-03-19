//==Binary Search==
int binarySearch(vi &A, int x) {
    int l = 0, r = A.size()-1; 
    while(l <= r) {
        int m = l+(r-l)/2; 
        A[m] < x ? l = m+1 : r = m-1; 
        if(A[m] == x) return m;
    } 
    return -1;
}

//==Binary Search the Answer==
ll l = 0, r = INF, ans = -1;
while(l <= r) {
    ll m = l+(r-l)/2;
    f(m) ? (l = m+1, ans = m) : r = m-1;
} 
cout << ans << endl;

//==Binary Search the Answer w/ Float==
ld l = 0, r = INF;
FOR(_,0,100) {
    ld m = l+(r-l)/2.0;
    f(m) ? l = m : r = m;
} 
printf("%0.7Lf\n",l);

//==Ternary Search==
int ternarySearch(vi &A, int x) {
    int l = 0, r = A.size()-1; 
    while(r >= l) {
        int m1 = l+(r-l)/3, m2 = r-(r-l)/3; 
        if(A[m1] > x) r = m1-1; 
        else if(A[m2] < x) l = m2+1; 
        else {l = m1+1; r = m2-1;} 
        if(A[m1] == x) return m1; 
        if(A[m2] == x) return m2;
    } 
    return -1;
}

//==Ternary Search the Answer==
ll l = 0, r = INF;
while(r-l > 3) {
    ll m1 = l+(r-l)/3, m2 = r-(r-l)/3;
    ll a = f(m1), b = f(m2);
    a > b ? l = m1+1 : r = m2-1;
} FOR(m,l,r+1) f(m);

//==Ternary Search the Anwer w/ Float==
ld l = 0, r = INF;
FOR(_,0,100) { // while(r-l > EPS) {
    ld m1 = l+(r-l)/3, m2 = r-(r-l)/3;
    ld a = f(m1), b = f(m2);
    a > b ? l = m1 : r = m2;
} 
printf("%0.9Lf\n",f(l));

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