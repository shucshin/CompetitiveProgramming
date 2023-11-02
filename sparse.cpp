#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)

vector<vi> sparse_table(vi &v) {
    int n = v.size(), k = (int)log2(n)+1; vector<vi> st(n,vi(k));
    FOR(i,0,n) st[i][0] = v[i];
    FOR(j,1,k+1) {
        for(int i=0; i+(1<<j)<=n; i++) {
            // RMQ :: Minimum <, Maximum >
            st[i][j-1] > st[i+(1<<(j-1))][j-1] ? st[i][j]=st[i][j-1] : st[i][j]=st[i+(1<<(j-1))][j-1];
            // RSQ
            // st[i][j] = st[i][j-1] + st[i+(1<<(j-1))][j-1];
        }
    } return st;
}

// Minimum <=, Maximum >=
int RMQ(int l, int r, vector<vi> &st) {
    int m, j = (int)log2(r-l+1);
    st[l][j] >= st[r-(1<<j)+1][j] ? m=st[l][j] : m=st[r-(1<<j)+1][j];
    return m;
}

ll RSQ(int l, int r, vector<vi> &st) {
    ll ans = 0; int k = (int)log2(st.size())+1;
    for(int j=k; j>=0; j--) {
        if(l+(1<<j)-1 <= r) {ans += st[l][j]; l += 1<<j;}
    } return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    vi u = {1,2,3,4,5,6,7,8,9,0};
    vi v = { 3, 7, 2, 5, 8, 9 };
    vector<vi> st = sparse_table(v);

    FOR(i,0,st.size()) {
        FOR(j,0,st[i].size()) {
            cout << st[i][j] << " ";
        } cout << endl;
    }

    cout << RMQ(0,5,st) << endl;
    cout << RMQ(3,5,st) << endl;
    cout << RMQ(2,4,st) << endl;
    cout << RSQ(0,5,st) << endl;
    cout << RSQ(3,5,st) << endl;
    cout << RSQ(2,4,st) << endl;
    return 0;
}