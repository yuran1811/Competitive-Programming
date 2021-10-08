// https://lqdoj.edu.vn/problem/cjanddenise
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 50;

int n, m;
vector <int> a[N], res;

void dfs(int u)
{
    while (a[u].size())
    {
        int v = *a[u].begin();
        a[u].erase(a[u].begin());
        
        auto pos = find(a[v].begin(), a[v].end(), u);
        a[v].erase(pos);

        dfs(v); 
    }
    res.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1); 
    for (auto x : res) cout << x << " ";
    return 0;
}
