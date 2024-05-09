// http://ntucoder.net/Problem/Details/67
#include <iostream>
using namespace std;
long long n,m,t,s,d,i;
int main()
{
    cin >> m >> n >> t;
    while (d<n)
    {
        d++;i++;
        if (i==m){d++;i=0;}
        s+=t;
    }
    cout << s;
    return 0;
}
