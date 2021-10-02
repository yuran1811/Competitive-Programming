// https://oj.vnoi.info/problem/qtree3
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5, oo = 1e9 + 7;

int n, q, PrevPos, par[N], NumChild[N];
int pos[N], head[N], ID_Node[N];
vector <int> a[N];

bool mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}
bool mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}

struct SegTree
{
	vector <int> t;
	int n;

	SegTree() {}
	SegTree(int n) {this -> n = n; t.resize(4 * n, oo);}

	void Up(int l, int r, int i, int p)
	{
		if (p < l || r < p) return;
		if (l == r) return void (t[i] = (t[i] == oo ? p : oo));
		int m = (l + r) >> 1;
		Up(l, m, i << 1, p);
		Up(m + 1, r, i << 1 | 1, p);
		t[i] = min(t[i << 1], t[i << 1 | 1]);
	}

	int Get(int l, int r, int i, int u, int v)
	{
		if (v < l || r < u) return oo;
		if (u <= l && r <= v) return t[i];
		int m = (l + r) >> 1;
		return min(Get(l, m, i << 1, u, v), Get(m + 1, r, i << 1 | 1, u, v));
	}
} T;

void DFS(int u, int p)
{
	par[u] = p;
	NumChild[u] = 1;
	for (int v : a[u])
	{
		if (v == p) continue;
		DFS(v, u);
		NumChild[u] += NumChild[v];
	}
}

void HLD(int u, int top)
{
	pos[u] = ++PrevPos; head[u] = top;
	ID_Node[PrevPos] = u;

	int heavy_node = -1, heavy_NumChild = -1;
	for (int v : a[u])
	{
		if (v == par[u]) continue;
		if (!mxm(heavy_NumChild, NumChild[v])) continue;
		heavy_node = v;
	}

	if (heavy_NumChild == -1) return;
	HLD(heavy_node, top);
	for (int v : a[u])
	{
		if (v == par[u] || v == heavy_node) continue;
		HLD(v, v);
	}
}

int Query(int u)
{
	int res = oo;
	for (; head[u] != 1; u = par[head[u]])
		mnz(res, T.Get(1, n, 1, pos[head[u]], pos[u]));
	mnz(res, T.Get(1, n, 1, 1, pos[u]));
	return res < oo ? ID_Node[res] : -1;
}

void Load_Tree()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
}

void Solve()
{
	Load_Tree();
	DFS(1, 1);
	HLD(1, 1);
	T = SegTree(n + 5);

	while (q--)
	{
		int c, v;
		cin >> c >> v;
		if (!c) T.Up(1, n, 1, pos[v]);
		else cout << Query(v) << '\n';
	}
}

int main() {Solve();}
