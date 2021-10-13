// http://ntucoder.net/Problem/Details/3388
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, l, r, MINUS[N], ZERO[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if (x == 0) ZERO[i]++; else 
        if (x < 0) MINUS[i]++;
    }
    for (int i = 1; i <= n; i++)
        ZERO[i] += ZERO[i - 1],
        MINUS[i] += MINUS[i - 1];
    while (m--)
    {
        cin >> l >> r;
        int x = ZERO[r] - ZERO[l - 1];
        if (x) cout << 0 << '\n'; else 
        {
            x = MINUS[r] - MINUS[l - 1];
            if (x & 1) cout << "-\n";
            else cout << "+\n";
        }
    }
    return 0;
}
