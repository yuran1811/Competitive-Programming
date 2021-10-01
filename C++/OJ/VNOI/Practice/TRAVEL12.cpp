#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 5;

int n, m, u, v, tmp, start;
vector <int> a[N], f;
vector <bool> Vst;

void DFS(int u, int cnt)
{
	if (cnt == 4)
	{
		for (int v : a[u])
			if (v == start)
			{
				for (int x : f)
					cout << x << " ";
				exit(0);
			}
		return;
	}

	Vst[u] = 1;
	for (int v : a[u])
		if (Vst[v])
		{
			Vst[v] = 1;
			f.push_back(v);
			DFS(v, cnt + 1);
			Vst[v] = 0;
			f.pop_back();
		}
}

void Load_Graph()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	Vst.resize(n + 5);
	for (int i = 1; i <= m; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);	
}

int main()
{
	Load_Graph();
	for (int i = 1; i <= n; i++)
	{
		start = i;
		f.push_back(i);
		DFS(i, 1);
		f.clear();
	}

	cout << -1;
	return 0;
}
