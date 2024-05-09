// http://ntucoder.net/Problem/Details/52
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 25;

pair <int, int> x, path[N][N], dir[] = {{1, 0}, {0, 1}};
vector <pair <int, int>> res;
int n, m, a[N][N];
bool kt[N][N];
set <int> s;

void prt()
{
	path[1][1] = {-1, -1};
	x = {n, m};
	do 
	{
		res.push_back(x);
		x = path[x.fi][x.se];
	} while (x.fi != -1 || x.se != -1);
	reverse(res.begin(), res.end());
	for (auto i : res) cout << i.fi << " " << i.se << '\n';
	exit(0);
}

bool good(int x, int y) {return (1 <= x && x <= n && 1 <= y && y <= m && !kt[x][y] && a[x][y] != -1);}

void btr(int x, int y)
{
	if (x == n && y == m)
	{
		if (s.size() >= 2) prt();
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		int u = x + dir[i].fi;
		int v = y + dir[i].se;
		if (good(u, v))
		{
			kt[u][v] = 1;
			if (a[u][v] != 0) s.insert(a[u][v]);
			path[u][v] = {x, y};
			btr(u, v);
			s.erase(a[u][v]);
			kt[u][v] = 0;
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= m; j++)
	    	cin >> a[i][j];
	btr(1, 1);
	cout << -1;
    return 0;
}
