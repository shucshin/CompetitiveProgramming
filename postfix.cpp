#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vc = vector<char>;
#define endl '\n'
#define rep(i,a,b) for(int i = a; i < b; i++)

string tobinary(ll n) {string s = ""; for(int i = (int)log2(n); i >= 0; i--) {(1&(n>>i)) ? s+="1" : s+="0";} return s;}


ll postfix(string t) {
    stack<char> s;
    rep(i,0,t.length()) {
        if(isdigit(t[i])) s.push(t[i]-'0');
        else {
            ll b = s.top(); s.pop();
            ll a = s.top(); s.pop();
            if(t[i] == '+') s.push(a+b);
            if(t[i] == '-') s.push(a-b);
            if(t[i] == '*') s.push(a*b);
            if(t[i] == '/') s.push(a/b);
        }
    } return s.top();
}

int prec(char c) {int p; (c=='^')?p=3:((c=='/'||c=='*')?p=2:((c=='+'||c=='-')?p=1:p=-1));return p;}

string toPostfix(string t) {
    stack<char> stk; string s="";
    rep(i,0,t.length()) {
        if(isalpha(t[i])||isdigit(t[i])) s+=t[i];
        else if(t[i]=='(') stk.push('(');
        else if(t[i]==')') {
            while(stk.top()!='(') {
                s += stk.top(); stk.pop();
            } stk.pop();
        }
        else {
            while(!stk.empty() && prec(t[i]) <= prec(stk.top())) {
                s += stk.top(); stk.pop();
            } stk.push(t[i]);
        }
    }
    while(!stk.empty()) {s += stk.top(); stk.pop();}
    return s;
}

string toInfix(string t) {
    stack<string> stk;
    rep(i,0,t.length()) {
        if(isalpha(t[i])||isdigit(t[i])) {
            string s(1,t[i]);
            stk.push(s);
        }
        else {
            string a = stk.top(); stk.pop(); 
            string b = stk.top(); stk.pop();
            stk.push("(" + b + t[i] + a + ")");
        }
    }
    return stk.top();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    // vc v = {'4', '1', '2', '9', '3', '/', '*', '+', '5', '-', '*'};
    string u = "41293/*+5-*";
    string v = "abcde/*+f-*";
    cout << postfix(u) << endl;
    string s = "4*(1+2*(9/3)-5)";
    string t = "a+b*(c^d-e)^(f+g*h)-i";
    cout << toPostfix(s) << endl;
    cout << tobinary(1501) << endl;
    cout << toInfix(v) << endl;

    char c = 'A';
    string z(1,c);
    cout << z << endl;

    return 0;
}