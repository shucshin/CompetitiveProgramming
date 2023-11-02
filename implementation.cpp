#include <bits/stdc++.h>
using namespace std;
using bint = __int128;
using ll = long long; // %lld
using ld = long double; // %0.5Lf
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define endl '\n'
#define sz(a) (a).size()
#define fst first
#define snd second
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
const ll MOD = 1e9+7;

//==1 to n-k+1, reverse substring of length k
string reverseK(string &s, int k) {
    int n = s.length();
    string pfx = s.substr(k-1,n-k+1), sfx = s.substr(0,k-1);
    if(n%2==k%2) reverse(all(sfx));
    return pfx+sfx; // S_k...S_n S_1...S_k-1
}

//==Smallest number with length m and sum of digits s==
string getMin(int m, int s) {
    if(m == 1) {return to_string(s);}
    string a = ""; bool first = 1;
    while((m-1)*9 > s && m > 0) {
        if(first) {first = 0; a += "1"; s--; m--; continue;}
        a += "0"; m--;
    }
    a += to_string(s-(m-1)*9); m--;
    FOR(i,0,m) a += "9";
    return a;
}

//==Largest number with length m and sum of digits s==
string getMax(int m, int s) {
    string a = "";
    while(s >= 9) {a += "9"; m--; s-=9;}
    if(s >= 1) {a += to_string(s); m--;}
    FOR(i,0,m) a += "0";
    return a;
}

//==Prefix needed from s to form t==
int pfxSformT(string s, string t) {
    map<char,vi> letters; int n = s.length();
    FOR(i,0,n) letters[s[i]].pb(i+1);
    vi alpha(26,0); int ans = 0;
    FOR(i,0,t.length()) alpha[t[i]-'a']++;
    FOR(i,0,25) {
        if(alpha[i]) ans = max(ans,letters[i+'a'][alpha[i]-1]);
    }
    return ans;
}

// Balanced Tunnel
//==Number of cars(b) that overtook other cars(a)==
int overrun(vi &a, vi &b) {
    int n = a.size(); vi c(n), res(n);
    rep(i,0,n) c[b[i]] = i; // turn of that index that goes out
    rep(i,0,n) res[i] = c[a[i]]; // order of that car that goes out
    int fined = 0, x=-1;
    rep(i,0,n) {
        (res[i] > x) ? x = res[i] : fined++;
    }
    return fined;
}

// Codeforces Round 508 Div.2 | C. Gambling
//==Maximize difference with other player==
ll maximizeDiff(priority_queue<ll> &A, priority_queue<ll> &B) {
    ll asum=0, bsum=0; int player = 0;
    while(!A.empty() || !B.empty()) {
        ll a = A.top(), b = B.top();
        if(a > b && !player) {
            asum += a; A.pop();
        } else if(a < b && player) {
            bsum += b; B.pop();
        } else player ? A.pop() : B.pop();
        player ^= 1;
    } 
    return asum-bsum;
}

// Number of different strings by removing 2 consecutive characters
int diffStrings(string s) {
    int ans = 1; 
    rep(i,0,s.length()-2) ans += s[i]!=s[i+2]; 
    return ans;
}

//==Make Palindrome with given string==
string makePalindrome(string s) {
	map<char,int> m;
	rep(i,0,s.length()) m[s[i]]++;
	int odd=0; char c;
	for(auto a : m) {
    	if(a.second%2!=0) {odd++; c=a.first;}
    }
	if(odd>1 || odd&&s.length()%2==0) return "-1";
	string x="", y="";
   	for(auto a : m) {
		string s(a.second/2,a.first);
		x=x+s; y=s+y;
    }
	return (odd) ? (x+c+y) : (x+y);
}

// Codeforces Round 867 Div. 3 | E. Making Anti-palindromes
//==Number of operations needed to make s anti-palindrome==
int makeAntipalindrome(string s) {
    int n = s.length(); map<char,int> m;
    FOR(i,0,n) m[s[i]]++; bool cant = 0;
    for(auto a : m) {
        if(m[a.fst]*2 > n) cant = 1;
    }
    if(n%2 || cant) return -1;
    vi same(26);
    FOR(i,0,n/2) {
        same[s[i]-'a'] += s[i]==s[n-i-1];
        // add to index of the alphabet if same on both sides
    } // doing just #same+1/2 won't work cuz what if aaaabbcdefghbbaaaa
    int ans = 0; priority_queue<int> pq;
    FOR(i,0,26) {
        if(same[i]) pq.push(same[i]);
        // if there is repeating alphabet, add to pq
    }
    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        a--; b--; ans++;
        if(a) pq.push(a);
        if(b) pq.push(b);
    }
    if(!pq.empty()) ans += pq.top();
    return ans;
}

// Codeforces Round 855 Div. 3 | E. Unforgivable Curse
//==Swap letters of s at distance k or k+1 to make same as t==
void canBeSame(string s, string t, int k) {
    bool can = 1; int n = s.length();
    if(k > n) {
    	(s==t) ? printf("YES\n") : printf("NO\n"); return;
    } if(k > n/2) {
        if(s.substr(n-k,n-(n-k)*2) != t.substr(n-k,n-(n-k)*2)) can=0;
    }
    map<char,int> ms, mt; 
    FOR(i,0,n) ms[s[i]]++; 
    FOR(i,0,n) mt[t[i]]++;
    for(auto a : ms) {if(ms[a.first] != mt[a.first]) {can=0; break;}}
    can ? printf("YES\n") : printf("NO\n");
}

// Codeforces Round 906 Div. 2 | D. Doremy's Connecting Plan
//==Unite all elems by sum of all A_k of cur elems 
bool can_connect(vi &A, ll c) {
    ll n = A.size(); vector<pi> B(n-1);
    FOR(i,1,n) {
        B[i-1] = {(i+1)*c-A[i], A[i]};
    } sort(all(B));
    ll sum = A[0];
    FOR(i,0,n-1) {
        if(sum < B[i].fst) return false;
        sum += B[i].snd;
    } return true;
}

// Codeforces Round 905 Div. 3 | F. You Are So Beautiful
//==Num of subarrays A[l,r] such that it occurs as subsequence only once in A==
ll beautiful_subarrays(vi &A) {
    ll n = A.size(), ans = 0;
    vi pfx(n,0); set<ll> S;
    FOR(i,0,n) {
        if(i) pfx[i] = pfx[i-1];
        if(S.find(A[i])==S.end()) pfx[i]++;
        S.insert(A[i]);
    } S.clear();
    RFOR(i,0,n) {
        if(S.find(A[i])==S.end()) ans += pfx[i];
        S.insert(A[i]);
    } return ans;
}

// Codeforces Round 906 Div. 2 | C. Smilo and Monsters
/* Given an array, make all elems 0 by doing 2 types of moves:
   - A[i]--, x++;
   - if(x >= A[i]) A[i] = 0, x = 0; */
ll smilo_monsters(vi &A) {
    ll n = A.size(), k = 0, sum = accumulate(all(A),0ll);
    sort(rall(A));
    vi pfx(n+1); FOR(i,1,n+1) pfx[i]=pfx[i-1]+A[i-1];
    while(pfx[k] < sum/2) k++; // 2nd move is only used on k biggest nums that form half of the sum
    return (sum+1)/2+k;
}

// g++ A.cpp -o A && ./A < input.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    string s = "helloworld";
    cout << reverseK(s,1) << endl;
    cout << reverseK(s,2) << endl;
    cout << reverseK(s,3) << endl;
    return 0;
}