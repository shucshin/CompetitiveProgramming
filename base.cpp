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
const ll MOD = 1e9+7;
const ll INF = 1e9;

ll ascii(char c) {return ('0' <= c && c <= '9') ? ((ll)c-'0') : ((ll)c-'A'+10);}
char asciiR(ll x) {return (0 <= x && x <= 9) ? char(x+'0') : char(x+'A'-10);}

//==From base a to base 10==
ll to_base10(string s, ll a) {
    ll n = s.length(), p = 1, num = 0;
    RFOR(i,0,n) {
        if(ascii(s[i]) >= a) return -1;
        num += ascii(s[i])*p;
        p *= a;
    } return num;
}

//==From base 10 to base b==
string from_base10(ll x, ll b) {
    string num = "";
    while(x > 0) {
        num += asciiR(x%b);
        x /= b;
    } reverse(all(num));
    return num;
}

//==From base a to b [a -> 10 -> b]==
string convert_base(string s, ll a, ll b) {
    return from_base10(to_base10(s,a),b);
}

void solve() {
    
}

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    // ll n; cin >> n;
    string s = "3F";
    cout << convert_base(s,16,10) << endl;
    return 0;
}