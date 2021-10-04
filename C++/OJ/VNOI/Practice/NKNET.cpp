// https://oj.vnoi.info/problem/nknet
#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 5e3 + 5, oo = 1e6 + 7;

vector <int> a[N];
int dfs[N], cnt = 0;
int n, m, s, t, res = 0;
int d[N], f[N][N], c[N][N];

pair <int, pair <int, int>> g[M];

void in()
{
	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; i++)
	{
		cin >> u >> v >> w;
		a[u].push_back(v);
		a[v].push_back(u);
		g[i] = {w, {u, v}};
	}
	cin >> s >> t;
}

bool bfs(int s, int t)
{
	memset(d, 0, sizeof d); d[s] = 1;
	queue <int> q; q.push(s);
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : a[u])
			if (!d[v] && f[u][v] < c[u][v])
			{
				d[v] = d[u] + 1;
				if (v == t) return true;
				q.push(v);
			}
	}
	return false;
}

int visit(int u, int t, int minn)
{
	if (u == t) return minn;
	if (dfs[u] != cnt) dfs[u] = cnt; else return 0;
	for (int v : a[u])
		if (f[u][v] < c[u][v])
			if (dfs[v] != cnt && d[v] == d[u] + 1)
				if (int x = visit(v, t, min(minn, c[u][v] - f[u][v])))
				{
					f[u][v] += x;
					f[v][u] -= x;
					return x;
				}
	return 0;
}

void sett()
{
	for (int i = 1; i <= n; i++)
	{
		a[i].clear();
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = 0;
			c[i][j] = oo;
		}
	}
}

void reset1(int x)
{
	sett();
	for (int i = 1; i <= m; i++)
		if (g[i].first > x)
		{
			int u = g[i].second.first;
			int v = g[i].second.second;
			a[u].push_back(v);
			a[v].push_back(u);
		}
}

void reset2(int x)
{
	sett();
	for (int i = 1; i <= m; i++)
	{
		int u = g[i].second.first;
		int v = g[i].second.second;
		a[u].push_back(v);
		a[v].push_back(u);
		if (g[i].first <= x) c[u][v] = c[v][u] = 1;
	}
}

int findd(int res)
{
	int l = 0, r = oo;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		reset1(m);
		if (bfs(s, t)) l = m + 1; 
		else {r = m - 1; res = m;}
	}
	return res;
}

void solve()
{
	int maxflow = 0;
	while (bfs(s, t))
		while (int x = (cnt++, visit(s, t, oo)))
			maxflow += x;
	cout << maxflow << '\n';
	for (int u = 1; u <= n; u++)
		if (u == s || d[u])
			for (int v : a[u])
				if (!d[v]) cout << u << " " << v << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	in(); reset2(findd(res)); solve();
	return 0;
}
