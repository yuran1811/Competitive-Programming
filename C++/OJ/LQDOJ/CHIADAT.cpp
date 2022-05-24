// https://lqdoj.edu.vn/problem/chiadat
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 505;

int n, a[N][N], f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++)
    		cin >> a[i][j];

	for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++)
    		f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];

    int min_difference = 1e9 + 7;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int first = f[i][j], second = f[i][n] - first, third = f[n][j] - first, forth = f[n][n] - first - second - third;
            int	minn = min(second, min(third, min(forth, first)));
            int maxx = max(second, max(third, max(forth, first)));
            min_difference = min(maxx - minn, min_difference);
        }
	cout << min_difference;
    return 0;
}