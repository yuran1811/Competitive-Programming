// http://ntucoder.net/Problem/Details/4425
#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    cout << (n/2 + n%2) * (m/2 + m%2);
    return 0;
}
