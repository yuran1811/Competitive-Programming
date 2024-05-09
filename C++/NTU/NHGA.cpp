// http://ntucoder.net/Problem/Details/39
#include <bits/stdc++.h>
using namespace std;
long int n,i,a[100001],m;
int main()
{
    cin >> n;
    for(i=0;i<=n-1;i++) cin >> a[i];
    sort(a,a+n);m=a[1]-a[0];
    for(i=2;i<=n-1;i++) m=min(m,a[i]-a[i-1]);
    cout << m;
    return 0;
}
