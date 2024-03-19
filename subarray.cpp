//==Kadane's Algorithm
tuple<ll,int,int> maxSubarray(vi &A) {
    int n = A.size(), l=0, r=0;
    ll ans = A[0], sum = 0, mp = -1;
    FOR(i,0,n) {
        sum += A[i];
        if(sum > ans) {ans = sum; l = mp+1; r = i;}
        if(sum <= 0) {sum = 0; mp = i;}
    }
    return {ans, l, r};
}

tuple<ll,int,int> minSubarray(vi &A) {
    int n = A.size(), l=0, r=0;
    ll ans = A[0], sum = 0, mp = -1;
    FOR(i,0,n) {
        sum += A[i];
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