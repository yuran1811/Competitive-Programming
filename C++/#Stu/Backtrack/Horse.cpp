#include <iostream>
using namespace std;

int x, y, d, a[21][21];
pair <int, int> dir[8] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

void btr(int h, int c)
{
	for (int i = 0; i < 8; i++)
	{
	    int u = h + dir[i].first;
	    int v = c + dir[i].second;
		if (a[u][v] == 0 && u <= d && v <= d && u > 0 && v > 0)
		{
			a[u][v] = a[h][c] + 1;
			if (a[u][v] == d * d)
			{
				for (int k = 1; k <= d; k++, cout << '\n')
                    for (int l = 1; l <= d; l++)
                        cout << a[k][l] << "  ";
                exit(0);
			}
			else btr(u, v);
			a[u][v] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> d >> x >> y; a[x][y] = 1; btr(x, y);
	return 0;
}
