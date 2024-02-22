#include <bits/stdc++.h>
using namespace std;
using ll = long long; // %lld
using ld = long double; // %0.5Lf
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)
#define all(a) (a).begin(), (a).end()
const ld EPS = 1e-9;

struct pt {ld x, y;};

struct seg {
    pt p, q; ll id;
    ld get_y(ld x) const {
        if(abs(p.x-q.x) < EPS) return p.y;
        return p.y + (q.y-p.y)*(x-p.x)/(q.x-p.x);
    }
};

bool intersect1d(ld l1, ld r1, ld l2, ld r2) {
    if(l1 > r1) swap(l1, r1);
    if(l2 > r2) swap(l2, r2);
    return max(l1,l2) <= min(r1,r2) + EPS;
}

int vec(const pt &a, const pt &b, const pt &c) {
    ld s = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const seg &a, const seg &b) {
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const seg &a, const seg &b) {
    ld x = max(min(a.p.x,a.q.x), min(b.p.x,b.q.x));
    return a.get_y(x) < b.get_y(x) - EPS;
}

struct event {
    ld x; ll tp, id;
    event() {}
    event(ld x, ll tp, ll id) : x(x), tp(tp), id(id) {}
    bool operator<(const event& e) const {
        if(abs(x-e.x) > EPS) return x < e.x;
        return tp > e.tp;
    }
};

set<seg> s;
vector<set<seg>::iterator> where;
set<seg>::iterator prev(set<seg>::iterator it) {return it == s.begin() ? s.end() : --it;}
set<seg>::iterator next(set<seg>::iterator it) {return ++it;}

// Search pair of intersecting segments
pair<ll,ll> solve(const vector<seg> &a) {
    int n = a.size(); vector<event> e;
    //FOR(i,0,n) {
    for (int i = 0; i < n; ++i) {
        e.pb(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.pb(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(all(e)); s.clear(); where.resize(a.size());
    //FOR(i,0,e.size()) {
    for(size_t i = 0; i < e.size(); ++i) {
        ll id = e[i].id;
        if(e[i].tp == +1) {
            set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if(nxt != s.end() && intersect(*nxt, a[id])) return mp(nxt->id, id);
            if(prv != s.end() && intersect(*prv, a[id])) return mp(prv->id, id);
            where[id] = s.insert(nxt, a[id]);
        } else {
            set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
            if(nxt != s.end() && prv != s.end() && intersect(*nxt, *prv)) return mp(prv->id, nxt->id);
            s.erase(where[id]);
        }
    }
    return mp(-1, -1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<seg> lines;
    int n; cin >> n;
    int x1, y1, x2, y2;
    FOR(i,1,n+1) {
        cin >> x1 >> y1 >> x2 >> y2;
        pt p, q;
        p.x = x1, p.y = y1;
        q.x = x2, q.y = y2;
        seg s;
        s.p = p; s.q = q; s.id = i;
        lines.pb(s);
    }
    pair<ll,ll> ans = solve(lines);
    if(ans.fst == -1 && ans.snd == -1) {cout << "NO" << endl; return 0;}
    cout << "YES" << endl;
    cout << ans.fst << " " << ans.snd << endl;
    return 0;
}