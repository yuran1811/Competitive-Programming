// http://ntucoder.net/Problem/Details/119
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e2 + 5;

int n, m, a[N][N], res = 0;
vector <int> Item[N];

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1, x; j <= m; j++)
		{
			cin >> x;
			if (!x) continue;
			Item[j].push_back(i);
		}
	for (int i = 1; i <= m; i++)
		sort(Item[i].begin(), Item[i].end(), greater <int> ());
}

int Scorpio()
{
	Load_Data();
	for (int i = 1; i <= m; i++)
	{
		int num = 0;
		for (int j : Item[i])
			res += n - j - num, num++;
	}
	cout << res;
	return 0;
}

int main() {Scorpio();}
