#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define LSOne(a) ((a) & -(a))

class Fenwick {
private:
    vi ft;
public:
    Fenwick(int m) {ft.assign(m+1,0);}
    void build(const vi &f) {int m = (int)f.size()-1; ft.assign(m+1,0); for(int i=1; i <= m; ++i) {ft[i] += f[i]; if(i+LSOne(i) <= m) ft[i+LSOne(i)] += ft[i];}}
    Fenwick(const vi &f) {build(f);}
    Fenwick(int m, const vi &s) {vi f(m+1,0); for(int i=0; i < (int)s.size(); ++i) ++f[s[i]]; build(f);}
    ll rsq(int j) {ll sum = 0; for(;j;j-=LSOne(j)) sum += ft[j]; return sum;}
    ll rsq(int i, int j) {return rsq(j) - rsq(i-1);}
    void update(int i, ll v) {for(; i < (int)ft.size(); i+=LSOne(i)) ft[i] += v;}
    int select(ll k) {int l = 1, h = ft.size()-1; for(int i=0; i < 30; ++i) {int m = (l+h)/2; (rsq(1,m) < k) ? l=m : h=m;} return h;}
};

class RUPQ {
private:
    Fenwick ft;
public:
    RUPQ(int m) : ft(Fenwick(m)) {}
    void range_update(int ui, int uj, int v) {ft.update(ui, v); ft.update(uj+1, -v);}
    ll point_query(int i) {return ft.rsq(i);}
};

class RURQ  {
private:
    RUPQ rupq;
    Fenwick purq;
public:
    RURQ(int m) : rupq(RUPQ(m)), purq(Fenwick(m)) {} 
    void range_update(int ui, int uj, int v) {rupq.range_update(ui, uj, v); purq.update(ui, v*(ui-1)); purq.update(uj+1, -v*uj);}
    ll rsq(int j) {return rupq.point_query(j)*j - purq.rsq(j);}
    ll rsq(int i, int j) {return rsq(j) - rsq(i-1);}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    vi f = {0,0,1,0,1,2,3,2,1,1,0};               // index 0 is always 0
    Fenwick ft(f);
    printf("%lld\n", ft.rsq(1, 6)); // 7 => ft[6]+ft[4] = 5+2 = 7
    printf("%d\n", ft.select(7)); // index 6, rsq(1, 6) == 7, which is >= 7
    ft.update(5, 1); // update demo
    printf("%lld\n", ft.rsq(1, 10)); // now 12
    printf("=====\n");
    RUPQ rupq(10);
    RURQ rurq(10);
    rupq.range_update(2, 9, 7); // indices in [2, 3, .., 9] updated by +7
    rurq.range_update(2, 9, 7); // same as rupq above
    rupq.range_update(6, 7, 3); // indices 6&7 are further updated by +3 (10)
    rurq.range_update(6, 7, 3); // same as rupq above
    // idx = 0 (unused) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10
    // val = -          | 0 | 7 | 7 | 7 | 7 |10 |10 | 7 | 7 | 0
    for (int i = 1; i <= 10; i++)
        printf("%d -> %lld\n", i, rupq.point_query(i));
    printf("RSQ(1, 10) = %lld\n", rurq.rsq(1, 10)); // 62
    printf("RSQ(6, 7) = %lld\n", rurq.rsq(6, 7)); // 20
    return 0;
}