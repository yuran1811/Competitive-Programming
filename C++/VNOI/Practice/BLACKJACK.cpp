#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 4;

int n, m, res, a[N];

int bs(int l, int r, int val)
{
	while (l < r) 
	{
		int mid = l + (r - l + 1) / 2;
		if (a[mid] > val) r = mid - 1;
		else              l = mid;
	}
	return l;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n - 2; i++)
		for (int j = n; j >= i + 2; j--)
			if (a[i] + a[j] < m)
			{
				int pos = bs(i + 1, j - 1, m - a[i] - a[j]);
				if (a[pos] <= m - a[i] - a[j])
					res = max(res, a[i] + a[j] + a[pos]);
			}
	cout << res;
	return 0;
}
