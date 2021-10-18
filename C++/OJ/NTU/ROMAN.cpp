// http://ntucoder.net/Problem/Details/3364
#include <iostream>
#include <string>
using namespace std;

string s;
long long d = 0;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i <= s.length() - 1; i++)
    {
        if (s[i] == 'I' && i == s.length() - 1) d++; else
        if (s[i] == 'I' && s[i + 1] != 'I') d--; else
        if (s[i] == 'I') d++;
      
        if (s[i] == 'V') d += 5; else
        if (s[i] == 'C' && (s[i + 1] != 'D' && s[i + 1] != 'M')) d += 100; else
        if (s[i] == 'C' && s[i + 1] == 'D') d -= 100; else
        if (s[i] == 'C' && s[i + 1] == 'M') d -= 100; else
        if (s[i] == 'X' && s[i + 1] != 'L' && s[i + 1] != 'C') d += 10; else
        if (s[i] == 'X') d -= 10; else
        if (s[i] == 'L') d += 50; else
        if (s[i] == 'D') d += 500; else
        if (s[i] == 'M') d += 1000;
    }
    cout << d;
    return 0;
}
