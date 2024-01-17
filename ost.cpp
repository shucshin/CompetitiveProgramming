// Order Statistics Tree
#include <bits/stdc++.h> 
#include <bits/extc++.h>  // pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define nth(A,k) nth_element(A.begin(), A.begin()+k, A.end())
#define rnth(A,k) nth_element(A.begin(),A.begin()+k,v.end(), greater<ll>())
#define fo(a) find_by_order(a)
#define ok(a) order_of_key(a)
template<class T> using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    vi v = {10,2,7,4,39,4,8,1,5,3,35}; int n = v.size();
    nth(v,4); // idx 4, 5th elem is 5th smallest num.
    // Left = smaller nums than 5th elem.
    // Right = bigger nums than 5th elem.
    FOR(i,0,n) cout << v[i] << " "; cout << endl;

    rnth(v,4); // index 4, 5th element is 5th biggest num.
    // Left = bigger nums than 5th elem.
    // Right = smaller nums than 5th elem.
    FOR(i,0,n) cout << v[i] << " "; cout << endl;


    vi A = {71,15,65,23,10,2,7,50,4}; n = A.size();
    ost<ll> tree; FOR(i,0,n) tree.insert(A[i]);
    // O(log n) select
    cout << *tree.fo(0) << endl;    // smallest = 2
    cout << *tree.fo(n-1) << endl;  // largest = 71
    cout << *tree.fo(4) << endl;    // 5th smallest = 15
    // O(log n) rank
    cout << tree.ok(2) << endl;     // index 0 (rank 1)
    cout << tree.ok(71) << endl;    // index 8 (rank 9)
    cout << tree.ok(15) << endl;    // index 4 (rank 5)
    // Erase an elem
    tree.erase(10);                      // delete 10 if it exists
    tree.erase(*tree.fo(0));             // del smallest elem
    tree.erase(*tree.fo(tree.size()-1)); // del biggest elem
    
    return 0;
}