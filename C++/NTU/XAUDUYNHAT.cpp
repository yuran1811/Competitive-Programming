// http://ntucoder.net/Problem/Details/5573
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i<=c;i++)
using namespace std;
int ans=1,cnt,r; string s;
vector <bool> a(121,0);
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	getline(cin,s);
	f(i,0,s.size()-1)
	{
		cnt=0; r=i;
		while (!a[s[r]] && r<s.size())
        {
            cnt++; a[s[r]]=1; r++;
        }
        ans=max(ans,cnt);
        f(j,i,r) a[s[j]]=0;
	}
	cout << ans;
    return 0;
}
