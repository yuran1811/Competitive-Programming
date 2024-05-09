// https://oj.vnoi.info/problem/power
#include <bits/stdc++.h>
using namespace std;

long long t, a, b;

int bs(long long l, long long r)
{
    int tmp = 0;
    for (int i = 39; i > 0; i--)
    {
        double a = pow(l, 1.0 / i), b = pow(r, 1.0 / i);
        for (int j = a - 1; j <= b + 1; j++)
        {
            if ((long long) pow(j, i) >= l && (long long) pow(j, i) <= r)
            {
                tmp = i;
                break;
            }
        }
        if (tmp != 0) break;
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int id = 1; id <= t; id++)
    {
        cin >> a >> b;
        int res = bs(a, b);
        cout << "Case #" << id << ": " << res << endl;
    }
    return 0;
}
