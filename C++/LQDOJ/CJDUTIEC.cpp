// https://lqdoj.edu.vn/problem/cjdutiec
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const long long oo = 1e17 + 90;

typedef pair <long long, int> pii;

int n, m, s, t, trace[N];
vector <pair <int, int>> a[N];
vector <int> res;

void dijk(int s)
{
    priority_queue <pii, vector <pii>, greater <pii>> q;
    vector <long long> d(N, oo);
    d[s] = 0;
    q.push({0, s});
    while (q.size())
    {
        int u = q.top().second;
        long long du = q.top().first; 
        q.pop();
        if (du > d[u]) continue;

        for (auto v : a[u])
            if (d[v.first] > d[u] + v.second)
            {
                d[v.first] = d[u] + v.second;
                trace[v.first] = u;
                q.push({d[v.first], v.first});
            }
    }
    cout << d[t] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    dijk(s);
    do
    {
        res.push_back(t);
        t = trace[t];
    } while (t != s);
    res.push_back(s);
    reverse(res.begin(), res.end());
    for (auto x : res)
        cout << x << " ";
    return 0;
}
