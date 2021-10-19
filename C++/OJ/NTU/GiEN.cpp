// http://ntucoder.net/Problem/Details/42
#include<bits/stdc++.h>
using namespace std;

int n;
string s1, s2;
set <string> res;

void sol(int i, string s)
{
    if (i==n)
    {
        res.insert(s);
        return;
    } 
    sol(i + 1, s + s1[i]);
    sol(i + 1, s + s2[i]);   
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s1 >> s2;
    string s;
    sol(0, s);
    cout << res.size() << '\n';
    for (auto x: res)
        cout << x << '\n';
    return 0;
}
