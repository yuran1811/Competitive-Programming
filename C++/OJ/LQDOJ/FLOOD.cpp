// https://lqdoj.edu.vn/problem/flood
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5, oo = 2e9 + 7;

typedef pair <int, int> pii;

pii dir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int n, m, k, res, f[N][N], b[N][N], rav[N][N];
queue <pii> ravine;
pii farm, shop;

void bfs()
{
    rav[farm.fi][farm.se] = rav[shop.fi][shop.se] = oo;
    while (ravine.size())
    {
        int u = ravine.front().fi, v = ravine.front().se;
        ravine.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = u + dir[i].fi, y = v + dir[i].se;
            if (x > 0 && y > 0 && x <= n && y <= m && rav[x][y] == 0)
            {
                rav[x][y] = rav[u][v] + 1;
                ravine.push({x, y});
            }
        }
    }
}

bool kt(int x)
{
    memset(f, oo, sizeof f);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = (rav[i][j] > x ? 0 : 1);

    deque <pii> q;
    q.push_front(farm);
    f[farm.fi][farm.se] = 0;

    while (q.size())
    {
        pii u = q.front(); q.pop_front();
        int fu = f[u.fi][u.se];

        for (int i = 0; i < 4; i++)
        {
            pii v = {u.fi + dir[i].fi, u.se + dir[i].se};
            if (v.fi > 0 && v.se > 0 && v.fi <= n && v.se <= m)
            {
                if (f[v.fi][v.se] > fu + b[v.fi][v.se])
                {
                    f[v.fi][v.se] = fu + b[v.fi][v.se];
                    if (b[v.fi][v.se] == 1) q.push_back(v);
                    else                    q.push_front(v);
                }
            }
        }
    }
    return f[shop.fi][shop.se] <= k;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("FLOOD.INP","r",stdin); freopen("FLOOD.OUT","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++)
    	{
            char c;
    		cin >> c;
    		if (c == 'H') farm = {i, j};
    		if (c == 'G') shop = {i, j};
    		if (c == 'S') ravine.push({i, j});
    	}
    bfs();    
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (!kt(mid)) r = mid - 1;
        else          l = mid;
    }
    cout << (l == 1e9 ? - 1 : l + 1);
    return 0;
}
