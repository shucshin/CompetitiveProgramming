// Bitmask
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,a,b) for(int i = (b)-1; i >= (a); i--)

string tobinary(ll n) {
    string s = "";
    RFOR(i,0,(int)log2(n)+1) {
        1&(n>>i) ? s+="1" : s+="0";
    } return s;
}

int main() {
    // Binary to decimal
    cout << stoi("1010",0,2) << endl;

    // Decimal to binary
    string b = ""; int z = 31;
    for(int i = (int)log2(z); i >= 0; i--) {
        (1&(z>>i)) ? b+="1" : b+="0";
    } cout << b << endl;

    // ASCII Char to binary
    cout << bitset<7>('A').to_string() << endl;

    // Left and Right shift operator
    int a = 11;
    cout << (a << 1) << endl; // mul 2^1
    cout << (a << 2) << endl; // mul 2^2
    cout << (a >> 1) << endl; // div 2^1
    cout << (a >> 2) << endl; // div 2^2

    // j-th bit is counted from right to left starting from 0
    // Turn on j-th bit and add
    int n = 10; // 1010
    n |= (1 << 2); // to turn on j-th bit and add
    // 1 << 2 is 0100
    cout << n << endl;

    // Check if j-th bit is set on
    int m = n & (1 << 0); // n is 1110 and j = 0
    cout << m << endl; // if 0, it's turned off

    // Clear/turn off j-th bit
    n &= ~(1 << 2); // ~ is neg, so i'm turning off only the index 2 bit and do & with n
    cout << n << endl; // n was 1110, ~(1 << 2) is 1011, so doing & is 1010 => 10

    // Flip j-th bit with XOR operation 
    n ^= (1 << 2); // n is 1010, (1 << 2) is 0100, doing XOR is 1110 => 14
    cout << n << endl;

    // Value of LSB that is on
    m = ((n) & -(n)); // LSOne(S)
    cout << m << endl; // 1110, 10 -> results as 2

    // Turn on all n bits
    n = (1 << 3)-1; // 1000 - 1 => 111 => 7
    cout << n << endl;

    // Enumerate all proper subsets
    int mask = 18; // 10010, so subsets are 10000, 00010
    for(int subset = mask; subset; subset = (mask & (subset-1))) {
        cout << subset << '\n';
    }

    // Count how many bits are on
    cout << __builtin_popcount(31) << endl; // 11111
    cout << __builtin_popcount((1l << 62)-1l) << endl; // 2^62-1

    // Count how many trailing zeroes
    cout << __builtin_ctz(32) << endl; // 100000
    cout << __builtin_ctz(1l << 62) << endl; // 2^62

    return 0;
}