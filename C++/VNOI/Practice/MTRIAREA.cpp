// https://oj.vnoi.info/problem/mtriarea
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

long long n, res = 0;

struct P
{
	long long x, y;
	bool operator <(const P &g) const {return x < g.x || (x == g.x && y < g.y);}
} a[N];
vector <P> s, _s, f;

long long calc(P a, P b) {return (a.x * b.y - a.y * b.x);}
long long calcS(P a, P b, P c) {return calc(a, b) + calc(b, c) + calc(c, a);}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; 
	while (n != -1)
	{
		for (int i = 1; i <= n; i++) 
			cin >> a[i].x >> a[i].y;
		if (n < 3) {cout << "0\n"; cin >> n; continue;}
		sort(a + 1, a + 1 + n);

		s.clear(); _s.clear(); f.clear();
		s.push_back(a[1]);
		_s.push_back(a[1]);
	
		for (int i = 2; i <= n; i++)
		{
			while (s.size() >= 2 && calcS(s[s.size() - 2], s[s.size() - 1], a[i]) >= 0) s.pop_back();
			while (_s.size() >= 2 && calcS(_s[_s.size() - 2], _s[_s.size() - 1], a[i]) <= 0) _s.pop_back();
			s.push_back(a[i]);
			_s.push_back(a[i]);
		}
		
		for (P i : _s) f.push_back(i);
		for (int i = s.size() - 2; i > 0; i--) f.push_back(s[i]);
		
		res = 0;
		int m = f.size(), i = 1, r = 2;
		for (int l = 0; l < m; l++)
		{
			while (1)
			{
				while (l != r + 1 && abs(calcS(f[l], f[i], f[r])) < abs(calcS(f[l], f[i], f[(r + 1) % m]))) r = (r + 1) % m;
				if (abs(calcS(f[l], f[i], f[r])) < abs(calcS(f[l], f[(i + 1) % m], f[r]))) i = (i + 1) % m;
				else break;
			}
			res = max(res, abs(calcS(f[l], f[i], f[r])));
		}
		cout << res / 2 << (res % 2 ? ".5\n" : ".0\n");
		cin >> n;
	}
	return 0;
}
