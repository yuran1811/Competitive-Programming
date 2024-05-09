// https://oj.vnoi.info/problem/lubenica
#include <iostream>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 5, oo = 1e6 + 50, LOG = 20;

vector <pair <int, int>> a[N];

int Min[N][LOG + 1], Max[N][LOG + 1];
int par[N][LOG + 1], high[N];
int n, q, u, v;

void dfs(int u)
{
	for (int v : a[u])
		if (v.fi != par[u][0])
		{
			par[v.fi][0] = u;
			high[v.fi] = high[u] + 1;
			Max[v.fi][0] = Min[v.fi][0] = v.se;
			dfs(v.fi);
		}
}

void sparse_table()
{
	dfs(1);
	for (int j = 1; j <= LOG; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1], 
			Max[i][j] = max(Max[i][j - 1], Max[par[i][j - 1]][j - 1]), 
			Min[i][j] = min(Min[i][j - 1], Min[par[i][j - 1]][j - 1]);
	high[0] = -1;
}

void lca(int u, int v)
{
	int MIN = oo, MAX = 0;
	if (high[u] < high[v]) swap(u, v);
	for (int i = LOG; i >= 0; i--)
		if (high[par[u][i]] >= high[v])
			MIN = min(MIN, Min[u][i]),
			MAX = max(MAX, Max[u][i]),
			u = par[u][i];
	if (u == v) return (void) (cout << MIN << " " << MAX << '\n');

	for (int i = LOG; i >= 0; i--)
		if (par[u][i] != par[v][i])
			MIN = min({MIN, Min[u][i], Min[v][i]}),
			MAX = max({MAX, Max[u][i], Max[v][i]}),
			u = par[u][i], 
			v = par[v][i];

	MIN = min({MIN, Min[u][0], Min[v][0]});
	MAX = max({MAX, Max[u][0], Max[v][0]});
	return (void) (cout << MIN << " " << MAX << '\n');
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, w; i < n; i++)
		cin >> u >> v >> w, 
		a[u].push_back({v, w}), 
		a[v].push_back({u, w}); 
	sparse_table();

	cin >> q;
	while (q--) cin >> u >> v, lca(u, v);
	return 0;
}
