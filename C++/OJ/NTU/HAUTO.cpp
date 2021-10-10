// http://ntucoder.net/Problem/Details/1157
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i<=c;i++)
using namespace std;
stack <int>  stknum;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); int t,tmp; string s; getline(cin,s);
    f(i,0,s.size())
    {
        int _tmp = 0;
        bool kt = 0;
        while (s[i]>='0' && s[i]<='9')
        {
               _tmp = _tmp*10 + s[i] - '0';
               i++; kt = 1;
        }
        if (kt) {stknum.push(_tmp); kt=0;}
        {
            if (s[i]=='+')
            {
                tmp = stknum.top(); stknum.pop();
                t = stknum.top() + tmp;
                stknum.pop();
                stknum.push(t);
            }
            if (s[i]=='-')
            {
                tmp = stknum.top(); stknum.pop();
                t = stknum.top() - tmp;
                stknum.pop();
                stknum.push(t);
            }
            if (s[i]=='*')
            {
                tmp = stknum.top(); stknum.pop();
                t = stknum.top() * tmp;
                stknum.pop();
                stknum.push(t);
            }
        }
    }
    cout << stknum.top();
    return 0;
}
