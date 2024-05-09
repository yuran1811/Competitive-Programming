// http://ntucoder.net/Problem/Details/51
#include <bits/stdc++.h>
#define _f(i,ii,iii) for(int i=ii,(_ii)=iii;i<=(_ii);i++)
using namespace std;
const int N=1e2+3;

int n, m, x, y, u, v, cnt=1;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char c[N][N];

void btr(int xx, int yy)
{
    _f(i,0,3)
    {
        u=xx+dx[i];
        v=yy+dy[i];
        if (c[u][v]=='0' && u>0 && v>0 && u<=n && v<=m)
        {
            cnt++;
            c[u][v]='1';
            btr(u,v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y; _f(i,1,n) _f(j,1,m) cin >> c[i][j];
    c[x][y]='1'; btr(x,y); cout << cnt;
    return 0;
}
