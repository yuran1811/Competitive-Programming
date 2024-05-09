// http://ntucoder.net/Problem/Details/1146
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

vector <int> a, b;
ll n, res = 0;

void compress()
{
    b = a; sort(b.begin(), b.end());
    for (int &x : a)
        x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}

struct FW
{
   vector <ll> bit;
   void init(int n) {bit.assign(n + 1, 0);}
   void up(int i) {while (i <= n) bit[i]++, i += -i & i;}
   ll get(int i) {ll res = 0; while (i > 0) res += bit[i], i -= -i & i; return res;}
} T;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; a.resize(n, 0); for (int &x : a) cin >> x;
    compress(); T.init(n);
    for (int x : a) 
      res += T.get(n) - T.get(x), 
      T.up(x);
    cout << res;
    return 0;
}
