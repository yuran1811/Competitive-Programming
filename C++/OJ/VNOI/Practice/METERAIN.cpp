// https://oj.vnoi.info/problem/meterain
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int n, m;

struct P
{
	long long x, y;
	bool operator <(const P &g) const {return y < g.y || (y == g.y && x < g.x);}
} a[N], b[N];
vector <P> convex_hull, t1, t2;

long long calc(P a, P b) {return a.x * b.y - a.y * b.x;}
long long calcS(P a, P b, P c) {return calc(a, b) + calc(b, c) + calc(c, a);}

bool check(P x, vector <P> a)
{
	for (int i = 0; i < int (a.size()) - 1; i++)
		if (calcS(a[i], x, a[i + 1]) >= 0) return false;
	if (calcS(a[a.size() - 1], x, a[0]) >= 0) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	sort(a + 1, a + 1 + n);

	t1.push_back(a[1]);
	t2.push_back(a[1]);
	for (int i = 2; i <= n; i++)
	{
		while (t1.size() >= 2 && calcS(t1[t1.size() - 2], t1[t1.size() - 1], a[i]) >= 0)
			t1.pop_back();
		t1.push_back(a[i]);
		while (t2.size() >= 2 && calcS(t2[t2.size() - 2], t2[t2.size() - 1], a[i]) <= 0)
			t2.pop_back();
		t2.push_back(a[i]);
	}

	for (P i : t2) convex_hull.push_back(i);
	for (int i = t1.size() - 2; i > 0; i--) convex_hull.push_back(t1[i]);

	cin >> m; 
	for (int i = 1; i <= m; i++) 
	{
		cin >> b[i].x >> b[i].y;
		cout << (check(b[i], convex_hull) ? "YES\n" : "NO\n");
	}
	return 0;
}
