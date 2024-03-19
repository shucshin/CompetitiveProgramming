// Longest Prefix Suffix
vi LPS(string s) {
    vi A(s.length(),0);
    FOR(i,1,s.length()) {
        int j = A[i-1];
        while(j && s[i]!=s[j]) j = A[j-1];
        if(s[i]==s[j]) j++;
        A[i] = j;
    } return A;
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
        if(i <= r) p[i] = min(r-i+1ll, p[i-l]);
        while(i+p[i] < n && a[p[i]] == a[i+p[i]]) ++p[i];
        if(i+p[i]-1 > r) l=i, r=i+p[i]-1;
    }
    FOR(i,0,n) {if(p[i] == m) z.pb(i-m-1);}
    return z;
}