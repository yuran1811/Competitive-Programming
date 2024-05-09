// https://oj.vnoi.info/problem/stable
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e4 + 5;

int f[N], d[N], par[N];
int n, m, s, res = 0;
vector <int> a[N];

void BFS(int s)
{
	queue <int> q; q.push(s);
	memset(d, 0, sizeof d);
	d[s] = 1; par[s] = s;

	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int v : a[u])
		{
			if (par[v] == u) continue;
			if (!d[v])
				par[v] = u, d[v] = d[u] + 1,
				f[v] = f[u], q.push(v);
			else f[v] |= (d[v] == d[u] + 1);
		}
	}
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, a[u].push_back(v);
}

int Scorpio()
{
	Load_Data();
	BFS(s);
	for (int i = 1; i <= n; i++)
		res += f[i];
	cout << res;
	return 0;
}

int main() {Scorpio();}
