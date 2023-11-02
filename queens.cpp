#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = a; i < b; i++)

vi row(8);
int a, b, lineCounter;

bool canPlace(int r, int c) {
    FOR(prev, 0, c) {
        if((row[prev] == r) || abs(row[prev]-r) == abs(prev-c)) return false;
    } return true;
}

void backtrack(int c) {
    if((c==8) && row[b] == a) {
        printf("%2d      %d", ++lineCounter, row[0]+1);
        FOR(j,1,8) printf(" %d", row[j]+1); cout << endl; return;
    }
    FOR(r,0,8) {
        if((c==b) && (r!=a)) continue;
        if(canPlace(r,c)) row[c] = r, backtrack(c+1);
    }
}

bitset<30> rw, ld, rd;
int n, ans = 0;
vector<vi> board;

void backtrackN(int c) {
    if(c==n) {++ans; return;}
    FOR(r,0,n) {
        if(board[r][c] != '*' && !rw[r] && !ld[r-c+n-1] && !rd[r+c]) {
            rw[r] = ld[r-c+n-1] = rd[r+c] = true;
            backtrackN(c+1);
            rw[r] = ld[r-c+n-1] = rd[r+c] = false;
        } 
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--) {
        cin >> a >> b; a--; b--;
        row.assign(row.size(),0);
        lineCounter = 0;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        backtrack(0);
        if(t) cout << endl;
    }
    return 0;
}
