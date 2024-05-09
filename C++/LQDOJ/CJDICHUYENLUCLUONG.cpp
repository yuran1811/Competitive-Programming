// https://lqdoj.edu.vn/problem/cjdichuyenlucluong
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const long long oo = 1e17 + 90;

typedef pair <long long, int> pii;

int n, m, s, t, trace[N];
vector <pair <int, long long>> a[N];

struct E
{
    int u, v, w;
    bool operator <(const E &x) const {return w > x.w;}
} g[N];

int f[N];
void init(int n)      {for (int i = 1; i <= n; i++) f[i] = i;}
int  rt(int u)        {return f[u] == u ? u : f[u] = rt(f[u]);}
bool kt(int u, int v) {return rt(u) == rt(v);}
void mer(int u, int v)
{
    if (kt(u, v)) return;
    u = rt(u), v = rt(v);
    f[v] = u;
}

void dijk(int s, int t)
{
    priority_queue <pii> q; q.push({oo + 1, s});
    vector <long long> d(N, -1); d[s] = oo;

    while (q.size())
    {
        int u = q.top().second;
        long long du = q.top().first;
        q.pop();
        if (du < d[u]) continue;
        if (u == t) break;

        for (auto v : a[u])
            if (d[v.first] < min(du, v.second))
            {
                d[v.first] = min(du, v.second);
                trace[v.first] = u;
                q.push({d[v.first], v.first});
            }
    }

    cout << d[t] << '\n';
    vector <int> res;
    do
    {
        res.push_back(t);
        t = trace[t];
    } while (t != s);
    res.push_back(s);
    reverse(res.begin(), res.end());
    for (int x : res) cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t; 
    for (int i = 1; i <= m; i++) cin >> g[i].u >> g[i].v >> g[i].w;
    sort(g + 1, g + 1 + m);
    init(n);

    for (int i = 1; i <= m; i++)
    {
        if (kt(s, t)) break;
        if (!kt(g[i].u, g[i].v))
        {
            a[g[i].u].push_back({g[i].v, g[i].w});
            a[g[i].v].push_back({g[i].u, g[i].w});
            mer(g[i].u, g[i].v);
        }
    }

    dijk(s, t);
    return 0;
}
