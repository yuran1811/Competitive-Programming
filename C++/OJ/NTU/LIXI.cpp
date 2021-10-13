// http://ntucoder.net/Problem/Details/2252
#include<bits/stdc++.h>
#define num first
#define price second
using namespace std;
const int N = 1e5 + 2;

int n, res, tmp;
pair <int, int> a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    for (int i = 1; i <= n; i++)
        cin >> a[i].price >> a[i].num;
    sort(a + 1, a + 1 + n);
    res = a[n].price;
    tmp = a[n].num;
    if (tmp == 0) {cout << res; return 0;}
    for (int i = n - 1; i > 0; i--)
    {
        if (tmp > 0) 
        {
            res += a[i].price;
            tmp += a[i].num;
            tmp--; 
        } else break;
    }
    cout << res;
    return 0;
}
