// Number Theory
using lli = __int128;
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return (a/gcd(a,b))*b;}

//==cin >> __int128==
istream& operator >> (istream& in, __int128& v) {
    string s; in >> s; v = 0;
    for(auto &it:s) if(isdigit(it)) v=v*10+it-'0';
    if(s[0]=='-') v*=-1;
    return in;
}

// cout << __int128
ostream& operator << (ostream &os, const __int128 &v) {
    if(v==0) return (os << "0");
    string s; __int128 num=v;
    if(v<0) os<<'-', num=-num;
    for(;num>0;num/=10) s.pb((char)(num%10)+'0');
    reverse(all(s));
    return (os<<s);
}

// a, b are the largest two divisors before x, find x
ll two_divisors(ll a, ll b) {
    if(b%a==0) return b*(b/a);
    return b*a/gcd(a,b);
}

// Check if n is a Square Num
bool isSquare(ll n) {
    if(n <= 0) return false;
    ll x = sqrt(n);
    return x*x==n;
}

// Check if n is a power of 2
bool isPowerTwo(ll n) {
    if(!n) return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

vi factorials(ll n) {
    vi f(n+1,1);
    FOR(i,1,n+1) f[i] = f[i-1]*i%MOD;
    return f;
}