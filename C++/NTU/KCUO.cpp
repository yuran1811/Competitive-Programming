// http://ntucoder.net/Problem/Details/29
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i<=c;i++)
using namespace std;
int n,k=1,d;
string b[101];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n; f(i,1,n) b[n/2+1]+='D';
    f(i,1,n/2)
    {
    	d=n-k;
    	f(j,1,n)
	    	if (d/2<j && j<=d/2+k)
	    	{
	    		b[i]+='D'; b[n-i+1]+='D';
	    	}
    		else 
    		{
	    		b[i]+='*'; b[n-i+1]+='*';
	    	}
    	k+=2; 	
    }
    f(i,1,n) cout << b[i] << endl;
    return 0;
}
