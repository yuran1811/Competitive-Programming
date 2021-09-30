#include <iostream>
using namespace std;

int n, c, b, row[101], kt1[101], kt2[101], a[21][21];

void btr(int i)
{
	for (int j = 1; j <= 8; j++)
		if (a[j][i] == 0 && row[j] == 0 && kt1[i - j + 8] == 0 && kt2[i + j] == 0)
		{
			a[j][i] = row[j] = kt1[i - j + 8] = kt2[i + j] = 1;
			if (i >= 8)
			{
				if (a[c][b] == 1)
				{
					for (int l = 1; l <= 8; l++, cout << endl)
						for (int k = 1; k <= 8; k++)
							cout << (a[l][k] == 1 ? "w" : ".");
					exit(0);
				}
			}
			else btr(i + 1);
			a[j][i] = row[j] = kt1[i - j + 8] = kt2[i + j] = 0;
		}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> b; btr(1);
	return 0;
}
