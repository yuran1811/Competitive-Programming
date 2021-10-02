// https://oj.vnoi.info/problem/jobset
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const ll oo = 1e18 + 5LL;
const int N = 1e3 + 5;

int d[N], dfs[N], cnt = 0;
ll f[N][N], c[N][N];
vector <int> a[N];
int n, m, Tax[N];
ll Sum = 0;

bool BFS(int s, int t)
{
	memset(d, 0, sizeof d); d[s] = 1;
	queue <int> q; q.push(s);
	while (q.size())
	{
		int u = q.front(); q.pop();
		if (u == t) return true;
		for (int v : a[u])
			if (!d[v] && f[u][v] < c[u][v])
				d[v] = d[u] + 1, q.push(v);
	}
	return false;
}

ll DFS(int u, int t, ll Min)
{
	if (u == t) return Min;
	if (dfs[u] != cnt) dfs[u] = cnt; else return 0;
	for (int v : a[u])
		if (f[u][v] < c[u][v])
			if (dfs[v] != cnt && d[v] == d[u] + 1)
				if (ll x = DFS(v, t, min(Min, c[u][v] - f[u][v])))
					return f[u][v] += x, f[v][u] -= x, x;
	return 0;
}

ll MaxFlow(int s, int t)
{
	ll flow = 0;
	while (BFS(s, t))
		while (ll x = (++cnt, DFS(s, t, oo)))
			flow += x;
	return flow;
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int u = 1; u <= n; u++)
	{
		cin >> Tax[u];
		if (Tax[u] < 0)
			c[u][n + 1] = -Tax[u],
			a[u].push_back(n + 1), a[n + 1].push_back(u);
		else c[0][u] = Tax[u], Sum += Tax[u],
			a[u].push_back(0), a[0].push_back(u);
	}

	cin >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u),
		c[u][v] = oo;
}

int Scorpio()
{
	Load_Data();
	cout << Sum - MaxFlow(0, n + 1);
	return 0;
}

int main() {Scorpio();}
