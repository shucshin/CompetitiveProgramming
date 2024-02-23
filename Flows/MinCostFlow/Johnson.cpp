template <int MN, int MM>
struct MCF  // MN = nodes, MM = edges [assume edges one-directional]
{
  public:
	int N, M, S, T;
	int flow[MM * 2], cap[MM * 2], hd[MN], nx[MM * 2], to[MM * 2], cost[MM * 2];
	int pi[MN], p[MN], d[MN];
	int vis[MN];
	void init(int n, int s, int t) {
		N = n, S = s, T = t;
		memset(hd, -1, sizeof hd);
	}
	void adde1(int a, int b, int f, int c) {
		nx[M] = hd[a], hd[a] = M;
		to[M] = b, cost[M] = c, cap[M] = f;
		M++;
	}
	void adde(int a, int b, int f, int c) {
		adde1(a, b, f, c);
		adde1(b, a, 0, -c);
	}
	void setpi() {
		std::queue<int> q;
		memset(pi, 0x3e, sizeof pi);
		memset(vis, 0, sizeof vis);
		q.push(S);
		pi[S] = 0;
		for (int n; !q.empty();) {
			n = q.front();
			q.pop();
			for (int id = hd[n], x; ~id; id = nx[id]) {
				if (cap[id] - flow[id] <= 0) continue;
				x = to[id];
				if (ckmin(pi[x], pi[n] + cost[id]))
					assert(++vis[x] <= N), q.push(x);
			}
		}
	}
	struct state {
	  public:
		int n, d;
		bool operator>(state o) const { return d > o.d; }
	};
	void dijk() {
		std::priority_queue<state, std::vector<state>, std::greater<state>> q;
		memset(p, -1, N * sizeof p[0]);
		memset(vis, 0, N * sizeof vis[0]);
		memset(d, 0x3e, N * sizeof d[0]);

		d[S] = 0;
		q.push({S, 0});
		for (int n; !q.empty();) {
			n = q.top().n;
			q.pop();
			if (vis[n]) continue;
			vis[n] = 1;
			for (int id = hd[n], x, w; ~id; id = nx[id]) {
				if (cap[id] - flow[id] <= 0) continue;
				x = to[id];
				w = cost[id] + pi[n] - pi[x];
				if (ckmin(d[x], w + d[n])) p[x] = id, q.push({x, d[x]});
			}
		}
	}
	int mincost(int F) {
		setpi();
		int C = 0;
		while (F > 0) {
			dijk();
			if (d[T] == INF) return INF;
			int c = d[T] + pi[T] - pi[S], f = F;
			for (int x = T; x != S; x = to[p[x] ^ 1])
				ckmin(f, cap[p[x]] - flow[p[x]]);
			C += c * f;
			for (int x = T; x != S; x = to[p[x] ^ 1]) {
				flow[p[x]] += f;
				flow[p[x] ^ 1] -= f;
			}
			F -= f;
			for (int i = 0; i < N; ++i) pi[i] += d[i];
		}
		return C;
	}
};