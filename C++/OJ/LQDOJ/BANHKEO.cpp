// https://lqdoj.edu.vn/problem/banhkeo
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;

int n, m, k, cnt, p, minn = 1e9 + 7;
vector <pair <int, int>> a[N];
vector <bool> kt(N, true);

void dfs(int u)
{
    for (auto v: a[u])
        if (kt[v.fi] && v.se >= minn)
        {
            kt[v.fi] = false;
            dfs(v.fi);
        } 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("BANHKEO.INP","r",stdin); freopen("BANHKEO.OUT","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) 
    {
        cin >> p; minn = min(minn, p);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++)
        if (kt[i])
        {
            cnt++;
            dfs(i);
        }
    cout << cnt;
    return 0;
}
