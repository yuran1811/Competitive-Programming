// https://oj.vnoi.info/problem/rectp
#include <algorithm>
#include <iostream>
#include <vector>
#define sz(s) (int (s.size()))
using namespace std;

typedef long long ll;

const int N = 1e4 + 5;

int n, m, lm;

struct RECT
{
	int l, r, x, c;
	bool operator < (const RECT &a) const {return x < a.x || (x == a.x && c > a.c);}
};
vector <RECT> a, b;

struct SegTree
{
	struct Node {ll val, lz;};
	vector <Node> t;

	void Init(int n) {t.resize(4 * n + 5, {0, 0});}
	void Up(int l, int r, int i, int u, int v, int val)
	{
		if (v < l || r < u) return;
		if (u <= l && r <= v)
		{
			t[i].val += val;
			if (t[i].val > 0) t[i].lz = r - l + 1; else
			t[i].lz = (l < r) ? (t[i << 1].lz + t[i << 1 | 1].lz) : 0;
			return;
		}
		int m = (l + r) >> 1;
		Up(l, m, i << 1, u, v, val);
		Up(m + 1, r, i << 1 | 1, u, v, val);
		if (!t[i].val)
			t[i].lz = t[i << 1].lz + t[i << 1 | 1].lz;
	}
} T;

int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, x1, x2, y1, y2; i <= n; i++)
		cin >> x1 >> y1 >> x2 >> y2, mxm(lm, max(x2, y2)),
		a.push_back({x1 + 1, x2, y1, 1}),
		a.push_back({x1 + 1, x2, y2, -1}),
		b.push_back({y1 + 1, y2, x1, 1}),
		b.push_back({y1 + 1, y2, x2, -1});
	sort(a.begin(), a.end()); m = sz(a);
	sort(b.begin(), b.end());
}

void Calc(vector <RECT> &a, ll &res)
{
	int Prev = 0;
	T.Init(lm);
	for (RECT x : a)
	{
		T.Up(1, lm, 1, x.l, x.r, x.c);
		res += abs(Prev - T.t[1].lz);
		Prev = T.t[1].lz;
	}
}

int Solve()
{
	Load_Data();
	ll res = 0;
	Calc(a, res);
	Calc(b, res);
	cout << res;
	return 0;
}

int main() {Solve();}
