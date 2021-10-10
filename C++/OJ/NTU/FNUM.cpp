// http://ntucoder.net/Problem/Details/4401
#include <bits/stdc++.h>
using namespace std;
unsigned long long i,t;
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getline(cin,s);
    for(i=0;i<s.length();i++)
    {
        t+=s[i]-48;
        while((t/10)!=0)
        {
            t=t%10+t/10;
        }
    }
    cout << t;
    return 0;
}
