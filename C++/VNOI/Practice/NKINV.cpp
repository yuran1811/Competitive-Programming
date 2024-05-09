#include <bits/stdc++.h>
using namespace std;

const int N = 6e4 + 5;

int n, m;
long long res = 0;
vector <int> a, b;

struct ST
{
	long long t[4 * N];

	void up(int l, int r, int i, int pos)
	{
		if (pos < l || pos > r) return;
		if (l == r) return (void) (++t[i]);
		int m = (l + r) >> 1;
		if (pos <= m) up(l, m, i << 1, pos); else
		up(m + 1, r, i << 1 | 1, pos);
		t[i] = t[i << 1] + t[i << 1 | 1];
	} 

	long long get(int l, int r, int i, int u, int v)
	{
		if (u > r || v < l) return 0;
		if (u <= l && r <= v) return t[i];
		int m = (l + r) >> 1;
		return get(l, m, i << 1, u, v) + get(m + 1, r, i << 1 | 1, u, v);
	}
} st;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, x; i <= n; i++)
		cin >> x, a.push_back(x);
	b = a;
	sort(b.begin(), b.end());
	for (int i = 0; i < int (a.size()); i++)
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

	for (int i = 0; i < n; i++)
	{
		res += st.get(1, n, 1, a[i] + 1, n);
		st.up(1, n, 1, a[i]);
	}

	cout << res;
	return 0;
}
