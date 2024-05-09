// https://lqdoj.edu.vn/problem/cjxaydung
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5, oo = 1e9 + 7;

set <int> f;
int n, m, edge = 0;
vector <int> tmp, res;
vector <pair <int, int>> a[N];

vector <bool> node(N, false);
int cnt = 0, Low[N], Num[N];
stack <int> s;

void tj(int u, int par)
{
    int child = 0;
    Low[u] = Num[u] = ++cnt;
    s.push(u);

    for (auto v : a[u])
        if (v.fi != par)
        {
            if (Num[v.fi] == 0)
            {
                tj(v.fi, u); child++;
                Low[u] = min(Low[u], Low[v.fi]);

                if (Low[v.fi] >= Num[v.fi])
                {
                    edge++;
                    int V;
                    do
                    {
                        V = s.top(); s.pop();
                        tmp.push_back(V);
                    } while (V != v.fi);
                }
            } else
                Low[u] = min(Low[u], Num[v.fi]);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back({v, i});
        a[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++)
        if (Num[i] == 0)
            tj(i, i);

    cout << edge << '\n';
    for (auto x : tmp)
        for (auto y : a[x])
            f.insert(y.se);
    for (auto x : f) cout << x << " ";
    return 0;
}
