// https://oj.vnoi.info/problem/assign1
#include <bits/stdc++.h>
using namespace std;
const int N = 250, oo = 1e9 + 7;

int n, c[N][N];
vector <int> a[N], f;
int mx[N], my[N], d[N];

bool bfs()
{
	queue <int> q; 
	for (int u = 1; u <= n; u++)
		if (!mx[u]) d[u] = 0, q.push(u);
		else 		d[u] = oo;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : a[u])
			if (!my[v]) return true; else 
			if (d[my[v]] == oo) d[my[v]] = d[u] + 1, q.push(my[v]);
	}
	return false;
}

bool dfs(int u)
{
	if (d[u] == oo) return false;
	for (int v : a[u])
		if (!my[v] || (d[my[v]] == d[u] + 1 && dfs(my[v])))
		{
			mx[u] = v, my[v] = u;
			return true;
		}
	return false;
}

bool check(int t)
{
	for (int i = 1; i <= n; i++) a[i].clear(), mx[i] = my[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (c[i][j] <= t) a[i].push_back(j);

	int tmp = 0;
	while (bfs())
		for (int u = 1; u <= n; u++)
			if (!mx[u])
				tmp += dfs(u);
	for (int u = 1; u <= n; u++)
		if (!mx[u]) return false;
	return true;
}

void solve()
{
	int l = 0, r = f.size(), res = 0;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (!check(f[m])) l = m + 1;
		else r = m - 1, res = f[m];
	}
	cout << res;
}

void in()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j], f.push_back(c[i][j]);
	sort(f.begin(), f.end());
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	in(); solve();
	return 0;
}
