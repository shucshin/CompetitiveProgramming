//==Prefix Sum==
vi prefixSum(vi &A) {
    int n = A.size(); vi pfx(n+1);
    FOR(i,1,n+1) pfx[i] = pfx[i-1] + A[i-1];
    return pfx;
} // Sum A[3,5] is pfx[5]-pfx[3-1]

//==Suffix Sum==
vi suffixSum(vi &A) {
    int n = A.size(); vi sfx(n+1);
    RFOR(i,0,n) sfx[i] = sfx[i+1] + A[i];
    return sfx;
} // Sum A[2,3] is sfx[2-1]-sfx[3]

//==Max, Min Subarray Sum== 
pi kadane(vi &pfx) {
    ll max_subarray_sum = pfx[1], min_prefix_sum = pfx[0];
    FOR(i,1,n+1) {
        max_subarray_sum = max(max_subarray_sum, pfx[i]-min_prefix_sum);
        min_prefix_sum = min(min_prefix_sum, pfx[i]);
    }
    return {max_subarray_sum, min_prefix_sum};
}

//==2D Prefix Sum== 
vector<vi> prefixSum2D(vector<vi> &A) { // 1-indexed
    int n = A.size();
    vector<vi> pfx(n,vi(n,0));
    FOR(i,1,n) {
        FOR(j,1,n) {
            pfx[i][j] = A[i][j]+pfx[i-1][j]+pfx[i][j-1]-pfx[i-1][j-1];
        }
    }
    return pfx;
}

// Sum of [x1,x2]x[y1,y2] | 1-indexed
ll sum2D(ll x1, ll x2, ll y1, ll y2, vector<vi> &pfx) {
    return pfx[x2][y2] - pfx[x1-1][y2] - pfx[x2][y1-1] + pfx[x1-1][y1-1];
} // x: 3~5, y: 2~3 = sum2D(3,5,2,3,pfx)

//==Precalculate Prefix Bitwise for Query==
vector<vi> prefixBIT(vi &A) {
    int bits = 32, n = A.size();
    vector<vi> pfx(bits,vi(n));
    FOR(i,0,bits) {
        pfx[i][0] = ((A[0] >> i) & 1);
        FOR(j,1,n) {
            pfx[i][j] = ((A[j] >> i) & 1ll);
            pfx[i][j] += pfx[i][j-1];
        }
    }
    return pfx;
}

//==[A_l & ... & A_r] or [A_l | ... | A_r]==
ll rangeBIT(ll l, ll r, vector<vi> &pfx) {
    ll ans = 0, bits = 32;
    FOR(i,0,bits) {
        ll x;
        (l==0) ? (x = pfx[i][r]) : (x = pfx[i][r]-pfx[i][l-1]);
        if(x==r-l+1) ans = (ans | (1ll << i)); // AND
        // if(x != 0) ans = (ans | (1 << i)); // OR
    }
    return ans;
}