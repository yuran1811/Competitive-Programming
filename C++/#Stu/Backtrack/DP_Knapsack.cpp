#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;

int n, m, w[N], v[N], f[N][N];

int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= w[i]) mxm(f[i][j], f[i - 1][j - w[i]] + v[i]);
        }
    cout << f[n][m] << endl;
    while (n)
    {
        if (f[n][m] != f[n - 1][m])
        {
            cout << n << " ";
            m -= w[n];
        }
        n--;
    }
    return 0;
}
