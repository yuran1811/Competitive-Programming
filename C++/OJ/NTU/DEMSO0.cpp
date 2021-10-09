// http://ntucoder.net/Problem/Details/3330
#include <iostream>
using namespace std;

long long n, s;

int main()
{ 
    cin >> n;
    while (n > 0)
        s += n / 5, n /= 5;
    cout << s;
    return 0;
}
