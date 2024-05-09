// http://ntucoder.net/Problem/Details/4398
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, res = 0, a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    	cin >> a[i];
   	sort(a + 1, a + 1 + n);

   	int i = 1;
   	while (res < n - 1)
   	{
   	    while (a[i] >= 1)
        {
        	a[i]--;
        	res++;
        	if (res >= n - 1) 
        		break;
        }
        i++; n--;
   	}
   	cout << res;
    return 0;
}
