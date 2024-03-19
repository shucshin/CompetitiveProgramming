// Euler's Totient Function (Phi-Function)

//==Phi Function (Euler's Totient Function)==
/* Counts number of ints [1,n] that are coprime to n
   Coprime = 2 nums that gcd 1. */
ll phi(ll n) {
    ll ans = n;
    for(ll i = 2; i*i <= n; i++) {
        if (n%i==0) {
            while (n%i==0) n /= i;
            ans -= ans/i;
        }
    }
    if(n > 1) ans-=ans/n;
    return ans;
}

//==Phi Function from 1 to n. O(n log log n)==
vi phi_n(ll n) {
    vi phi(n+1);
    FOR(i,0,n+1) phi[i] = i;
    FOR(i,2,n+1) {
        if(phi[i]==i) {
            for(int j=i; j <= n; j+=i) phi[j]-=phi[j]/i;
        }
    }
    return phi;
}

//==Phi Function from 1 to n using divisor sum property. Worse case O(n log n)==
vi phi_1_to_n(ll n) {
    vi phi(n+1); phi[0]=0; phi[1]=1;
    FOR(i,2,n+1) phi[i] = i-1;
    FOR(i,2,n+1) {
        for(ll j = 2*i; j <= n; j+=i) phi[j] -= phi[i];
    }
    return phi;
}