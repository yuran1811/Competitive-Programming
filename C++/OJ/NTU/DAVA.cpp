// http://ntucoder.net/Problem/Details/76
#include <bits/stdc++.h>
using namespace std;

long long n,k,i,j,a[1001][1001],b[1001][1001],t,m;

int main()
{
    cin >> n >> k;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            cin >> a[i][j];
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
        }
    for (i=1;i<=n-k+1;i++)
        for (j=1;j<=n-k+1;j++)
        {
            t=b[i+k-1][j+k-1]-b[i-1][j+k-1]-b[i+k-1][j-1]+b[i-1][j-1];
            m=max(m,t);
        }
    cout << m;
    return 0;
}
