// https://lqdoj.edu.vn/problem/divisor
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, cnt = 0, res = 0;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == sqrt(n))
            {
                cnt++;
                res += i;
            } else 
            {
                cnt += 2;
                res += i + n / i;
            }
        }
    }
    cout << cnt << " " << res;
    return 0;   
}
