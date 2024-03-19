// Number of bubble sort swaps to sort array
//==Inversion Count with Merge Sort==
ll merge(vi &v, vi &A, int l, int m, int r) {
    int i = l, j = m, k = l; ll inv = 0;
    while(i <= m-1 && j <= r) {
        if(v[i] <= v[j]) A[k++] = v[i++];
        else {A[k++] = v[j++]; inv += (m-i);}
    }
    while(i <= m-1) A[k++] = v[i++];
    while(j <= r) A[k++] = v[j++];
    FOR(i,l,r+1) v[i] = A[i];
    return inv;
}

ll mergeSort(vi &v, vi &A, int l, int r) {
    int m; ll inv = 0;
    if(l < r) {
        m = (l+r)/2;
        inv += mergeSort(v,A,l,m);
        inv += mergeSort(v,A,m+1,r);
        inv += merge(v,A,l,m+1,r);
    } return inv;
}

ll inversionCount(vi &v) {
    vi A(v.size());
    return mergeSort(v,A,0,v.size()-1);
}

//==Inversion Index==
struct comparepq {bool operator() (pi a, pi b) {return a.fst > b.fst;}};
int inversionIndex(vi &A) { 
    if(A.size() <= 1) return 0;
    /*==Ascending==
    struct comparepq {bool operator() (pi a, pi b) {return a.fst > b.fst;}};
    priority_queue<pi, vector<pi>, comparepq > pq; */
    priority_queue<pi> pq;
    FOR(i,0,A.size()) {pq.push({A[i],i});} A.clear(); int ans = 0;
    while(!pq.empty()) {
        pi p = pq.top(); pq.pop();
        int y = lb(A,p.snd); ans += p.snd - y;
        A.insert(lower_bound(all(A),p.snd),p.snd);
    } return ans;
}

//==Swaps(any i,j) needed to sort array==
void swap(vi &A, int i, int j) {
    ll tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int min_swaps(vi A, int n) {
    int ans = 0; vi tmp = A; sort(all(tmp));
    map<ll,ll> m; // indexes of A
    FOR(i,0,n) m[A[i]] = i; // m[5] = index of 5
    FOR(i,0,n) {
        if(A[i] != tmp[i]) {
            ans++;
            int j = A[i];
            // swap elem with idx it should be in
            swap(A,i,m[tmp[i]]); 
            // update idx
            m[j] = m[tmp[i]]; 
            m[tmp[i]] = i;
        }
    }
    return ans;
}

//==Swaps in a binary tree to make sorted perfect binary tree==
bool mergeBT(vi &v, int l, int m, int r) {
    if(v[m] < v[m+1]) return 0;
    FOR(i,l,m+1) swap(v[i],v[i+(r-l+1)/2]); 
    return 1;
}

void swapsBT(vi &v, int l, int r, int &ans) {
    if(l < r) {
        int m = l+(r-l)/2;
        swapsBT(v,l,m, ans);
        swapsBT(v,m+1,r, ans);
        if(mergeBT(v,l,m,r)) ans++;
    }
}

//==Num of inversions (i < j | s_i > s_j)==
ll inversions(string &s, ll N=1) { // string s repeats N times
    vector<char> A; N %= MOD;
    ll inv = 0, n = s.length();
    FOR(i,0,n) {
        ll a = lb(A,s[i]), b = ub(A,s[i]);
        inv += (A.size()-b)*((N*(N+1)/2)%MOD);
        inv += a*((N*(N-1)/2)%MOD);
        inv %= MOD; if(inv < 0) inv += MOD;
        A.insert(A.begin()+a,s[i]);
    }
    return inv;
}

//==Num of inversions when only 0's and 1's==
ll inversions01(vi &A) {
    ll inv = 0, k = 0, n = A.size();
    FOR(i,0,n) {
        if(A[i] == 1) k++;
        else inv += k;
    }
    return inv;
}

//==Num of inversions that works only on alphabets==
ll inversionsA(string &s, ll N=1) { // string s repeats N times
    vi cnt(26,0); ll inv = 0, n = s.length(); N%=MOD;
    FOR(i,0,n) {
        ll idx = s[i]-'a';
        FOR(j,idx+1,26) {inv += cnt[j];}
        cnt[idx]++;
    } inv *= N;
    ll g = 0;
    FOR(i,0,26) {
        FOR(j,i+1,26) {
            g += (cnt[i]*cnt[j]);
        }
    }
    inv += g*((N*(N-1)/2)%MOD);
    inv%=MOD; if(inv < 0) inv += MOD;
    return inv;
}