#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using ii = pair<ll,ll>;
using vii = vector<ii>;
using vi = vector<int>;
ll gcd(ll a, ll b) {return a == 0? b: gcd(b%a,a);}
ll lcm(ll a, ll b) {return a * (b / gcd(a,b));}
#define pb push_back
#define rep(x,n) for (int i = x; i < n; i++)
#define repc(i,a,b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define lb(v,a) lower_bound(v.begin(),v.end(),a)-v.begin()
#define ub(v,a) upper_bound(v.begin(),v.end(),a)-v.begin()-1
    struct segtree{
        ll n;
        vii st;

        void build(vector<ll>& nums, int v, int tl, int tr){
            if (tl == tr) st[v] = {nums[tl], nums[tl]};
            else{
                int mid = (tl + tr) / 2;
                build(nums,2*v,tl,mid);
                build(nums,2*v + 1,mid+1,tr);
                st[v] = {st[2*v].first + st[2*v+1].first, min(st[2*v].second,st[2*v].first+st[2*v+1].second)};
            }
        }

        void build(vector<ll>& nums){
            n = nums.size();
            st.resize(4 * n);
            build(nums,1,0,n-1);
        }

        // ll query(int v, int tl, int tr, int l, int r){
        //     if (tl > r || tr < l) return 0;
        //     if (tl >= l && tr <= r) return st[v];
        //     int mid = (tl + tr) / 2;
        //     return query(2*v,tl,mid,l,r) + query(2*v+1,mid+1,tr,l,r);
        // }

        ii query(int l, int r){
            return st[1]; 
        }
        void update(int v, int tl, int tr, int pos){
            if (tl == tr && tl == pos) st[v] = {-st[v].first, -st[v].second};
            else{
                int mid = (tl + tr) / 2;
                if (pos <= mid) update(2*v,tl,mid,pos);
                else update(2*v+1,mid+1,tr,pos);
                st[v] = {st[2*v].first + st[2*v+1].first, min(st[2*v].second,st[2*v].first+st[2*v+1].second)};


            }
        }
        void update(int pos){
            update(1,0,n-1,pos);
        }
    };
    
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        int jj = 0;
        while(jj < 10){
            int a; cin >> a; 
            string str; cin >> str; 
            vll nums(a);
            rep(0,a) if(str[i] == '(') nums[i] = 1; else nums[i] = -1;
            segtree segt; 
            segt.build(nums);
            int b; cin >> b;
            cout << "Test " << jj+1 << ":\n";
            rep(0,b){
                int x; cin >> x; 
                if(x == 0){
                    ii aux = segt.query(1,1);
                    //cout << segt.st[2].first << " , " << segt.st[2].second << " : " << segt.st[3].first << " , " << segt.st[3].second << '\n';                  
                    if(aux.first == 0 && aux.second >= 0) cout << "YES" << endl;
                    else cout << "NO" << endl;
                } else {
                    --x;
                    segt.update(x);
                }
            }
            jj++;
        }
    }