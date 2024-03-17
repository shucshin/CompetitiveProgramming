#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n';
#define pb push_back
#define sq(a) (a)*(a)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
const int INF = 1e9;
const ll MOD = 1e9+7;

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

// ==Number of triplets v[i]+v[j]+v[k] that equal n==
vector<vi> threeSum(vi &v, int n) {
    sort(all(v)); vector<vi> ans;
    FOR(i,0,v.size()-2) {
        if(i > 0 && v[i-1] == v[i]) continue;
        int k = -v[i]+n, a = i+1, b = v.size()-1;
        while(a < b) {
            if(v[a] + v[b] == k) {
                ans.pb({v[i], v[a], v[b]});
                a++, b--;
                while(a < b && v[a] == v[a-1]) a++;
                while(a < b && v[b] == v[b+1]) b--;
            }
            if(v[a] + v[b] > k) b--;
            if(v[a] + v[b] < k) a++;
        }
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vi A = {1,2,3,4,5};
    cout << divisible_pairs(A) << endl;

    return 0;
}