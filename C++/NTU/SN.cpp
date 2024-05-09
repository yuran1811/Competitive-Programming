// http://ntucoder.net/Problem/Details/5612
#include <bits/stdc++.h>
using namespace std;
const int N = 150, oo = 1e6 + 7;

int n, m, t[N][N];
vector <int> a[N];
int l = 0, r = oo, res = -1;
int mx[N], my[N], d[N];

bool bfs()
{
	queue <int> q; 
	for (int u = 1; u <= n; u++)
		if (!mx[u]) q.push(u), d[u] = 0;
		else d[u] = oo;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : a[u]) 
			if (!my[v]) return true; else
			if (d[my[v]] == oo) d[my[v]] = d[u] + 1, q.push(my[v]);
	}
	return false;
}

bool match(int u)
{
	if (d[u] == oo) return false;
	for (int v : a[u])
		if (!my[v] || (d[my[v]] == d[u] + 1 && match(my[v])))
		{
			mx[u] = v;
			my[v] = u;
			return true;
		}
	return false;
}

void reset()
{
	memset(d, 0, sizeof d);
	memset(mx, 0, sizeof mx);
	memset(my, 0, sizeof my);
	for (int i = 1; i <= n; i++) a[i].clear();
}

bool check(int T)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (t[i][j] != -1 && t[i][j] <= T)
				a[i].push_back(j);

	while (bfs())
	{
		for (int u = 1; u <= n; u++)
			if (!mx[u]) match(u);
	}
	for (int v = 1; v <= m; v++)
		if (!my[v]) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			cin >> t[i][j], res = max(res, t[i][j]);

	while (l <= r)
	{
		int m = (l + r) >> 1;
		reset();
		if (check(m)) r = m - 1, res = m;
		else l = m + 1;
	}
	cout << res;
	return 0;
}
