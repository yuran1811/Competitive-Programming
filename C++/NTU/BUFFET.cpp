// http://ntucoder.net/Problem/Details/5569
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#define fi first
#define se second
#define MASK(x) (1 << (x))
#define sz(s) (int (s.size()))
#define BIT(x, i) (((x) >> (i)) & 1)
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pllll;

vector <pllll> a, b;
ll Max, Min, res;
int n, n1, n2;

bool mxm(ll &a, ll b) {return a < b ? a = b, 1 : 0;}

bool InRange(ll l, ll r, ll val) {return l <= val && val <= r;}

void Load_Data(int n, vector <pllll> &a)
{
	vector <pllll> x(n);
	for (pllll &i : x) cin >> i.fi >> i.se;
	for (int mask = 0; mask < MASK(n); mask++)
	{
		ll w = 0, v = 0;
		for (int i = 0; i < n; i++)
			if (BIT(mask, i)) w += x[i].fi, v += x[i].se;
		if (w > Max) continue;
		a.push_back({w, v});
		if (InRange(Min, Max, w)) mxm(res, v);
	}
}

void FileIO()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> Min >> Max; n1 = n / 2; n2 = n - n1;
	Load_Data(n1, a); sort(a.begin(), a.end(), greater <pllll> ());
	Load_Data(n2, b); sort(b.begin(), b.end());
}

int Scorpio()
{
	FileIO();
	deque <pllll> q;
	int j = 0;
	for (pllll x : a)
	{
		while (j < sz(b) && x.fi + b[j].fi <= Max)
		{
			while (sz(q) && b[j].se >= q.back().se) q.pop_back();
			q.push_back(b[j++]);
		}
		while (sz(q) && !InRange(Min, Max, q.front().fi + x.fi)) q.pop_front();
		if (sz(q)) mxm(res, x.se + q.front().se);
	}
	cout << res;
	return 0;
}

int main() {Scorpio();}
