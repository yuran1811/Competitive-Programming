// https://oj.vnoi.info/problem/vomovrec
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;

struct E {long long x, y, _x, _y;} a[N], b[N];
int n;

bool kt(E t)
{
    if (t.x >= t._x) return false;
    if (t.y >= t._y) return false;
    return true;
}

bool check(long long t)
{
    for (int i = 1; i <= n; i++)
    {
        b[i].x  = a[i].x - t;  b[i].y  = a[i].y - t;
        b[i]._x = a[i]._x + t; b[i]._y = a[i]._y + t;
    }

    E k;
    k.x  = max(b[1].x,  b[2].x);
    k.y  = max(b[1].y,  b[2].y);
    k._x = min(b[1]._x, b[2]._x);
    k._y = min(b[1]._y, b[2]._y);
    if (!kt(k)) return false;

    for (int i = 3; i <= n; i++)
    {
        k.x = max(k.x, b[i].x);
        k.y = max(k.y, b[i].y);
        k._x = min(k._x, b[i]._x);
        k._y = min(k._y, b[i]._y);
        if (!kt(k)) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i]._x >> a[i]._y;

    long long l = 1, r = 2e9;
    while (l < r)
    {
        long long mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else            l = mid + 1;
    }
    cout << r;
    return 0;
}
