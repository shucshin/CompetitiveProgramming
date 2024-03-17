//fenwick tree i2 dimensions implementation 
#include <bits/stdc++.h>
using namespace std;
using lli = __int128;
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
#define rall(a) (a).rbegin(), (a).rend()
const ll MOD = 1e9+7;
const ll INF = 1e9;
#define MAXN 1024


    int ft[MAXN+1][MAXN+1];
    void update(int i0, int j0, int v){
        for(int i=i0+1;i<=MAXN;i+=i&-i)
        for(int j=j0+1;j<=MAXN;j+=j&-j)
            ft[i][j]+=v;
    }
    int get(int i0, int j0){
        int r=0;
        for(int i=i0;i;i-=i&-i)
        for(int j=j0;j;j-=j&-j)
            r+=ft[i][j];
        return r;
    }
    int query(int i0, int j0, int i1, int j1){
        return get(i1,j1)-get(i1,j0)-get(i0,j1)+get(i0,j0);
    }
    int x[MAXN+1][MAXN+1];
    int n;


    int main(){
        int a,b; cin >> a >> b; 
        FOR(i,0,a+1) FOR(j,0,a+1) ft[i][j] = x[i][j] = 0;
        FOR(i,1,a+1) {
            FOR(j,1,a+1) {
                char c; cin >> c;
                if(c == '*'){
                    //always update x matrix, and update subtracting val to x at position i,j
                    int val = 1;
                    update(i,j,val-x[i][j]);
                    x[i][j] = 1;
                }
            }
        }
        //query update
        int xx,y,val; cin >> xx >> y >> val;
        update(xx,y,val-x[xx][y]);
        x[xx][y] = val;

        FOR(_,0,b){
            //need to increase x2,y2 for sum query
            int x,y,x2,y2; cin >> x >> y >> x2 >> y2; x2++; y2++;
            cout << query(x,y,x2,y2) << endl;
        }
    }
