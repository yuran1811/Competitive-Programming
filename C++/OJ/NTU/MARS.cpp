// http://ntucoder.net/Problem/Details/100
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m, res = 0;
int a[N][N], f[N][N];
char c;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], f[i][j] = (a[i][j] == 0);
  
  for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!a[i][j])
                f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
            res = max(res, f[i][j]);
        }
  cout << res;
	return 0;
}
