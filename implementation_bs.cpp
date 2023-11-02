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
const ll MOD = 1e9+7;
const ll INF = 1e9;

// Codeforces Round 878 Div. 3 | D. Wooden Toy Festival
//==Divide into 3 sections such that each of the 3 pivots cover reachable range==
// e.g. 1 2 4 5 30 60 -- pivots in 3,30,60 | ans = 2, pivot in 3 reaches 1 to 5 with range 2
ll waitingTime(vi &A) {
    int n = A.size(); sort(all(A));
    ll l = 0, r = INF, ans=0;
    while(l <= r) {
        ll m = l+(r-l)/2, i = 0, j = n-1;
        while(i < n && A[i]-A[0] <= 2*m) i++;
        while(j >= 0 && A[n-1]-A[j] <= 2*m) j--;
        (i > j || A[j]-A[i] <= 2*m) ? (r = m-1, ans = m) : (l = m+1);
    }
    return ans;
}

 

// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi A(n); FOR(i,0,n) cin >> A[i];
        cout << waitingTime(A) << endl;
    }
    return 0;
}