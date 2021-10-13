// https://oj.vnoi.info/problem/fmatch
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 50, oo = 2e9 + 7;

int n, m, p, matched = 0;
vector <int> a[N], mx(N, 0), my(N, 0), d(N);

bool bfs()
{
    queue <int> q; 
    for (int u = 1; u <= n; u++)
        if (!mx[u])
        {
            d[u] = 0;
            q.push(u);
        } else d[u] = oo;

    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : a[u])
            if (!my[v]) return true; else 
            if (d[my[v]] == oo)
            {
                d[my[v]] = d[u] + 1;
                q.push(my[v]);
            }
    }
    return false;
}

bool dfs(int u)
{
    if (d[u] == oo) return false;
    for (int v : a[u])
        if (!my[v] || (d[my[v]] == d[u] + 1 && dfs(my[v])))
        {
            mx[u] = v;
            my[v] = u;
            return true;
        }
    return false;
}

void match()
{
    while (bfs())
    {
        for (int u = 1; u <= n; u++)
            if (!mx[u])
                matched += dfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> p; 
    for (int i = 1, u, v; i <= p; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
    }
    match();
    cout << matched;
    return 0;
}
