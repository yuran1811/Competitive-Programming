// http://ntucoder.net/Problem/Details/1177
#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a, c = b; i <= c; i++)
using namespace std;

int n, m, z, e;
long long b[100002];

int BS(int l, int r, int t)
{
	int mid = (l + r) >> 1, x = b[mid];
	if (t == x) return cout << mid << " ", 0; 
	if (abs(l - r) == 1)
	{
    if (t >= b[l] + 1 && t < b[r]) return cout << l + 1 << " ", 0;
    if (t >= b[l] + 1 && t > b[r]) return cout << r + 1 << " ", 0;
    if (t < b[l] + 1) return cout << l << " ",0;
	}
	if (t < x) BS(l, mid - 1, t); else
	if (t > x) BS(mid + 1, r, t);
	return 0;
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n; f(i, 1, n) cin >> e, b[i] = b[i - 1] + e;
  cin >> m; while (m--) cin >> z, BS(1, n, z);
  return 0;
}
