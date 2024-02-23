/**
 * 
 * 
 * Step 1: Let S be the set of source nodes (nodes with no incoming edges, if S is empty terminate algorithm)
 * Output a line containing a single integer: the largest possible size of S 
 * at the beginning of any iteration of Step 1 in the execution of Kahn’s Algorithm.
*/


TopoSort<500> T;
int n, m;
bool link[500][500];
vi out[500];
Dinic<1005> D;

int main() {
	setIO();
	re(n, m);
	F0R(i, m) {
		int x, y;
		re(x, y);
		T.ae(x, y);
		link[x][y] = 1;
	}
	F0R(k, n) F0R(a, n) F0R(b, n) link[a][b] |= link[a][k] & link[k][b];
	T.sort(n);
	vi bad;
	F0R(i, n) if (T.in[i]) bad.pb(i);  // cannot be part of S
	trav(a, bad) F0R(i, n) link[a][i] = link[i][a] = 0;
	F0R(i, n) {
		D.ae(2 * n, i, 1);
		D.ae(i + n, 2 * n + 1, 1);
	}
	F0R(i, n) F0R(j, n) if (link[i][j]) D.ae(i, n + j, 1);
	int chain = n - sz(bad) - D.maxFlow(2 * n + 2, 2 * n, 2 * n + 1);
	ps(chain);
}