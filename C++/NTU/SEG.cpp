// http://ntucoder.net/Problem/Details/3369
#include <bits/stdc++.h>
using namespace std;

const int N = 1500;

int n, a[N], s[N];

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i],
		s[i] += s[i - 1] + a[i];
}

int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}

int Solve()
{
	Load_Data();
	int res = 0;
	for (int i = 1; i < n; i++)
	{
		int Max = s[n] / s[i], cnt = 2, pow = 2;
		for (int j = i + 1; j < n; j++)
			if (s[j] == s[i] * pow)
				pow++, cnt++;
		if (cnt == Max) mxm(res, Max);
	}
	cout << res;
	return 0;
}

int main() {Solve();}
