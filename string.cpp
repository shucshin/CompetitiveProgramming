#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define prtfor(a) FOR(i,0,a.size()) cout << a[i] << " \n"[i==a.size()-1];
#define prtfore(a) for(auto it=a.begin(); it!=a.end(); ++it) cout << *it << " \n"[it==--a.end()];

// Longest Prefix Suffix
vi LPS(string s) {
    vi v(s.length(),0);
    FOR(i,1,s.length()) {
        int j = v[i-1];
        while(j && s[i]!=s[j]) j = v[j-1];
        if(s[i]==s[j]) j++;
        v[i] = j;
    } return v;
}

// Knuth-Morris-Pratt
vi KMP(string s, string t) {
    int n = s.length(), m = t.length();
    vi lps = LPS(t), kmp;
    int i=0, j=0;
    while(n-i >= m-j) {
        if(s[i] == t[j]) {i++; j++;}
        if(j==m) {kmp.pb(i-j); j = lps[j-1];}
        else if(i < n && s[i] != t[j]) {
            j ? j = lps[j-1] : i++;
        }
    }
    return kmp;
}

// Z algorithm
vi Z(string s, string t) {
    string a = t+"$"+s; int n = a.length(), m = t.length();
    vi p(n), z;
    for(int i=1, l=0, r=0; i < n; ++i) {
        if(i <= r) p[i] = min(r-i+1, p[i-l]);
        while(i+p[i] < n && a[p[i]] == a[i+p[i]]) ++p[i];
        if(i+p[i]-1 > r) l=i, r=i+p[i]-1;
    }
    FOR(i,0,n) {if(p[i] == m) z.pb(i-m-1);}
    return z;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    vi lps = LPS("aabaaaabaab");
    prtfor(lps);

    string s1 = "aaabaabaaaaacaabbaaabaaaabaabaaaabaa";
    string s2 = "aabaa";
    vi kmp = KMP(s1,s2);
    prtfor(kmp);
    vi z = Z(s1,s2);
    prtfore(z);

    return 0;
}

