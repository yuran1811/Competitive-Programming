// http://ntucoder.net/Problem/Details/66
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;

int n, m, res = 0;

struct E 
{
	int s, f;
	bool operator <(const E &x) {return s < x.s;}
} a[N];

int bs(int l, int r, int val)
{
	int pos = 0;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (val <= a[m].s) r = m - 1, pos = m;
		else l = m + 1;
	}
	return pos;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].s >> a[i].f;
	sort(a + 1, a + 1 + n);
	a[n + 1].s = N;
	for (int i = 1; i <= n; i++) res += bs(i, n + 1, a[i].f) - i - 1;
	cout << res;
	return 0;
}
