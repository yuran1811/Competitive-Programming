// http://ntucoder.net/Problem/Details/3382
#include <iostream>
using namespace std;

const int N = 1e6 + 5;

long long n, q, x, y, a[N], f[N];
char c;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q; 
    for (int i = 1; i <= n; i++) {cin >> a[i]; f[i] += f[i - 1] + a[i];}
    while (q--)
    {
        cin >> c >> x >> y;
        if (c == 'S') cout << f[y + 1] - f[x] << '\n'; else
        if (c == 'U') 
            for (int i = x + 1; i <= n; i++) f[i] += y; else 
            for (int i = x + 1; i <= n; i++) f[i] -= y;
    }
    return 0;
}
