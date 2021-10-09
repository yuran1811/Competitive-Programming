// http://ntucoder.net/Problem/Details/4437
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, oo = 2e9 + 7;

int n, a[N];
long long res = 0;

void sol(int l , int r)
{
	int minn = oo, _l = 0, _r = 0;
	for (int i = l; i <= r; i++)
		minn = min(minn, a[i]);
	for (int i = l; i <= r; i++)
	{
		if (a[i] ^ minn && !_l) _l = i;
		if (a[i] == minn &&  _l) _r = i - 1;
		if (_l && _r)	
		{
			sol(_l, _r);
			_l = _r = 0;
		}
		if (i == r && _l) sol(_l, i);
	}
	res++;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
    sol(1, n); cout << res;
    return 0;
}
