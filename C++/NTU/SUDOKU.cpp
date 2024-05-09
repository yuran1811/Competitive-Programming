// http://ntucoder.net/Problem/Details/3261
#include<bits/stdc++.h>
using namespace std;
const int N = 10;

int  a[N][N];

void prt()
{
    for (int i = 0; i < 9; i++, cout << endl)
    for (int j = 0; j < 9; j++)
        cout << a[i][j] << " ";
}

bool kt(int x, int y, int k)
{
    for (int i = 0; i < 9; i++)
        if (a[x][i] == k || a[i][y] == k)  
            return false;

    for (int i = x / 3 * 3; i <= x / 3 * 3 + 2; i++)
        for (int j = y / 3 * 3; j <= y / 3 * 3 + 2; j++)
            if (a[i][j] == k)
                return false;
    return true;
}

void sol(int x, int y)
{
    if (y == 9)
    {
        if (x == 8) {prt(); exit(0);} 
        else sol(x + 1, 0);
    } else 
    if(a[x][y] == 0)
    {
        for (int k = 1; k <= 9; k++)
            if (kt(x, y, k))
            {
                a[x][y] = k;
                sol(x, y + 1);
                a[x][y] = 0;
            }
    } else sol(x, y + 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
        cin >> a[i][j];
    sol(0, 0);
    cout << -1;
    return 0;
}
