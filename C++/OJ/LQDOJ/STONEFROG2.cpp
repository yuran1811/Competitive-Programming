// https://lqdoj.edu.vn/problem/stonefrog2
#include <bits/stdc++.h>
#define waitt first
#define cost second
using namespace std;
const int N = 1e5 + 5;

int n, k;
long long a[N], f[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k; for (int i = 1; i <= n; i++) cin >> a[i];

    f[0] = f[1] = 0;
    f[2] = abs(a[2] - a[1]);
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + abs(a[i - 1] - a[i]);
        for (int j = 2; j <= k; j++)
            if (i - j > 0)
                f[i] = min(f[i], f[i - j] + abs(a[i - j] - a[i]));
    }
    cout << f[n];
    return 0;
}
