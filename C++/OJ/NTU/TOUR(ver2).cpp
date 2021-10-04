#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;

int n, m, high[N], par[N];
vector <int> a[N];
int res;

struct DSU
{
	vector <int> f;
	void Init(int n) {f.resize(n + 5, -1);}
	int Root(int u) {return f[u] < 0 ? u : f[u] = Root(f[u]);}
	void LCA(int u, int v)
	{
		while (u != v)
		{
			u = Root(u), v = Root(v);
			if (u == v) break;
			if (high[u] <= high[v])
				v = f[v] = par[v], res--; else
			if (high[u] >= high[v])
				u = f[u] = par[u], res--;
		}
	}
} dsu;

void DFS(int u, int p)
{
	for (int v : a[u])
		if (v ^ p)
		{
			high[v] = high[u] + 1;
			par[v] = u;
			DFS(v, u);
		}
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; dsu.Init(n);
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
	DFS(1, -1);
}

int Solve()
{
	Load_Data();
	res = n - 1;
	cin >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, dsu.LCA(u, v);
	cout << res;
	return 0;
}

int main() {Solve();}
