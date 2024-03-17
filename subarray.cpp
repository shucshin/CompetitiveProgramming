#include <bits/stdc++.h>
using namespace std;
using bint = __int128;
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

//==Kadane's Algorithm
tuple<ll,int,int> maxSubarray(vi &v) {
    int n = v.size(), l=0, r=0;
    ll ans = v[0], sum = 0, mp = -1;
    FOR(i,0,n) {
        sum += v[i];
        if(sum > ans) {ans = sum; l = mp+1; r = i;}
        if(sum <= 0) {sum = 0; mp = i;}
    }
    return {ans, l, r};
}

tuple<ll,int,int> minSubarray(vi &v) {
    int n = v.size(), l=0, r=0;
    ll ans = v[0], sum = 0, mp = -1;
    FOR(i,0,n) {
        sum += v[i];
        if(sum < ans) {ans = sum; l = mp+1; r = i;}
        if(sum >= 0) {sum = 0; mp = i;}
    }
    return {ans, l, r};
}

//==Subarray Sum Equals K==
ll subarraySum(vi &A, ll k) {
    map<ll,ll> m;
    ll ans = 0, cur = 0;
    FOR(i,0,A.size()) {
        cur += A[i];
        if(cur == k) ans++;
        if(m.count(cur-k)) ans += m[cur-k];
        m[cur]++;
    } return ans;
}

//==Subarrays that sum Odd==
ll subarraySumOdd(vi &A) {
    ll odd = 0, c = 0, ans = 0, n = A.size();
    FOR(i,0,n) {
        if(A[i]&1) odd = !odd;
        if(odd) c++;
    }
    FOR(i,0,n) {ans += c; if(A[i]&1) c = (n-i-c);}
    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    return 0;
}