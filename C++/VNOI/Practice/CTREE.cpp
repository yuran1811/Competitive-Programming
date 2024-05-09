// https://oj.vnoi.info/problem/ctree
#include <iostream>
#include <vector>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const int MAX = 10, N = 1e4 + 5, oo = 1e9 + 7;

vector <int> a[N];

ll f[N][MAX + 5], c[N];
int n;

ll mnz(ll &a, ll b) {return a > b ? a = b, 1 : 0;}

void DFS(int u, int p)
{
	for (int c = 1; c <= MAX; c++) f[u][c] = c;

	for (int v : a[u])
	{
		if (v == p) continue;
		DFS(v, u);

		for (int c = 1; c <= MAX; c++)
		{
			ll Min = oo;
			for (int _c = 1; _c <= MAX; _c++)
				if (c != _c)
					mnz(Min, f[v][_c]);
			f[u][c] += Min;
		}
	}
}

void Recall(int u, int p, ll c_u)
{
	c[u] = c_u;

	for (int v : a[u])
	{
		if (v == p) continue;

		pii Min = {oo, -1};
		for (int c = 1; c <= MAX; c++)
		{
			if (c == c_u) continue;
			Min = min(Min, make_pair(f[v][c], 1LL * c));
		}
		Recall(v, u, Min.se);
	}
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, 
		a[u].push_back(v),
		a[v].push_back(u);
}

int Solve()
{
	Load_Data();

	DFS(1, -1);
	pii res = {oo, -1};
	for (int i = 1; i <= MAX; i++)
		res = min(res, make_pair(f[1][i], 1LL * i));
	Recall(1, -1, res.se);
	
	cout << res.fi << '\n';
	for (int i = 1; i <= n; i++)
		cout << c[i] << "\n";
	return 0;
}

int main() {Solve();}
