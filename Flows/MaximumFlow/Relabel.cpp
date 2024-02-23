/**https://cp-algorithms.com/graph/push-relabel.html
 * With the push operation we try to push as much excess flow from one 
 * vertex  $u$  to a neighboring vertex  $v$ . 
 * We have one rule: we are only allowed to push flow from  $u$  to  $v$  
 * if  $h(u) = h(v) + 1$ . 
 * In layman's terms, the excess flow has to flow downwards, 
 * but not too steeply. Of course we only can push  
 * $\min(x(u), c((u, v)) - f((u, v)))$  flow.
 * 
 * If a vertex has excess, but it is not possible to push the excess 
 * to any adjacent vertex, then we need to increase the height of this 
 * vertex. We call this operation relabel. We will increase it by 
 * as much as it is possible, while still maintaining validity of the 
 * labeling.
 * 
 * To recap, the algorithm in a nutshell is: 
 * We initialize a valid preflow and a valid labeling. 
 * While we can perform push or relabel operations, we perform them. 
 * Afterwards the preflow is actually a flow and we return it.
*/

/**
 * Here we use the queue excess_vertices to store all vertices that 
 * currently have excess. In that way we can pick the next vertex for 
 * a push or a relabel operation in constant time.
 * And to make sure that we don't spend too much time finding 
 * the adjacent vertex to whom we can push, we use a data structure 
 * called current-arc. Basically we will iterate over the edges in a 
 * circular order and always store the last edge that we used. 
 * This way, for a certain labeling value, we will switch the current 
 * edge only  $O(n)$  time. And since the relabeling already takes  $O(n)$  time, 
 * we don't make the complexity worse.
*/



const int inf = 1000000000;

int n;
vector<vector<int>> capacity, flow;
vector<int> height, excess, seen;
queue<int> excess_vertices;

void push(int u, int v)
{
    int d = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;
    excess[u] -= d;
    excess[v] += d;
    if (d && excess[v] == d)
        excess_vertices.push(v);
}

void relabel(int u)
{
    int d = inf;
    for (int i = 0; i < n; i++) {
        if (capacity[u][i] - flow[u][i] > 0)
            d = min(d, height[i]);
    }
    if (d < inf)
        height[u] = d + 1;
}

void discharge(int u)
{
    while (excess[u] > 0) {
        if (seen[u] < n) {
            int v = seen[u];
            if (capacity[u][v] - flow[u][v] > 0 && height[u] > height[v])
                push(u, v);
            else 
                seen[u]++;
        } else {
            relabel(u);
            seen[u] = 0;
        }
    }
}

int max_flow(int s, int t)
{
    height.assign(n, 0);
    height[s] = n;
    flow.assign(n, vector<int>(n, 0));
    excess.assign(n, 0);
    excess[s] = inf;
    for (int i = 0; i < n; i++) {
        if (i != s)
            push(s, i);
    }
    seen.assign(n, 0);

    while (!excess_vertices.empty()) {
        int u = excess_vertices.front();
        excess_vertices.pop();
        if (u != s && u != t)
            discharge(u);
    }

    int max_flow = 0;
    for (int i = 0; i < n; i++)
        max_flow += flow[i][t];
    return max_flow;
}