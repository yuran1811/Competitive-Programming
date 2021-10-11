// http://ntucoder.net/Problem/Details/49
#include <iostream>
using namespace std;

int a, b;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b; a ^= b; cout << __builtin_popcount(a);
	return 0;
}
