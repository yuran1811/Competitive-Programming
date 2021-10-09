// https://lqdoj.edu.vn/problem/fgird
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 50, oo = 1e6 + 3;

pair <int, int> dir[2] = {{1, 0}, {0, 1}};
int n, cnt = 1, f[N][N]; 
string s; char c[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    cin >> s;
    if(s[0] == c[1][1]) f[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int d = 0; d < 2; d++)
            {
                int u = i + dir[d].fi;
                int v = j + dir[d].se;
                if (u <= 0 || u > n || v <= 0 || v > n) continue;
                if (s[u + v - 2] == c[u][v])
                    (f[u][v] += f[i][j]) %= oo;
            }   
        }
    }
    cout << f[n][n];
    return 0;
}
