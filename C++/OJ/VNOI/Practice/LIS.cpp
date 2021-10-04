// https://oj.vnoi.info/problem/lis
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector <int> a, b;
int n;

bool mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}

void Compress()
{
	b = a; sort(b.begin(), b.end());
	for (int &x : a)
		x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}

struct BIT
{
	vector <int> bit;
	void Init(int n) {bit.assign(n + 1, 0);}
	void Up(int i, int val) {for (; i <= n; i += -i & i) mxm(bit[i], val);}
	int Get(int i, int res = 0)
	{
		for (; i > 0; i -= -i & i)
			mxm(res, bit[i]);
		return res;
	}
} T;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; a.resize(n); for (int &x : a) cin >> x;
	Compress(); T.Init(n);
	
	for (int i : a) T.Up(i, T.Get(i - 1) + 1);
	cout << T.Get(n);
	return 0;
}
