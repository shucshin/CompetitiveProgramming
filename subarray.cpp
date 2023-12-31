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
int subarraySum(vi &v, int k) {
    unordered_map<int,int> m;
    int ans = 0, cur = 0;
    FOR(i,0,v.size()) {
        cur += v[i];
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

// ==Longest Substring without Repeating Chars==
int LSWRC(string &s) {
    set<char> alphabet;
    int ans = 0, l = 0;
    for(int i = 0; i < s.length(); i++) {
        while(alphabet.count(s[i])) {
            alphabet.erase(s[l]); l++;
        }
        alphabet.insert(s[i]);
        ans = max(ans, i-l+1);
    }
    return ans;
}
        
// ==Longest Substring without repeating chars==
string LSWRChar(string &s) {
    int l=0, r=0, i=0, j=0, m=0;
    unordered_set<char> a;
    while(r < s.size()) {
        if(a.find(s[r]) == a.end()) {
            a.insert(s[r]);
            if(r-l+1 > m) {m = r-l+1; i = l; j = r;}
            r++;
        } else {a.erase(s[l]); l++;}
    }
    return s.substr(i,m);
}

//==Longest Substring with K unique chars==
string LKS(string &s, int k) {
    int i=0, j=0, ans=-1;
    unordered_map<char,int> m;
    while(j < s.size()) {
        m[s[j]]++;
        while(m.size() > k) {
            m[s[i]]--;
            if(!m[s[i]]) m.erase(s[i]);
            i++;
        }
        if(m.size()==k) ans=max(ans,j-i+1);
        j++;}
    return s.substr(i,ans);
}

//==Minimum substring of s that contains all chars of t==
string minWindow(string s, string t) {
    vi m(256,0);
    int a=0, b=INT_MAX, c=0, i=0, j=0;
    FOR(i,0,t.length()) {if(!m[t[i]]) c++; m[t[i]]++;}
    while(j < s.length()) {
        m[s[j]]--;
        if(!m[s[j]]) c--;
        while(!c) {
            if(b > j-i+1) {a = i; b = min(b,j-i+1);}
            m[s[i]]++;
            if(m[s[i]] > 0) c++;
            i++;
        }
        j++;
    }
    return (b != INT_MAX) ? s.substr(a,b) : "-1";
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    string s1 = "erogijaerogjeraoig", s2 = "gao";
    cout << minWindow(s1,s2) << endl;

    s1 = "GEEKSFORGEEKS";
    cout << LSWRC(s1) << endl;

    //s1 = "aabacbebebe";
    cout << LKS(s1,3) << endl;

    return 0;
}