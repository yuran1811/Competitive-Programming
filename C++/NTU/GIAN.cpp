// http://ntucoder.net/Problem/Details/4421
#include<bits/stdc++.h>
using namespace std;
const int N = 105;

int n, m, a[N][N], f[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> a[i][j];
        
    f[0][0] = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            f[i][j] = max(f[i][j], max(f[i - 1][j], f[i][j - 1])) + a[i][j];

    cout << f[n][m];
    return 0;
}
