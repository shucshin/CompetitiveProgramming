#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(),(a).end()
#define lb(v,a) lower_bound(all(v),a)-v.begin()
#define ub(v,a) upper_bound(all(v),a)-v.begin()
const ll INF = 1e9;

//==Longest Increasing Subsequence==
ll LIS(vi &A) {
    vi dp;
    for(auto x : A) {
        ll i = lb(dp,x);
        if (i==dp.size()) (dp.pb(x));
        else dp[i] = x;
    }
    return dp.size();
}

//==Longest Increasing Subsequence==
vi LIS_(vi &v) {
    int n = v.size();
    vi ans, sub, si, path(n, -1);
    FOR(i,0,n) {
        if(sub.empty() || sub[sub.size()-1] < v[i]) {
            path[i] = sub.empty() ? -1 : si[sub.size()-1];
            sub.pb(v[i]);
            si.pb(i);
        } else {
            int idx = lb(sub,v[i]);
            path[i] = idx == 0 ? -1 : si[idx-1];
            sub[idx] = v[i];
            si[idx] = i;
        }
    }
    int t = si[si.size()-1];
    while(t != -1) {
        ans.pb(v[t]);
        t = path[t];
    }
    reverse(all(ans));
    return ans;
}

// Longest Common Subsequence
string LCS(string s, string t) {
    int n = s.length(), m = t.length();
    vector<vi> dp(n+1,vi(m+1));
    FOR(i,0,n+1) {
        FOR(j,0,m+1) {
            !i||!j ? dp[i][j] = 0 : (s[i-1]==t[j-1] ? dp[i][j]=dp[i-1][j-1]+1 : dp[i][j]=max(dp[i-1][j],dp[i][j-1]));
        }
    }
    int i = n, j = m, k = dp[n][m]; vector<char> c(k+1); c[k] = '\0';
    while(i && j) {
        s[i-1]==t[j-1] ? (c[k-1] = s[i-1], i--, j--, k--) : (dp[i-1][j]>dp[i][j-1] ? i-- : j--);
    }
    string lcs(all(c)); lcs.erase(lcs.length()-1,1);
    return lcs;
} 

// Longest Palindromic Subsequence
string LPSubseq(string &s) {
    string t = s;
    reverse(all(t));
    return LCS(s,t);
}

// Longest Palindromic Subsequence
//int a, b = s.length(); vvi dp(MAXN,vi(MAXN,-1));
/* int LPSubseq(string &s, int a, int b) {
    if(a==0 || b==0) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    if(s[a-1]==s[n-b]) return dp[a][b] = 1+LPSubseq(s,a-1,b-1);
    else return dp[a][b] = max(LPSubseq(s,a-1,b),LPSubseq(s,a,b-1));
} */

//==Longest Subsequence of A having LCM at most K
int LongestSubsequenceLCM(vi A, int k) {
    int n = A.size(); map<ll,ll> m;
    FOR(i,0,n) m[A[i]]++;
    vi v(k+1,0);
    for(auto a : m) {
        if(a.fst <= k) {
            for(int i=1;;++i) {
                if(a.fst*i > k) break;
                v[a.fst*i] += a.snd;
            }
        } else break;
    }
    ll lcm = 0, ans = 0; //if lcm==0, no answer
    FOR(i,1,n+1) {if(v[i] > ans) {ans = v[i]; lcm = i;}}
    vi u; FOR(i,0,n) if(lcm%A[i]==0) u.pb(A[i]); // subsequence
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vi A = {3,4,-1,0,6,2,3};
    cout << LIS(A) << endl;

    string s = "azAZ", t = "aAzZ";
    cout << LCS(s,t) << endl;
    string a = "aAZ", b = "aazz";
    cout << LCS(a,b) << endl;
    

    return 0;
}