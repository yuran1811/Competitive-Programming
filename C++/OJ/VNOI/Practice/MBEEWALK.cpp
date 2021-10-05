// https://oj.vnoi.info/problem/mbeewalk
#include <bits/stdc++.h>
using namespace std;

pair <int, int> d[6] = {{0, -1}, {0, 1}, {-1, 1}, {-1, 0}, {1, 0}, {1, -1}};
int f[40][40][15], n, t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[15][15][0] = 1;
	cin >> t;
	while (t--)
	{
	    cin >> n;
	    for (int i = 1; i <= n; i++)
            for (int x = 1; x <= 38; x++)
                for (int y = 1; y <= 38; y++)
                {
                    f[x][y][i] = 0;
                    for (int l = 0; l < 6; l++)
                        f[x][y][i] += f[x + d[l].first][y + d[l].second][i - 1];
                }
		cout << f[15][15][n] << '\n';
	}
	return 0;
}
