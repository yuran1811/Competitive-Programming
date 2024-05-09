// https://oj.vnoi.info/problem/mcquery
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#define fi first
#define se second
using namespace std;

typedef long long ll;

const ll oo = 1e18 + 5LL;

struct Edge
{
	int u, v, rev;
	ll capacity, f;
	Edge() {}
	Edge(int _u, int _v, ll c, int _rev = 0)
	{
		this -> u = _u; this -> v = _v;
		this -> rev = _rev; this -> capacity = c;
	}
};

struct Graph
{
	int n;
	vector <int> d, iter;
	vector <vector <Edge>> a;
	Graph(int n = 0) : n(n), a(n) {}

	void addEdge(int u, int v, ll capacity)
	{
		n = max(n, max(u, v) + 1); a.resize(n);
		a[u].push_back(Edge(u, v, capacity, a[v].size()));
		a[v].push_back(Edge(v, u, capacity, a[u].size() - 1));
	}

	ll DFS(int u, int t, ll Min)
	{
		if (u == t) return Min;
		for (int &i = iter[u]; i < int (a[u].size()); i++) // also can : for (Edge &e : a[u]) instead of using vector <int> iter, but can be slower
		{
			Edge &e = a[u][i]; // this line can be deleted if don't use the vector <int> iter
			if (e.f > 0 && d[u] < d[e.v])
				if (ll f = DFS(e.v, t, min(Min, e.f)))
					return e.f -= f, a[e.v][e.rev].f += f, f;
		}
		return 0;
	}

	int BFS(int s, int t)
	{
		d.assign(n, -1); d[s] = 0;
		queue <int> q; q.push(s);
		while (q.size())
		{
			int u = q.front(); q.pop();
			if (u == t) break;
			for (Edge &e : a[u])
				if (e.f > 0 && d[e.v] < 0)
					q.push(e.v), d[e.v] = d[u] + 1;
		}
		return d[t];
	}

	ll maxFlow(int s, int t)
	{
		for (int u = 0; u < n; u++)
			for (Edge &e : a[u]) e.f = e.capacity;

		ll flow = 0;
		while (BFS(s, t) >= 0)
		{
			iter.assign(n, 0); // this line can be deleted if don't use
			for (ll x; (x = DFS(s, t, oo)); flow += x);
		}
		return flow;
	}

	vector <Edge> tree;
	void GomoryHu()
	{
		tree.clear();
		vector <int> par(n);
		for (int u = 1; u < n; u++)
		{
			tree.push_back(Edge(u, par[u], maxFlow(u, par[u])));
			for (int v = u + 1; v < n; v++)
				if (d[v] >= 0 && par[v] == par[u]) par[v] = u;
		}
	}
};

struct DSU
{
	vector <int> f;
	DSU(int n) : f(n, -1) {};
	int Root(int u) {return f[u] < 0 ? u : f[u] = Root(f[u]);}
	bool Same(int u, int v) {return Root(u) == Root(v);}
	int getSize(int u) {return -f[Root(u)];}
	bool Mer(int u, int v)
	{
		if ((u = Root(u)) == (v = Root(v))) return 0;
		if (f[u] > f[v]) swap(u, v);
		return f[u] += f[v], f[v] = u, 1;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int id = 1, n, m, q; id <= t; id++)
	{
		if (id ^ 1) cout << '\n';
		cin >> n >> m;
		Graph MCQ(n);
		for (int i = 1, u, v, c; i <= m; i++)
			cin >> u >> v >> c, MCQ.addEdge(u - 1, v - 1, c);
		MCQ.GomoryHu();

		map <ll, vector <Edge>> edges;
		for (auto e : MCQ.tree)
			edges[-e.capacity].push_back(e);

		int sum = n * (n - 1) / 2;
		DSU dsu(n);
		vector <ll> f({oo});
		vector <int> c({sum});

		for (auto &p : edges)
		{
			f.push_back(-p.fi);
			c.push_back(sum);
			for (auto e : p.se)
				if (!dsu.Same(e.u, e.v))
					sum -= dsu.getSize(e.u) * dsu.getSize(e.v), dsu.Mer(e.u, e.v);
		}
		f.push_back(-1); c.push_back(0);
		reverse(f.begin(), f.end());
		reverse(c.begin(), c.end());

		cin >> q;
		for (int i = 0, a; i < q; i++)
		{
			cin >> a;
			int k = distance(f.begin(), lower_bound(f.begin(), f.end(), a));
			// distance(a, b) : Calculates the number of elements between a and b. (a, b : iterator)
			while (f[k] > a) --k;
			cout << c[k] << '\n';
		}
	}
	return 0;
}
