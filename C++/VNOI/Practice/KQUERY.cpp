// https://oj.vnoi.info/problem/kquery
#include <bits/stdc++.h>
#define val first
#define id second
using namespace std;

const int N = 2e5 + 5;

int n, m;
pair <int, int> a[N];

struct O
{
	int k, u, v, n;
	bool operator <(const O &x) const {return k < x.k;}
} q[N];

struct Lazy
{
	int t[4 * N];

	void build(int l, int r, int i)
	{
		if (l == r) return (void) (t[i] = 1);
		int m = (l + r) >> 1;
		build(l, m, i << 1);
		build(m + 1, r, i << 1 | 1);
		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	void up(int l, int r, int i, int pos)
	{
		if (pos < l || pos > r) return;
		if (l == r) return (void) (t[i] = 0);
		int m = (l + r) >> 1;
		up(l, m, i << 1, pos);
		up(m + 1, r, i << 1 | 1, pos);
		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	int get(int l, int r, int i, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return t[i];
		int m = (l + r) >> 1;
		return get(l, m, i << 1, u, v) + get(m + 1, r, i << 1 | 1, u, v);
	}
} lz;

void init()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; for (int i = 1; i <= n; i++) cin >> a[i].val, a[i].id = i;
	cin >> m; for (int i = 1; i <= m; i++) cin >> q[i].u >> q[i].v >> q[i].k, q[i].n = i;

	lz.build(1, n, 1);
	sort(q + 1, q + 1 + m);
	sort(a + 1, a + 1 + n);
}

void solve()
{
	vector <int> res(m + 1);
	int i = 1;
	for (int j = 1; j <= m; j++)
	{
		while (i <= n && a[i].val <= q[j].k)
			lz.up(1, n, 1, a[i].id), i++;
		res[q[j].n] = lz.get(1, n, 1, q[j].u, q[j].v);
	}	
	for (int i = 1; i <= m; i++) cout << res[i] << '\n';
}

int main()
{
	init();
	solve(); 
	return 0; 
}
