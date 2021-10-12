// https://lqdoj.edu.vn/problem/1920sodep
#include <bits/stdc++.h>
using namespace std;

string s;
int res = 0;

void sol(string t)
{
    for (int i = 0; i < t.size(); i++) 
        res += t[i] - '0';
    if (res < 10) {cout << res; return;}
    while (res > 9)
    {
        int tmp = res; res = 0;
        while (tmp != 0)
        {
            res += tmp % 10;
            tmp /= 10;
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> s; sol(s);
    return 0;
}
