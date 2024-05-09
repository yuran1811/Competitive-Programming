// http://ntucoder.net/Problem/Details/38
#include <bits/stdc++.h>
using namespace std;
long long n,x,a[100001],i,j,t,m;
int main()
{
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >> x;
        a[x]++;
        m=max(m,x);
    }
    for (i=1;i<=m;i++) if (a[i]>=2) t+=a[i]*(a[i]-1)/2;
    cout << t;
    return 0;
}
