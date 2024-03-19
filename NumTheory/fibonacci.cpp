// Fibonacci Numbers
vi f(90);

//==Fibonacci Pre-process==
void fibonacci(ll n=90) {
    f[0] = 0, f[1] = 1;
    FOR(i,2,n) {
        f[i] = f[i-1]+f[i-2];
    }
}

//==N-th Fibonacci==
ll fib(ll n) {
    ll a = 0, b = 1;
    FOR(i,0,n) {
        ll tmp = a + b;
        a = b; b = tmp;
    } return a;
}

//==Fibonacci Numbers==
// returns {F_n,F_n+1}
pi fibs(ll n) {
    if(n == 0) return {0, 1};
    auto p = fibs(n >> 1);
    ll c = p.fst * (2*p.snd-p.fst);
    ll d = p.fst*p.fst + p.snd*p.snd;
    if(n & 1) return {d, c+d};
    else return {c, d};
}