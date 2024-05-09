// http://ntucoder.net/Problem/Details/1172
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, oo = 2e9 + 7;

int n, m, a[N];

struct SegmentTree
{
    int f[4 * N];
    void build(int l, int r, int i)
    {
        if (l == r) return (void) (f[i] = a[l]);
        int m = (l + r) >> 1;
        build(l, m, i * 2);
        build(m + 1, r, i * 2 + 1);
        f[i] = min(f[i * 2], f[i * 2 + 1]);
    }

    int get(int l, int r, int i, int u, int v)
    {
        if (r < u || v < l) return oo;
        if (u <= l && r <= v) return f[i];
        int m = (l + r) >> 1;
        return min(get(l, m, i * 2, u, v), get(m + 1, r, i * 2 + 1, u, v));
    }
} st;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
    st.build(1, n, 1);
    
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        cout << st.get(1, n, 1, u, v) << '\n';
    }
    return 0;
}
