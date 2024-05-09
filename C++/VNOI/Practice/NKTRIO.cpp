// https://oj.vnoi.info/problem/nktrio
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

int n, f[N][N], trace[N], cnt = 0;
vector <int> a[N], kt(N + 1, 0), res;

void dfs(int u)
{
    //kt[u] = 1;
    for (int v : a[u])
        if (kt[v] == 0)
        {
            trace[v] = u;
            kt[v] = 1;
            dfs(v);
        } else
        //if (kt[v] == 1)
        {
            //if (f[u][v] != 1) continue;
            /*vector <int> cycle;
            for (int i = u; i != v; i = trace[i])
                cycle.push_back(i);

            if (cycle.size() == 3)
            {
                for (int x : cycle) cout << x << " ";
                exit(0);
            }
            return;*/
            if (trace[u] > 0 && f[v][trace[u]] == 1)
            {
                cout << u << " " << v << " " << trace[u];
                exit(0);
            }
        }
    //kt[u] = 2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> f[i][j];
            if (f[i][j] == 1) a[i].push_back(j);
        }

    for (int i = 1; i <= n; i++)
        if (kt[i] == 0)
        {
            trace[i] = -1;
            dfs(i);
        }

    cout << "-1 -1 -1";
    return 0;
}
