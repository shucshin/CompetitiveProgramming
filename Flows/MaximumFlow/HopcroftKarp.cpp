#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

/**
 * There are n boys and m girls in a school. Next week a school dance will be organized. 
 * A dance pair consists of a boy and a girl, and there are k potential pairs.
 * Your task is to find out the maximum number of dance pairs and show how this number can be achieved.
*/


int n, m, k;
// dist[node] = the position of node in the alternating path
vector<int> match, dist;
vector<vector<int>> g;

bool bfs() {
	queue<int> q;
	// The alternating path starts with unmatched nodes
	for (int node = 1; node <= n; node++) {
		if (!match[node]) {
			q.push(node);
			dist[node] = 0;
		} else {
			dist[node] = INF;
		}
	}

	dist[0] = INF;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (dist[node] >= dist[0]) { continue; }
		for (int son : g[node]) {
			// If the match of son is matched
			if (dist[match[son]] == INF) {
				dist[match[son]] = dist[node] + 1;
				q.push(match[son]);
			}
		}
	}
	// Returns true if an alternating path has been found
	return dist[0] != INF;
}

// Returns true if an augmenting path has been found starting from vertex node
bool dfs(int node) {
	if (node == 0) { return true; }
	for (int son : g[node]) {
		if (dist[match[son]] == dist[node] + 1 && dfs(match[son])) {
			match[node] = son;
			match[son] = node;
			return true;
		}
	}
	dist[node] = INF;
	return false;
}

int hopcroft_karp() {
	int cnt = 0;
	// While there is an alternating path
	while (bfs()) {
		for (int node = 1; node <= n; node++) {
			// If node is unmatched but we can match it using an augmenting path
			if (!match[node] && dfs(node)) { cnt++; }
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m >> k;

	dist.resize(n + m + 1);
	match.resize(n + m + 1);
	g.resize(n + m + 1);

	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;

		y += n;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	cout << hopcroft_karp() << '\n';
	for (int node = 1; node <= n; node++) {
		if (match[node]) { cout << node << ' ' << match[node] - n << '\n'; }
	}
}