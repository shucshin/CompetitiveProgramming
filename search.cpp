#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'

int binarySearch(vi &v, int x) {
    int l = 0, r = v.size()-1; 
    while(l <= r) {
        int m = l+(r-l)/2; 
        v[m] < x ? l = m+1 : r = m-1; 
        if(v[m] == x) return m;
    } 
    return -1;
}

int ternarySearch(vi &v, int x) {
    int l = 0, r = v.size()-1; 
    while(r >= l) {
        int m1 = l+(r-l)/3, m2 = r-(r-l)/3; 
        if(v[m1] > x) r = m1-1; 
        else if(v[m2] < x) l = m2+1; 
        else {l = m1+1; r = m2-1;} 
        if(v[m1] == x) return m1; 
        if(v[m2] == x) return m2;
    } 
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    return 0;
}