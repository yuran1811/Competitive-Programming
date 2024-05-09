// http://ntucoder.net/Problem/Details/139
#include <bits/stdc++.h>
#define _f(i,ii,iii) for(int i=ii,(_ii)=iii;i<=(_ii);i++)
using namespace std;

const int N=1e3;

int n, cnt=0, t1, t2;
char c[N], c1='(', c2=')';

bool kt()
{
    t1=t2=0;
    if (c[1]==')') return false;
    _f(i,1,n)
    {
        if (c[i]=='(') t1++; else t2++;
        if (t2>t1) return false;
    }
    if (t1==t2) return true; else return false;
}

void prt()
{
    if (kt())
    {
        _f(i,1,n) cout << c[i]; cout << endl;
        cnt++;
    }
}

void btr(int x)
{
    if (x==n+1) prt();
    else
    {
        c[x]=c1; btr(x+1);
        c[x]=c2; btr(x+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; btr(1); cout << cnt;
    return 0;
}
