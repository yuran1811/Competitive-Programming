// http://ntucoder.net/Problem/Details/5629
#include <functional>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

const int N = 1e4 + 5;
const ll oo = 1e18 + 9;

ll x[N], y[N], fx[N], fy[N], c[N][N], res = 0;
int n, m, finish, trace[N], mx[N], my[N];
vector <int> a[N];

bool mnz(ll &a, ll b) {return a > b ? a = b, 1 : 0;}
bool mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}

int BFS(int s)
{
	memset(x, 0, sizeof x); memset(y, 0, sizeof y);
	memset(trace, 0, sizeof trace);
	queue <int> q; q.push(s);

	while (q.size())
	{
		int u = q.front(); q.pop();
		x[u] = 1;

		for (int v : a[u])
			if (!y[v] && c[u][v] == fx[u] + fy[v])
			{
				y[v] = 1;
				trace[v] = u;
				if (!my[v]) return finish = v, 1;
				q.push(my[v]);
			}
	}
	return 0;
}

void Turn()
{
	ll delta = oo;
	for (int u = 1; u <= n; u++)
		if (x[u])
			for (int v : a[u])
				if (!y[v])
					mnz(delta, c[u][v] - fx[u] - fy[v]);
	for (int i = 1; i <= n; i++)
	{
		if (x[i]) fx[i] += delta;
		if (y[i]) fy[i] -= delta;
	}
}

void Enlarge(int s)
{
	int u, v = finish, t;
	while (!mx[s])
	{
		u = trace[v];
		t = mx[u];
		mx[u] = v;
		my[v] = u;
		v = t;
	}
}

int Num[N], Low[N], cnt = 0, noWay = 0;
bool Check()
{
	vector <int> s;
	function <void (int u)> Tarjan = [&](int u)
	{
		Num[u] = Low[u] = ++cnt; s.push_back(u);
		for (int v : a[u])
			if (!Num[v]) mnz(Low[u], Low[v]);
			else mnz(Low[u], Num[v]);
		if (Num[u] == Low[u])
		{
			int v, d = 0;
			do
			{
				v = s.back(); s.pop_back();
				Num[v] = Low[v] = 1e9;
				d++;
			} while (u ^ v);
			noWay |= d == 1;
		}
	};
	for (int u = 1; u <= n; u++)
	{
		if (noWay) return false;
		if (!Num[u]) Tarjan(u);
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			c[i][j] = oo;
		
	for (int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w, a[u].push_back(v),
		mnz(c[u][v], 1LL * w);

	if (!Check()) return cout << -1, 0;

	for (int u = 1; u <= n; u++)
	{
		while (!BFS(u)) Turn();
		Enlarge(u);
	}

	for (int u = 1; u <= n; u++) 
		res += fx[u] + fy[u];
	cout << (res >= (ll) 2e18 + 1e17 + 4e16 ? -1 : res);
	return 0;
}
