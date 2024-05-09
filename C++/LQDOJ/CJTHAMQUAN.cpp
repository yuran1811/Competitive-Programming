// 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m;
long long res = 0;
long long rs = 0;
vector <int> a[N];
bool ok[N];
long long w[N];
int print[N], tmp[N];

void DFS(int u, int cnt)
{
    tmp[cnt] = u;
    if (cnt == 4)
    {
        if (res > rs)
        {
            rs = res;
            for (int i = 1; i <= 4; i++)
              print[i] = tmp[i];
        }
        return;
    }
  
    for (int v: a[u])
    {
        if (!ok[v])
        {
            ok[v] = 1;
            res += w[v];
            DFS(v, cnt + 1);
            res -= w[v];
            ok[v] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1, u, v; i <= m; i++)
        cin >> u >> v,
        a[u].push_back(v),
        a[v].push_back(u);
  
    for (int i = 1; i <= n; i++)
    {
        ok[i] = 1;
        res = w[i];
        DFS(i, 1);
        ok[i] = 0;
    }
    cout << rs << '\n';
    return 0;
}
