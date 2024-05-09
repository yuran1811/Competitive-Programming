// http://ntucoder.net/Problem/Details/3262
#include <bits/stdc++.h>
using namespace std;
int n,m,q,l,r,t,i,x;
int a[1000005],b[1000005],c[1000005],v[1000005],u[1000005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (i=1;i<=m;i++)
    {
        cin >> l >> r;
        b[l]+=1; b[r+1]+=-1;
    }
    for (i=1;i<=n;i++)
    {
        c[i]=c[i-1]+b[i]; a[i]+=c[i]; v[a[i]]++;
    }
    for (i=n-1;i>=1;i--)
    {
        v[i]+=v[i+1];
    }
    cin >> q;
    for (i=1;i<=q;i++) cin >> u[i];
    for (i=1;i<=q;i++)
    {
        cout << v[u[i]] << "\n";
    }
    return 0;
}
