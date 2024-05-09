// https://oj.vnoi.info/problem/fct003_digitsum
#include <iostream>
#include <cstring>
#define sz(s) (int (s.size()))
using namespace std;

typedef long long ll;

ll f[16][150][10][2], l;
string s, t;

ll DP(const string &s, int i, int sum, int prev, bool IsLess)
{
	if (i >= sz(s)) return sum;
	ll &val = f[i][sum][prev][IsLess];
	if (val != -1) return val;
	val = 0;

	if (IsLess)
	{
		for (int d = 0; d <= 9; d++)
			val += DP(s, i + 1, sum + d, d, IsLess);
		return val;
	}
	int limit = s[i] - '0';
	for (int d = 0; d <= limit; d++)
		val += DP(s, i + 1, sum + d, d, d < limit);
	return val;
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> l >> s; t = to_string(--l);
}

int Solve()
{
	Load_Data();
	memset(f, -1, sizeof f);
	ll res = DP(s, 0, 0, 0, 0);
	memset(f, -1, sizeof f);
	cout << res - DP(t, 0, 0, 0, 0);
	return 0;
}

int main() {Solve();}
