// https://oj.vnoi.info/problem/stnode
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 50;

int n, m, s, t;
vector <bool> kt(N, true);
vector <int> a[N], trace(N, 0), pos(N, -1), path;

void findd() 
{
	queue <int> q; q.push(s);
	trace[s] = -1;

	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : a[u])
			if (!trace[v])
			{
				trace[v] = u;
				q.push(v);
			}
	}

	int v = t;
	while (v != s)
	{
		path.push_back(v);
		v = trace[v];
	}
	path.push_back(v);
	
	reverse(path.begin(), path.end());
	int tmp = 0; for (int x : path) pos[x] = tmp++;
}

int bfs(int s)
{
	queue <int> q; q.push(s); kt[s] = false;
	int x = -1;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : a[u])
			if (kt[v] && pos[v] < 0)
			{
				kt[v] = false;
				q.push(v);
			} else x = max(x, pos[v]);
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1, u, v; i <= m; i++)
	{
		cin >> u >> v;
		a[u].push_back(v);
	}

	findd();
	int x = -1, res = 0;
	for (int v : path)
	{
		if (v != s && v != t && x <= pos[v]) res++;
		x = max(x, bfs(v));
	}
	cout << res;
	return 0;
}
