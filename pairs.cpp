//==Number of pairs that sum k==
int pairSumK(vi &A, ll k) {
    int n = A.size(), ans = 0;
    map<ll,ll> m;
    FOR(i,0,n) {
        if(m.find(k-A[i]) != m.end()) {
            ans += m[k-A[i]];
        }
        m[A[i]]++;
    } return ans;
}

//==Divisible pairs in an Array==
ll divisible_pairs(vi &A) {
    int n = A.size(), ans = 0;
    map<ll,ll> frq;
    FOR(i,0,n) frq[A[i]]++;
    FOR(i,0,n) {
        for(int j = 1; sq(j) <= A[i]; j++) {
            if(A[i]%j==0) {
                (A[i]==sq(j)) ? ans+=frq[j] : ans+=frq[j]+frq[A[i]/j];
            }
        } ans--;
    }
    return ans;
}

//==Number of pairs of lower and upper case==
// Can swap lower to upper or viceversa max k times
ll pairsLowerUpper(int k, string s) {
    map<char,ll> m; ll ans = 0; ll available = 0;
    FOR(i,0,s.length()) m[s[i]]++;
    for(auto a : m) {
        char l = tolower(a.first), u = toupper(a.first);
        if(!m[l] && !m[u]) continue;
        else if(m[l] && m[u]) {
            ans += min(m[l], m[u]);
            available += abs(m[l]-m[u])/2;
            m[l] = 0; m[u] = 0;
        } else {
            available += max(m[l], m[u])/2;
            m[l] = 0; m[u] = 0;
        }}
    ans += min(available, k);
    return ans;
}