// http://ntucoder.net/Problem/Details/5538
#include <bits/stdc++.h>
#define _U first
#define _V second
using namespace std;
const int N = 1e5 + 5, oo = 1e9 + 7;

typedef pair <int, int> pii;
int m, n, s, t, f[N];
vector <pii> a[N];

void sol(int n, int s, int t) 
{
    priority_queue <pii> q;
    q.push({0, s});
    memset(f, 0x3f, sizeof f);
    f[s] = 0;
    while (q.size()) 
    {
        pii u = q.top(); q.pop();

        if (f[u._V] > u._U) continue;
        if (u._V == t) break;

        for (pii v : a[u._V]) 
        {
            if (f[v._U] > oo || f[v._U] < min(u._U, v._V)) 
            {
                f[v._U] = (u._U == 0 ? v._V : min(u._U, v._V));
                q.push({f[v._U], v._U});
            } 
        }
    }
    cout << (f[t] < oo ? f[t] : -1);
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
    sol(n, s, t);
    return 0;
}
