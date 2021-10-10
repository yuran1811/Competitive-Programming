// http://ntucoder.net/Problem/Details/4419
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i>=c;i--)
using namespace std;
int test,n;
int main()
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        f(i,trunc(sqrt(n)),1)
        	if (n%(i*i)==0)
            {
                cout << i << " " << n/(i*i) << '\n'; break;
            }
    }
    return 0;
}
