// https://oj.vnoi.info/problem/hbtlca
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1e5 + 5, LOG = 20;

vector <int> a[N];

int par[N][LOG + 1];
int t, n, q, root;
int high[N];

void DFS(int u)
{
	for (int v : a[u])
		if (v != par[u][0])
			high[v] = high[u] + 1,
			par[v][0] = u, DFS(v);
}

void Sparse_Table()
{
	DFS(1); high[0] = -1;
	for (int j = 1; j <= LOG; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}

int LCA(int u, int v)
{
	if (high[u] < high[v]) swap(u, v);
	for (int i = LOG; i >= 0; i--)
		if (high[par[u][i]] >= high[v])
			u = par[u][i];
	if (u == v) return u;

	for (int i = LOG; i >= 0; i--)
		if (par[u][i] != par[v][i])
			u = par[u][i],
			v = par[v][i];
	return par[u][0];
}

void Reset(int n)
{
	for (int i = 1; i <= n; i++) a[i].clear();
	memset(high, 0, sizeof high);
	memset(par, 0, sizeof par);
	root = 1;
}

bool Load_Data()
{
	cin >> n; if (!n) return false;
	Reset(n);
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
	return true;
}

int Solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (Load_Data())
	{
		Sparse_Table();
		cin >> q;
		for (int i = 1, u, v, res; i <= q; i++)
		{
			char c; cin >> c >> u;
			if (c == '!') root = u; else
			{
				cin >> v;
				int x = LCA(root, u), y = LCA(root, v), z = LCA(u, v);
				res = high[x] >= high[y] ? x : y;
				res = high[z] >= high[res] ? z : res;
				cout << res << '\n';
			}
		}
	}
	return 0;
}

int main() {Solve();}
