// Treap = Tree + Heap (Cartesian Tree)
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
const ll MOD = 1e9+7;
const ll INF = 1e9;

typedef struct item* pitem;
struct item {
    int val, pr;
    item *l, *r;
    item() {}
    item(int val) : val(val), pr(rand()), l(0), r(0) {}
    item(int val, int pr) : val(val), pr(pr), l(0), r(0) {}
};

void split(pitem t, int val, pitem &l, pitem &r) {
    if(!t) l = r = 0;
    else if(t->val <= val) split(t->r, val, t->r, r), l = t;
    else split(t->l, val, l, t->l), r = t;
}

void insert(pitem &t, pitem it) {
    if(!t) t = it;
    else if(it->pr > t->pr) split(t, it->val, it->l, it->r), t = it;
    else insert(t->val <= it->val ? t->r : t->l, it);
}

void merge(pitem &t, pitem l, pitem r) {
    if (!l || !r)  t = l ? l : r;
    else if(l->pr > r->pr) merge (l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
}

void erase(pitem &t, int val) {
    if(t->val == val) {
        pitem th = t;
        merge (t, t->l, t->r);
        delete th;
    } else erase(val < t->val ? t->l : t->r, val);
}

pitem unite(pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->pr < r->pr)  swap (l, r);
    pitem lt, rt;
    split (r, l->val, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}

int cnt(pitem t) {return t ? t->cnt : 0;}
void upd_cnt(pitem t) {if(t) t->cnt = 1 + cnt(t->l) + cnt (t->r);}


// g++ A.cpp -o A && ./A < in.txt > out.txt
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    



    return 0;
}