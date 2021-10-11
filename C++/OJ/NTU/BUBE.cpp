// http://ntucoder.net/Problem/Details/48
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, k, a[N];
multiset <int> f;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, greater <int>());
    vector <bool> kt(n + 1, true);

    long long res = 0;
    int i = 1, j = 1;
    while (i <= n && j <= n)
    {
        while (a[i] - k < a[j] && j <= n) j++;
        kt[j] = false;
        i++; j++;
    }
    for (int i = 1; i <= n; i++)
        if (kt[i])
            res += a[i];
    cout << res;
    return 0;
}
